### 解题思路
看了大神的解题思路，自己记录一下。帮助记忆。
1、其中dp[i+1]:表示从s[0]到s[i]可以解码的方法总数。所以s[0]对应的dp[1]。初始化dp[0] = 1;
2.1若s[i]== 0 && s[i-1] == '1' || '2,表示s[i]只能和s[i-1]一起组成一个数，故dp[i+1]= dp[i-1]。
   若s[i]==0&&s[i-1]>2,此时不能解码，直接返回0
2.2若1<=s[i]<=6,且s[i-1]==2，此时可以s[i]和s[i-1]组成一个数，此时dp[i+1] = dp[i-1]；也可以s[i]和s[i-1]分别组成一个数，此时dp[i+1] = dp[i];
2.3其他情况dp[i+1] = dp[i]


### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s.size()== 0 || s[0] == '0'){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 1; i<n; i++){
            if(s[i] == '0'){
                if(s[i-1] == '1'|| s[i-1] == '2'){
                    dp[i+1] = dp[i-1];
                }
                else{
                    return 0;
                }
            }
            else if(s[i] >= '1'&&s[i] <= '6' && s[i-1] == '2' || s[i-1] == '1'){
                dp[i+1] = dp[i-1] +dp[i];
            }
            else{
                dp[i+1] = dp[i];
            }
        }
        return dp[n];
    }
};
```