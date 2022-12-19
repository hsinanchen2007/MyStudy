```
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int res,idx=0;
        dfs(root,idx,k,res);
        return res;
    }
    void dfs(TreeNode* root,int &idx,int k,int&res){
        if(!root)
            return;
        dfs(root->right,idx,k,res);
        if(++idx==k){
            res=root->val;
            return;
        }
        dfs(root->left,idx,k,res);
    }
};
```
