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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        stack<TreeNode*> nodes;
        push(root, nodes);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            push(node->right, nodes);
        }
        return result;
    }

    void push(TreeNode* root, stack<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push(root);
        while (root->left) {
            nodes.push(root->left);
            root = root->left;
        }
    }
};
```