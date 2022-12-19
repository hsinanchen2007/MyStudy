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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool hasValue = false;
        int currentValue = 0;
        stack<TreeNode*> s;
        s.push(root);
        while (root->left) {
            s.push(root->left);
            root = root->left;
        }
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (hasValue && currentValue >= node->val) return false;
            currentValue = node->val;
            hasValue = true;
            if (node->right) {
                s.push(node->right);
                node = node->right;
                while (node->left) {
                    s.push(node->left);
                    node = node->left;
                }
            }
        }
        return true;
    }
};
```