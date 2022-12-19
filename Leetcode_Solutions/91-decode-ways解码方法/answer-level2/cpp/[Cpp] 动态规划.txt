### 解题思路
dp[i]表示s的前i个元素可以解码的方法数
如果第i个位置为0，则dp[i] = dp[i - 2],表示只能前i和i的前一个位置解码成一个字母
如果i不为0，则dp[i] = dp[i - 1]，即将前一个字母解码成一个字符
如果i-1和i能组成一个字符，则dp[i] += dp[i - 2]

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || (s.size() > 1 && s[0] == '0')) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
```