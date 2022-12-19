```
class Solution {
public:
    vector<int> bits;
    int N;
    void add(int i, int d) {
        while (i <= N) {
            bits[i] = max(bits[i], d);
            i += i & (-i);
        }
    }
    int query(int i) {
        int res = 0;
        while (i > 0) {
            res = max(res, bits[i]);
            i -= i & (-i);
        }
        return res;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<int> s(difficulty.begin(), difficulty.end());
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        N = s.size() + 1;
        bits = vector<int>(N + 1, 0);
        for (int i = 0; i < difficulty.size(); ++i) {
            int k = lower_bound(s.begin(), s.end(), difficulty[i]) - s.begin() + 1;
            add(k, profit[i]);
        }
        int res = 0;
        for (auto x : worker) {
            int k = upper_bound(s.begin(), s.end(), x) - s.begin();
            res += query(k);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/91ba488bf57932d01f7b531bf00e38cfcc4d28fd8eb4f4322fbc70a1ef0cc496-image.png)
