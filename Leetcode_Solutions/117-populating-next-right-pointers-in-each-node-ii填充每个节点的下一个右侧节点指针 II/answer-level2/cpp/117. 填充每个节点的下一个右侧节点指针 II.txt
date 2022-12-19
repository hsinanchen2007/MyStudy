### 解题思路
通俗易懂的代码
先递归右子树再左子树，保证不断链

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* r;
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left==NULL&&root->right==NULL) return root;
        if(root->left){
            if(root->right)
            root->left->next=root->right;
            else{
                r=root->next;
                while(r){
                    if(r->left==NULL&&r->right==NULL)  r=r->next;
                    else break;
                } 
                if(r){
                    if(r->left) root->left->next=r->left;
                    else if(r->right) root->left->next=r->right;
                }
              
            }
        } 
        if(root->right){
            r=root->next;
            while(r){
                if(r->left==NULL&&r->right==NULL)  r=r->next;
                else break;
            } 
            if(r){
                if(r->left) root->right->next=r->left;
                else if(r->right) root->right->next=r->right;
            }
        }   
        connect(root->right);
        connect(root->left);
        return root;
    }
};
```