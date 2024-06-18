#include<iostream>
#include<queue>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildBST(Node* root, int data){
    if(root == NULL){
        Node* temp = new Node(data);
        return temp;
    }

    if(data > root->data){
        root->right = buildBST(root->right,data);
    }
    else{
        root->left = buildBST(root->left,data);
    }
    return root;
}

void createBST(Node*& root){
    int data;
    cout << "Enter the value for Root Node" << endl;
    cin>>data;

    while(data != -1){
        root = buildBST(root,data);
        cout << "Enter the data for node " << endl;
        cin>>data;
    }
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void lvlOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left != NULL)
            q.push(front->left);

            if(front->right != NULL)
            q.push(front->right);

        }
    }

}

int main(){
    Node* root = NULL;
    createBST(root);

    cout << "Printing PreOrder " << endl;
    preOrder(root);
    cout << endl;
    
    cout << "Printing Inorder " << endl;
    inOrder(root);
    cout << endl;

    cout << "Printing PostOrder " << endl;
    postOrder(root);
    cout << endl;

    cout << "Printing Level Order " << endl;
    lvlOrderTraversal(root);
}
