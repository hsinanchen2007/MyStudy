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
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        push(root, nodes);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            if (k == 1) return node->val;
            k--;
            push(node->left, nodes);
        }
        return root->val;
    }

    void push(TreeNode* root, stack<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push(root);
        while (root->right) {
            nodes.push(root->right);
            root = root->right;
        }
    }
};
```