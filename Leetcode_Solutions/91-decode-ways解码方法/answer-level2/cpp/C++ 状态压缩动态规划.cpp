```
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int N = s.size();
        int dp1 = 1;
        int dp2 = 1;
        for (int i = 1; i < N; ++i) {
            int dp = 0;
            int t1 = s[i] - '0';
            if (t1 >=1 && t1 <= 9) {
                dp += dp2;
            }
            int t2 = stoi(s.substr(i - 1, 2));
            if (t2 >= 10 && t2 <= 26) {
                dp += dp1;
            }
            if (dp == 0) return 0;
            dp1 = dp2;
            dp2 = dp;
        }
        return dp2;
    }
};
```
![image.png](https://pic.leetcode-cn.com/241226dbe69d611114af2b96c86ae52c02dcb28c38b2ae1c730b2e561346fa58-image.png)
