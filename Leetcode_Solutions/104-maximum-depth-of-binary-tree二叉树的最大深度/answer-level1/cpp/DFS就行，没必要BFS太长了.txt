```C++ []
class Solution {
public:
    int  dfs(TreeNode* p, int deep){
        if(!p)
            return deep;
        return max(dfs(p->left, deep + 1),dfs(p->right, deep + 1));
    }
    int maxDepth(TreeNode* root) {
        int ans = dfs(root, 0);
        return ans;
    }
};

```

感觉dfs挺好做的