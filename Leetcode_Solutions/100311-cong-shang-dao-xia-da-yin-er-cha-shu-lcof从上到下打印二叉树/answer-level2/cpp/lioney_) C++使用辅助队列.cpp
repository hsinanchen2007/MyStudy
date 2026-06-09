```
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty()) {
            root = q.front(); q.pop();
            res.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        return res;
    }
};
```
