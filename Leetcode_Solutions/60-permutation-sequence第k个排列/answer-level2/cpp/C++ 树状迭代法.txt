```
class Solution {
public:
    string getPermutation(int n, int k) {
        int a = 1;
        int t = n;
        while (--t > 0) {
            a *= t;
        }
        vector<bool> used(n + 1, false);
        int count = a;
        int res = 1;
        int i = 1;
        used[1] = true;
        while (i < n) {
            if (count < k) {
                int t = res % 10;
                used[t] = false;
                res -= t;
                for (int j = t + 1; j <= n; ++j) {
                    if (!used[j]) {
                        res += j;
                        used[j] = true;
                        break;
                    }
                }
                count += a;
            } else {
                count -= a;
                a /= n - i;
                count += a;
                ++i;
                res *= 10;
                for (int j = 1; j <= n; ++j) {
                    if (!used[j]) {
                        res += j;
                        used[j] = true;
                        break;
                    }
                }
            }
        }
        return to_string(res);
    }
};
```
![image.png](https://pic.leetcode-cn.com/6014f56cd6969a62bc6cede5e3ca9b031adcd6a1ecdc1e3146d5727ff2db42a1-image.png)
