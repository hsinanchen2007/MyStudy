### 解题思路
递归创建

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
    if(!root) return NULL;
    TreeNode* ret = new TreeNode(root->val);
    ret->left = mirrorTree(root->right);
    ret->right = mirrorTree(root->left);
    return ret;
    }
 
};
```