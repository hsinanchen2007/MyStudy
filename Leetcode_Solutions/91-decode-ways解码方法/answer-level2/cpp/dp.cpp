### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        vector<int> dp(length+1);
        if(s[0] == '0') return 0;
        if(length==1 && s[0] != '0') return 1;
        dp[0]=1;
        if(s[0]=='0') dp[1]=0;
        if(s[0]!='0') dp[1]=1;

        for(int i=2;i<=length;i++){
            if(s[i-1]=='0'){
                if(s[i-2]-'0'>2 || s[i-2]=='0') dp[i]=0;
                else dp[i] = dp[i-2];
            }else{
                if((s[i-2]-'0')*10+s[i-1]-'0'>26 || s[i-2]=='0') dp[i]=dp[i-1];
                else{
                    dp[i] = dp[i-1]+dp[i-2];
                }
            }
        }
        return dp[length];
    }
};
```