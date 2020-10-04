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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls,rs) +1;
}

// print kth level
void printKthlevel(Node* root,int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthlevel(root->left,k-1);
    printKthlevel(root->right,k-1);

    return ;
}


// print nodes in different lines
void printLevelInLines(Node* root){
    if(root == NULL){
        return ;
    }
    int k  = height(root);
    for(int i=1;i<=k;i++){
        printKthlevel(root,i);
        cout<<"\n";
    }
    return ;

}


int main() {
	Node* head = CreateTree();
	printLevelInLines(head);
	return 0;
}
