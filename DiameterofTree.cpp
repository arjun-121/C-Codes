#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        // constructor
    public:
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
// create tree function
Node* CreateTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }

    Node* head = new Node(x);
    head->left = CreateTree();
    head->right = CreateTree();

    return head;

}
//height
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls,rs) +1;
}
// diameter of tree  O(n^2) approach
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1+h2 + 1;
    int op2 = diameter(root->left);
    int op3  = diameter(root->right);

    return max(op1,max(op2,op3));

}
// diameter of a tree optimised approach
class Pair{
  public:
    int height;
    int diameter;
};

Pair fastDiameter(Node* root){
    Pair p;
    if(root == NULL){
         p.diameter = p.height =0;
         return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    p.height = max(left.height,right.height) + 1;
    p.diameter = max((left.height+right.height),max(left.diameter,right.diameter)) + 1;

    return p;
}


int main() {
	Node* head = CreateTree();
	Pair p = fastDiameter(head);
	cout<<p.diameter<<"\n";
	return 0;
}
