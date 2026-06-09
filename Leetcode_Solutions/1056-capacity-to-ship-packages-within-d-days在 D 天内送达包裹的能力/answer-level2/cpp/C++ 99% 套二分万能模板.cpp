```
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0, r = 500 * 50000 + 1, m;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (cannot_achieve(weights, D, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
    bool cannot_achieve(vector<int> &weights, int D, int m) {
        int cnt = 0, rem = 0;
        for (auto w : weights) {
            if (rem >= w) {
                rem -= w;
            } else {
                rem = m - w;
                ++cnt;
            }
            if (cnt > D || m < w) return true;
        }
        return false;
    }
};
```