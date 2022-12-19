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
    void flatten(TreeNode* root) {
        helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        TreeNode* right = helper(root->right);
        TreeNode* left = helper(root->left);
        if (left != NULL) {
            root->right = left;
            root->left = NULL;
            TreeNode* second = left;
            while(second->right != NULL) {
                second = second->right; 
            }
            second->right = right;
        } else {
            root->left = NULL;
            root->right = right;
        }
        return root;
    }
};
```