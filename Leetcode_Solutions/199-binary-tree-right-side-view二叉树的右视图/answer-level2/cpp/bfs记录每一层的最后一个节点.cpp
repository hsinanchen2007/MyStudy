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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; i --) {
                auto it = q.front();
                q.pop();
                if (it->left) q.push(it->left);
                if (it->right) q.push(it->right);
                if (i == 0) ans.push_back(it->val);
            }
        }
        return ans;
    }
};
```