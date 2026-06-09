```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res,ans;
    int tpmaxn=INT_MIN;
    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp =q.front();
                ans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
            for(int i=0;i<ans.size();i++){
                tpmaxn=max(tpmaxn,ans[i]);
            }
            res.push_back(tpmaxn);
            tpmaxn=INT_MIN;
            ans.clear();
        }

    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        bfs(root);
        return res;
    }
};
```
