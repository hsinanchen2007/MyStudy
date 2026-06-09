### 解题思路
考虑上一个数字和当前数字就可以求得当前数字对应的解。

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if (s.size() == 0) return 0;
        // initialize;
        for (int i = 0; i < 2 && i < s.size(); i++) {
            if (i == 0) {
                if(s[i] == '0') {
                    // 此时无法编码;
                    return 0;
                } else {
                    // 非0的数字,第一个数字只有1个解;
                    dp[i] = 1;
                }
            }
            if (i == 1) {
                if (s[i - 1] == '1') {
                    if (s[i] != '0') {
                        dp[i] = 2;
                    } else {
                        dp[i] = 1;
                    }
                } else if (s[i - 1] == '2') {
                    if (s[i] > '6' || s[i] == '0') {
                        dp[i] = 1;
                    } else {
                        dp[i] = 2;
                    }
                } else {
                    if (s[i] == '0') {
                        //此时无法编码;
                        return 0;
                    } else {
                        dp[i] = 1;
                    }
                }
            }
        }
        for (int i = 2; i < s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i] == '0') {
                    // 此时无法解码;
                    return 0;
                } else {
                    dp[i] = dp[i - 1];
                }
            } else if (s[i - 1] == '1') {
                if (s[i] == '0') {
                    dp[i] = dp[i - 2];
                } else {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
            } else if (s[i - 1] == '2') {
                if (s[i] == '0') {
                    dp[i] = dp[i - 2];
                } else if (s[i] < '7') {
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    dp[i] = dp[i - 1];
                }
            } else {
                if (s[i] == '0') {
                    // 此时无法编码;
                    return 0;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp.back();
    }
};
```