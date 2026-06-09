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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            if (node->right) nodes.push(node->right);
            if (node->left) nodes.push(node->left);
        }
        return result;
    }
};
```