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
    using DT = long long;
    map<TreeNode*, pair<DT, DT> > coordinates;
    void dfs(TreeNode* root, DT x, DT y) {
        if (root == NULL) return;
        coordinates[root] = {x, y};
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};
        dfs(root, 0, 0);
        map<int, vector<pair<int, TreeNode*> > > m;
        for (auto& p : coordinates) {
            m[p.second.first].push_back({p.second.second, p.first});
        }
        vector<vector<int> > res;
        for (auto& p : m) {
            sort(p.second.begin(), p.second.end());
            vector<int> v;
            for (auto& t : p.second) {
                v.push_back(t.second->val);
            }
            res.push_back(v);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4f9f804ea69773d0ebd1bcea5572ae9f42912446e1f78141b497a39ed10035fe-image.png)
