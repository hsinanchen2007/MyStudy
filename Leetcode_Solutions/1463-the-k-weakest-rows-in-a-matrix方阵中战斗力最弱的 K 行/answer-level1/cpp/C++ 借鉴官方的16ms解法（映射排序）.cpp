### 代码
```cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<int> cnt;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) cnt.push_back(accumulate(mat[i].begin(),mat[i].end(),0));
        iota(ans.begin(), ans.end(), 0);
        sort(ans.begin(), ans.end(), [&](int i, int j) {return cnt[i] < cnt[j] || (cnt[i] == cnt[j] && i < j);});
        ans.resize(k);
        return ans;
    }
};
```