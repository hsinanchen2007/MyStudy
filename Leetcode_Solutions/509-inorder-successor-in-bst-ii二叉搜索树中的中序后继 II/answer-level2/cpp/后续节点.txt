### 解题思路

后续节点

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node==NULL)return NULL;
        if(node->right){
            node=node->right;
            while(node->left)node=node->left;
            return node;
        }
        if(node->parent==NULL)return NULL;
        int tmp=node->val;
        while(node&&node->val<=tmp){
            node=node->parent;
        }
        return node;
    }
};
```