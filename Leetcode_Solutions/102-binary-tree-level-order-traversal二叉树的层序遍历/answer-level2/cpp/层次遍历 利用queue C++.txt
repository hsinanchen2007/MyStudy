```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        vector<int> r;
        q.push(root);
        while(!q.empty()){
            r.clear();
            int n = q.size();
            while(n--){
                TreeNode* tmp = q.front();
                r.push_back(tmp->val);
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(r);
        }
        return res;
    }
};
```
