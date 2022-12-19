```
class Solution {
private:
    int res;
    void dfs(TreeNode *root, int min_parent, int max_parent){
        if(min_parent!=INT_MAX)
            res = max(res, abs(root->val-min_parent));
        if(max_parent!=-1)
            res = max(res, abs(max_parent-root->val));
        min_parent = min(min_parent, root->val);
        max_parent = max(max_parent, root->val);
        if(root->left)
            dfs(root->left, min_parent, max_parent);
        if(root->right)
            dfs(root->right, min_parent, max_parent);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        this->res = 0;
        dfs(root, INT_MAX, -1);
        return this->res;
    }
};
```
