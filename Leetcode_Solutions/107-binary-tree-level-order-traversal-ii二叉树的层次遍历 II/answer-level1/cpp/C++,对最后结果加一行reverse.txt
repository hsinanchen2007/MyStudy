```
class Solution {
private:
    void p(queue<TreeNode*> &q1, queue<TreeNode*> &q2, vector<vector<int>> &res){
        vector<int> v_temp;
        while(!q1.empty()){
            TreeNode *temp = q1.front(); q1.pop();
            v_temp.push_back(temp->val);
            if(temp->left)  q2.push(temp->left);
            if(temp->right) q2.push(temp->right);
        }
        res.push_back(v_temp);
        if(!q2.empty())
            p(q2, q1, res);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q1, q2;
        if(root){
            q1.push(root);
            p(q1, q2, res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
