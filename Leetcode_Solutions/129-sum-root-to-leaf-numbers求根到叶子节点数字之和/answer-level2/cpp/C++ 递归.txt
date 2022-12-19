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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode* root, int acc) {
        if (!root) return acc;
        if (!root->left && !root->right) return 10 * acc + root->val;
        int s = 0;
        if (root->left) {
            s += sumNumbers(root->left, 10 * acc + root->val);
        }
        if (root->right) {
            s += sumNumbers(root->right, 10 * acc + root->val);
        }
        return s;
    }
};
```