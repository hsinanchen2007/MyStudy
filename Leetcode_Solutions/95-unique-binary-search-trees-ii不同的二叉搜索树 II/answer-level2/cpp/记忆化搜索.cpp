```
const int mod = 1005;
class Solution {
private:
    unordered_map<int, vector<TreeNode*>> mp;
    vector<TreeNode*> dfs(int s, int e)
    {
        if (s == e) {
            vector<TreeNode*> tmp = { new TreeNode(s) };
            int code = s * mod + e;
            mp[code] = tmp;
            return tmp;
        }
        if (s > e) {
            return { NULL };
        }
        int code = s * mod + e;
        if (mp.count(code))
            return mp[code];
        vector<TreeNode*> tmp;
        for (int i = s; i <= e; ++i) {
            vector<TreeNode*> l = dfs(s, i - 1);
            vector<TreeNode*> r = dfs(i + 1, e);
            for (TreeNode* ls : l) {
                for (TreeNode* rs : r) {
                    TreeNode* mid = new TreeNode(i);
                    mid->left = ls, mid->right = rs;
                    tmp.push_back(mid);
                }
            }
        }
        mp[code] = tmp;
        return tmp;
    }

public:
    vector<TreeNode*> generateTrees(int n)
    {
        if(n == 0) return {};
        return dfs(1, n);
    }
};
```
