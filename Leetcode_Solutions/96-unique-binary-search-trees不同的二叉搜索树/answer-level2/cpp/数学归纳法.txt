```
class Solution {
public:
    int numTrees(int n) {
        /*
        n=1: 1 => 1 => 1
        n=2: 1   1 => 3 => 2
        n=3: 2   2  1 => 9 => 5
        n=4: 5   5  3  1 => 28 => 14
        n=5: 14 14  9  4  1 => 90 => 42
        */
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 1);
        dp[0] = 0;
        int last_res = 1;
        int last_sum = 1;
        for (int i = 2; i < n; ++i) {
            int sum = i + last_res;
            int last = 1;
            for (int j = i-1; j > 1; --j) {
                dp[j] = dp[j-1] + last;
                last = dp[j];
                sum += dp[j] * j;
            }
            dp[1] = last_res;
            last_res += last_sum;
            last_sum = sum;
        }
        return last_res + last_sum;
    }
};
```
