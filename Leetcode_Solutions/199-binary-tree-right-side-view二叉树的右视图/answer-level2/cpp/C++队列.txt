```
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int len = q.size();
            int next;
            bool is_get = false;
            while (len--) {
                TreeNode* cur = q.front();
                q.pop();
                next = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            res.push_back(next);
        }
        return res;
    }
};
```
