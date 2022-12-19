### 解题思路


### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int len=s.size();
        if(s[0]=='0') return 0;
        vector<int> dp(len+1,1);//因为防止i-2越界，所以取i+1代表len
        for(int i=1;i<len;i++){
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2') dp[i+1]=dp[i-1];
                else return 0;
            }
            else if(s[i-1]=='1'||s[i-1]=='2'&&s[i]>='1'&&s[i]<='6')
            {
                dp[i+1]=dp[i-1]+dp[i];
            }
            else dp[i+1]=dp[i];//其他情况第i个字符只能放一边
        }
        return dp[len];
    }
};
```