```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i< len; i++){
                TreeNode* now = q.front();
                v.push_back(now->val);
                q.pop();
                if(now->left) q.push(now->left);
                if(now->right) q.push(now->right);
            }
            res.push_back(v);
            v.clear();
           
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
