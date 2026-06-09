```
class Solution {
public:
    //vector<int> v;
    long lt=LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(isValidBST(root->left)){
            if(lt<root->val){
                lt=root->val;
                return isValidBST(root->right);
            }return false;
        }
        return false;
    }
    
    
};
class Solution {
public:
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        int n=v.size();
        for(int i=1;i<n;i++)
            if(v[i]<=v[i-1])
                return false;
        return true;
    }
    void dfs(TreeNode* root){
        if(!root)
            return ;
        dfs(root->left);
        v.emplace_back(root->val);
        dfs(root->right);
    }
    
};
```
