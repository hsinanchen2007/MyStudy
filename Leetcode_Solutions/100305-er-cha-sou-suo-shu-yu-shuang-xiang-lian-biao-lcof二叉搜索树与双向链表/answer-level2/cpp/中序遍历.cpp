### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head;
    Node* pre;
    Node* p;
    Node* treeToDoublyList(Node* root) {
        if(!root)return NULL;
        inorder(root);
        pre->right=head;
        head->left=pre;
        return head;
    }
    void inorder(Node* root){
        if(root->left){
            inorder(root->left);
        }
        root->left=pre;
        if(pre==NULL){
            head=root;
        }
        else{
            pre->right=root;
        }
        pre=root;
        if(root->right){
            inorder(root->right);
        }
    }
};
```