```
class Solution{
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root){
        if(!root) return res;
        string path(to_string(root->val));
        if(!root->left && !root->right) res.push_back(path);
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
        return res;
    }
    void dfs(TreeNode* root, string path){
        path = path + "->" + to_string(root->val);
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
    }
};
```
