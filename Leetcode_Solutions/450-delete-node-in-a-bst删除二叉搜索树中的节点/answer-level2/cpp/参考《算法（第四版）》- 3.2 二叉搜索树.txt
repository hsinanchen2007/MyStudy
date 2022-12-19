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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if      (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            TreeNode* t = root;
            root = getMinNode(t->right);
            root->right = deleteMinNode(t->right);
            root->left = t->left;
        }
        return root;
    }

private:
    TreeNode* getMinNode(TreeNode* root)
    {
        if (root->left == nullptr) return root;
        return getMinNode(root->left);
    }

    TreeNode* deleteMinNode(TreeNode* root)
    {
        if (root->left == nullptr) return root->right;
        root->left = deleteMinNode(root->left);
        return root;
    }
};
```
