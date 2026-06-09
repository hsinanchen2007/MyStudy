```C++ []
class Solution {
public:
    void dfs1(const vector<vector<int> >& g, int i, int k, vector<int>& dfn) {
        dfn[i] = k;
        for (auto j : g[i]) {
            if (!dfn[j]) {
                dfs1(g, j, k + 1, dfn);
            }
        }
    }
    void dfs2(const vector<vector<int> >& g, const vector<int>& dfn, int i, int d1, int d2, vector<int>& res) {
        if (dfn[i] == d1 || dfn[i] == d2) {
            res.push_back(i);
        } else if (dfn[i] < d1 && dfn[i] < d2) {
            return;
        }
        for (auto j : g[i]) {
            if (dfn[j] < dfn[i]) {
                dfs2(g, dfn, j, d1, d2, res);
            }
        }
    }
    int getMaxInd(const vector<int>& nums) {
        return max_element(nums.begin(), nums.end()) - nums.begin();
    }
    int getMaxNum(const vector<int>& nums) {
        return nums[getMaxInd(nums)];
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int> > g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> dfn(n, 0);
        dfs1(g, 0, 1, dfn);
        int k = getMaxInd(dfn);
        fill(dfn.begin(), dfn.end(), 0);
        dfs1(g, k, 1, dfn);
        
        int d = getMaxNum(dfn);
        int d1 = (1 + d) / 2;
        int d2 = 1 + d / 2;
        k = getMaxInd(dfn);
        vector<int> res;
        dfs2(g, dfn, k, d1, d2, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/3f1b1d24b387863c99be86ade0b84e16d314fea513d482be52bafc9184e6fcc8-image.png)
