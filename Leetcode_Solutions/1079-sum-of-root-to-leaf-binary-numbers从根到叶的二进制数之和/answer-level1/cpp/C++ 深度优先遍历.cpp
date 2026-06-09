```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    void dfs(TreeNode* root, long p, long& res) {
        if (root == NULL) return;
        p = (p << 1) | root->val;
        if (root->left == NULL && root->right == NULL) {
            res += p;
            res %= M;
            return;
        }
        dfs(root->left, p, res);
        dfs(root->right, p, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        long res = 0;
        long p = 0;
        dfs(root, p, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/91d7a73c7e8d3784ba6a67927c992096191ba722a014b9d49bb27832d3d6dd91-image.png)
