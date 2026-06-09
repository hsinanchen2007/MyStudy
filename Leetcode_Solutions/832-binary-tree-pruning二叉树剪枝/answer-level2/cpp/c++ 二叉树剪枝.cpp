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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root->left);　　　//剪左枝
        root->right = pruneTree(root->right);　　//剪右枝
        if(root->val==0 && !root->left && !root->right) 
            return NULL;　//如果当前根节点值为0，且左右枝都为空，剪掉
        return root;
    }
};
```