```c++
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if (i > 1) {
                int t = stoi(s.substr(i-2, 2));
                if (t >= 10 && t <= 25) {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};
```