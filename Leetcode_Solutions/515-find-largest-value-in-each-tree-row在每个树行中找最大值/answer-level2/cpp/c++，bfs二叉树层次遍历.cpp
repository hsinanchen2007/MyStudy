水题
```
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            int maxVal = q.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(maxVal);
        }
        return res;
    }
```