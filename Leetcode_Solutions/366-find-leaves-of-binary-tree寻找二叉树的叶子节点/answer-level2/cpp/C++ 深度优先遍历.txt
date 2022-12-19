```C++ []
class Solution {
public:
    int dfs(TreeNode* root, map<int, vector<int> >& m) {
        if (root == NULL) return 0;
        int d = 1 + max(dfs(root->left, m), dfs(root->right, m));
        m[d].push_back(root->val);
        return d;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        map<int, vector<int> > m;
        dfs(root, m);
        vector<vector<int> > res;
        for (auto& p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/b1cbcac365c7379eaa618fc219256edfd6fc0fd08f08ff11da10da071ee23813-image.png)
