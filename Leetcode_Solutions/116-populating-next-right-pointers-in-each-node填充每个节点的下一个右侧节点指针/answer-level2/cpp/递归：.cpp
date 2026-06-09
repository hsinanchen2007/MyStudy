```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        Connection(root->left,root->right);
        return root;     
    }
    
    void Connection(Node* left,Node* right){
        if(left == NULL || right==NULL)
            return;
        Connection(left->left,left->right);
        left->next = right;
        Connection(right->left,right->right);
        if(left->right){
            left->right->next = right->left;
            Connection(left->right,right->left);
        }
    }

};
```
![image.png](https://pic.leetcode-cn.com/b40f0762aa80e894f181ec614f83aa53f731db89b8f4ede0197528dfad113a87-image.png)
