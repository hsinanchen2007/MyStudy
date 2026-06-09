### 解题思路
1、根据动态规划，得出至少两个字符之间是否是回文子串。
2、单个字符也可以作为回文子串。所以count需要加上字符长度。

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1){
            return 1;
        }
        int count = 0;
        count = s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i = 1; i< n; i++){
            for(int j = 0; j < i; j++){
                if(s[i]==s[j] &&(i-j<=2 || dp[j+1][i-1])){
                    dp[j][i] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
```