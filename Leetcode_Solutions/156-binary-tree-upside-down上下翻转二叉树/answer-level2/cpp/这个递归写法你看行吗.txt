```
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* new_root = nullptr, *last = nullptr;
        dfs(root, new_root, last);
        return new_root;
    }

    void dfs(TreeNode* root, TreeNode* &new_root, TreeNode* &last){
        if (!root) {
            last = nullptr;
            return;
        }
        dfs(root->left, new_root, last);
        dfs(root->right, new_root, last);
       // if (last)
       {
            if (root->left && root->right == last){
                root->left->left = last;
                root->left->right = root;
                root->right = nullptr;
                root->left = nullptr;
            }else{
                //last = nullptr;//!!!
            }
        }

        last = root;
        if (!new_root) new_root = root;
    }
};
```
