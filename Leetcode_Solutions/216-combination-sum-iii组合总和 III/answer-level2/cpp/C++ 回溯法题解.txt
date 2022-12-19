```
class Solution {
public:
    void backtrace(unordered_set<int>& candidate, vector<int>& rec, vector<vector<int> >& res, int i, int k, int s, int n) {
        if (s > n) return;
        if (i == k) {
            if (s == n) {
                res.push_back(rec);
            }
            return;
        }
        vector<int> v(candidate.begin(), candidate.end());
        for (auto x : v) {
            if (!rec.empty() && x < rec.back()) continue;
            candidate.erase(x);
            rec.push_back(x);
            backtrace(candidate, rec, res, i + 1, k, s + x, n);
            candidate.insert(x);
            rec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> rec;
        vector<vector<int> > res;
        unordered_set<int> candidate{1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrace(candidate, rec, res, 0, k, 0, n);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c13e8fa10a53be95e958b0605821f062b1dbc3fa7893751eaaae377c6ab8ea19-image.png)
