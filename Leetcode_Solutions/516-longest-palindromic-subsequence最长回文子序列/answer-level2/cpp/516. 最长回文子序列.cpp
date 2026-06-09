### 解题思路
看注释吧

### 代码

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n;i++ ){//将len = 1或者len = 2的长度的子序列进行初始化
            dp[i][i] = 1;
            
            if((i+1) < n){
                if(s[i] == s[i+1]){
                    dp[i][i+1] = 2;
                }else{
                    dp[i][i+1] = 1;
                }
            }
        }

        for (int len = 3; len <= n; ++len) {//长度为1或者2的子串已经完成初始化，所以此处从len = 3的长度开始
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end]) {//如果两端的字符相同，则在len-2的子串中最大回文子序列长度基础上+2
                    dp[start][end] = dp[start + 1][end - 1] + 2;
                } else {//如果不相同，则取len-1的子串中回文子序列的最大长度
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};
```