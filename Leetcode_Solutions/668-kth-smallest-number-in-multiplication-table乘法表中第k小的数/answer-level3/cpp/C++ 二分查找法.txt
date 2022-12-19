```
class Solution {
public:
    int countLessEqual(int m, int n, int t) {
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            res += min(t / i, n);
        }
        return res;
    }
    int findKthNumber(int m, int n, int k) {
        int r = m * n;
        int l = 1;
        while (l < r) {
            int md = l + (r - l) / 2;
            int c = countLessEqual(m, n, md);
            if (c >= k) {
                r = md;
            } else {
                l = md + 1;
            }
        }
        return r;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d6e4ffa316fec034130d27ceea8adf872203093073950dd5f49307a1092575f4-image.png)


