简单粗暴，利用stack先进后出的特点，实现自底向上：用stack<vector<int>>先缓存结果，然后再一个个输出到vector<vector<int>>。

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        stack< vector<int> > svi;  //利用stack先进后出的特点，实现自底向上
        queue<TreeNode*> q; 
        q.push(root);
        while(!q.empty()){
            vector<int> vec_tmp;
            int q_size = q.size();
            for(int i=0; i<q_size; i++){
                TreeNode* p = q.front();
                q.pop();
                vec_tmp.push_back(p->val);
                if(p->left)  q.push(p->left);
                if(p->right) q.push(p->right);
            }
            svi.push(vec_tmp);
        }
        
        while(!svi.empty()){
            res.push_back(svi.top());
            svi.pop();
        }
        
        return res;
    }
};