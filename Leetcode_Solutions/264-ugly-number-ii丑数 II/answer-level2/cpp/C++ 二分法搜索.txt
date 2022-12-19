二分查找算法
```
class Solution {
public:
    using ll = long long;
    vector<ll> p2, p3, p5;
    Solution() {
        p2 = vector<ll>(31, 1);
        for (int i = 1; i < p2.size(); ++i) {
            p2[i] = 2 * p2[i - 1];
        }
        p3 = vector<ll>(20, 1);
        for (int i = 1; i < p3.size(); ++i) {
            p3[i] = 3 * p3[i - 1];
        }
        p5 = vector<ll>(14, 1);
        for (int i = 1; i < p5.size(); ++i) {
            p5[i] = 5 * p5[i - 1];
        }
    }
    int count(int n) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (p2[i] * p3[j] > n) break;
                for (int k = 0; k < 14; ++k) {
                    if (p2[i] * p3[j] * p5[k] > n) break;
                    ++res;
                }
            }
        }
        return res;
    }
    int nthUglyNumber(int n) {
        ll l = 1;
        ll r = INT_MAX;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (count(m) < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r;
    }
};
```
不过效率确实没有dp高，不过也是一种解法
![image.png](https://pic.leetcode-cn.com/b1c017cb551526b19924b9977e25094e7c1b36fa2992fdb8f07c100e4d92c579-image.png)

