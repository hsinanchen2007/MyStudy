```c++
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
        if (root==nullptr) return nullptr;
        if (root->val == key) {
            if (!root->left) {
                TreeNode* newRoot = root->right;
                delete root;
                return newRoot;
            }
            else if (root->left && !root->right) {
                TreeNode* newRoot = root->left;
                delete root;
                return newRoot;
            }else{
                TreeNode* newRoot = root->left;
                if (newRoot->right) {
                    insertNode(root->right, newRoot->right);
                }
                newRoot->right = root->right;
                delete root;
                return newRoot;
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
    void insertNode(TreeNode* root, TreeNode* node) {
        while(1) {
            if (node->val <= root->val) {
                if (root->left == nullptr) {
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right == nullptr) {
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        if (node->val <= root->val) {
            root->left = node;
        } else {
            root->right = node;
        }
    }
};
```
