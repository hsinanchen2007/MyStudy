### 解题思路
设dp[j][i](写成j,i跟代码统一)是Sj...Si回文串的长度，如果不是回文串，则为0。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> result;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int max = -1;
        result = make_pair(0, 0);
        // 循环的条件需要注意，需要先初始化中心的字符串结果
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            if (max == -1)
                max = 1;
            for (int j = 0; j < i; j++) {
                if (i == j) continue;
                dp[j][i] = s[j] == s[i] ? (dp[j+1][i - 1] > 0 || (i == j + 1) ? i - j + 1 : 0) : 0; //充要条件是：si == sj, 当i == j+1 时，这是相邻的两个字符，组成回文, 当i != j+1时，则需要判断Sj+1~Si-1,也就是中心一些的字符串，是否回文，显然具有一致性
                if (dp[j][i] > 0 && dp[j][i] > max) {
                    max = dp[j][i];
                    result = make_pair(j, i);
                }
            }
        }
        return s.substr(result.first, result.second - result.first + 1);
    }
};
```