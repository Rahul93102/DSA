#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertion(Node*& root, int d) {
    if (root == nullptr) {
        root = new Node(d);
        return root;
    }
    if (d < root->data) {
        root->left = insertion(root->left, d);
    } else {
        root->right = insertion(root->right, d);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void takeinput(Node*& root) {
    int n;
    cout << "Enter Data: " << endl;
    cin >> n;

    while (n != -1) {
        root = insertion(root, n);
        cin >> n;
    }
}

bool search(Node* root , int x){ 
    //sc - O(n) due to recursion
    // if(root == NULL)  return NULL;  
    // if(root -> data ==  x) return root -> data;
    
    // if(root -> data > x){ 
    //     return search(root -> left,x);
    // }
    // return search(root -> right,x);
    //tc - O(n) sc - O(1)
    Node*temp = root;

    while(temp != NULL){ 
        if(temp -> data == x){ 
            return true;
        }
        if(temp -> data > x){
            temp = temp -> left;
        }if(temp -> data < x) {
            temp = temp -> right;
        }
    }
    return false;
}

int maxi(Node* & root){ 
    Node* temp = root;
    while(temp -> right != NULL){ 
        temp = temp -> right;
    }
    return temp -> data;
}

Node* mini(Node* & root){ 
    Node* temp = root;
    while(temp -> left != NULL){ 
        temp = temp -> left;
    }
    return temp;
}

Node* deleteBst(Node* & root , int d){ 
    if(root == NULL)  return NULL;

    if(root -> data == d){
        //0 child 
        if(root -> left == NULL && root -> right == NULL){ 
            delete root;
            return NULL;
        }

        // 1 child
        if(root -> left != NULL & root -> right == NULL){ 
            Node * temp = root -> left;
            delete root;
            return temp;
        }

        if(root -> left == NULL & root -> right != NULL){ 
            Node * temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child 
        if(root -> left != NULL & root -> right != NULL){ 
            int mini_right = mini(root -> right) -> data;
            root -> data = mini_right;
            root -> right = deleteBst(root -> right,d);
            return root;
        }

    }else if(root -> data > d){
        deleteBst(root -> right,d);
        return root;
    }else {
        deleteBst(root -> left,d);
        return root;
    }

}

int main() {
    Node* root = nullptr;
    takeinput(root);
    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);
    return 0;
}
