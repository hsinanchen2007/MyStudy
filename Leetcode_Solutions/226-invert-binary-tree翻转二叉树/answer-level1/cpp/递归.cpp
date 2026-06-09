
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
    TreeNode* invertTree(TreeNode* root) {

        TreeNode *temp = NULL;        
        if (root)
        {
            temp = root->left;  // 对当前节点进行翻转
            root->left = root->right;
            root->right = temp;
            
            invertTree(root->left);  // 对左子树进行翻转
            invertTree(root->right);  // 对右子树进行翻转
        }
        return root;
    }
};
