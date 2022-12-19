### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL)
            return root;
        
        return exchange(root);
        
    }
    
    TreeNode* exchange(TreeNode* node){
        if(node!=NULL){
            exchange(node->left);
            exchange(node->right);
            TreeNode* p = node->left;
            node->left = node->right;
            node->right = p;
        }
        return node;
    }
};
```