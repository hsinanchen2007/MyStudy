```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(); //标识一层节点个数
            vector<int> r;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                r.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(r);
        }
        return res;
    }
};
```
