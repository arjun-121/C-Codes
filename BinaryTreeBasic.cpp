#include <iostream>
#include<queue>
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
// preorder traversal
void  PreOrder(Node* head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<"  ";
    PreOrder(head->left);
    PreOrder(head->right);

    return;

}
// inorder traversal
void  InOrder(Node* head){
    if(head == NULL){
        return;
    }

    InOrder(head->left);
    cout<<head->data<<"  ";
    InOrder(head->right);

    return;
}
// post order traversal
void  PostOrder(Node* head){
    if(head == NULL){
        return;
    }

    PostOrder(head->left);
    PostOrder(head->right);
    cout<<head->data<<"  ";
    return;
}
// level order traversal in one line
void LevelOrder(Node* head){
    queue<Node*> q;
    q.push(head);

    while(!q.empty()){
        Node* curr  = q.front();
        q.pop();
        cout<<curr -> data<<" ";
        if(curr->left)
             q.push(curr -> left);

         if(curr->right)
            q.push(curr->right);
    }

    return;
}




// main function
int main() {

    Node* head = CreateTree();
     PreOrder(head);
     cout<<"\n";
     InOrder(head);
     cout<<"\n";
     PostOrder(head);

    LevelOrder(head);

return 0;
}
