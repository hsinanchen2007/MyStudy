```cpp
class Solution {
public:
    double cnt1[1000] = { 0 };
    double cnt2[1000] = { 0 };
    int help(TreeNode* rt, int level) {
        if (rt == nullptr) return level;
        
        ++level;
        int l = help(rt->left, level);
        int r = help(rt->right, level);
        cnt1[level] += rt->val;
        ++cnt2[level];

        return max(l, r);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int level = help(root, -1);
        vector<double> ans;
        for (int i = 0; i <= level; ++i)
            ans.emplace_back(cnt1[i] / cnt2[i]);
        return ans;
    }
};
```