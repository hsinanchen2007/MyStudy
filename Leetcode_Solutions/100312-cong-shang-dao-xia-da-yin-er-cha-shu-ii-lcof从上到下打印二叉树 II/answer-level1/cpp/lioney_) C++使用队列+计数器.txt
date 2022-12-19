```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for(int i=0; i<size; i++) {
                root = q.front(); q.pop();
                tmp.push_back(root->val);
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```
