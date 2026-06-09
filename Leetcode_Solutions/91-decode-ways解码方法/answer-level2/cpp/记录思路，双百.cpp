### 解题思路
dp[i+1]表示s[0..i]的解码数，
当s[i]==0,
    若前一位为0，return 0，
    否则dp[i+1]=dp[i-1] 即s[i]与s[i-1]为唯一方案，并与s[i-2]之前的合并
否则，当s[i-1]==1时，
    若s[i]单独译码，不会增加，有dp[i]种，若s[i]与s[i-1]一起单独译码，则有dp[i-1]种，所以dp[i+1]=dp[i]+dp[i-1]
或者 s[i-1]==2时，
    若s[i]<=6,同上，
    否则，s[i]只能单独译码，不会增加，则dp[i+1]=dp[i]

分情况讨论

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n=s.size();
        vector<int> dp(n+1,1);//dp[i]是s[0..i]的解码数；
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2')
                    dp[i+1]=dp[i-1];
                else return 0;
            }
            else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6')){
                dp[i+1]=dp[i-1]+dp[i];
            }
            else dp[i+1]=dp[i];
        }
        return dp[n];
    }
};
```