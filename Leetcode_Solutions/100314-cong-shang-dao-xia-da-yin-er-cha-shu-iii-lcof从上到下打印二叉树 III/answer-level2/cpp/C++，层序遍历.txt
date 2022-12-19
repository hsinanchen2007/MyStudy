```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> t;
        queue<TreeNode*> q;
        q.push(root);
        if(!root){
            return t;
        }
        int index=0;
        while(!q.empty()){
            vector<int>r;
            int l=q.size();
            for(int i=0;i<l;i++){ 
                TreeNode* temp=q.front();
                r.push_back(temp->val);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(index%2!=0){
                vector<int> re;
                for(int c=r.size()-1;c>=0;c--){
                    re.push_back(r[c]);
                }
                t.push_back(re);
            }
            else
                t.push_back(r);
            index++;
        }
        return t;
    }
};
```
