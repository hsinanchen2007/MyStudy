### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n);
        if(s[0]=='0') return 0;
        //=dp[i-1]表示把当前第i个单独和前面组合的情况数
        //=dp[i-2]表示把当前第i个同第i-1个拼起来后与前面组合的情况数
        fill(dp.begin(),dp.end(),1);
        for(int i=1;i<n;i++){
            cout<<s[i]<<endl;
            if(i==1){
                if(s[i]=='0'){
                     if(atoi((char*)s.substr(i-1,2).data())<=26&&s[i-1]!='0') dp[i]=dp[i-1];//i和i-1只能合起来看
                     else return 0;
                }
                else{
                    if(atoi((char*)s.substr(i-1,2).data())<=26&&s[i-1]!='0'){
                        dp[i]=2;
                    }
                    else{
                        dp[i]=1;
                    }
                   
                }
            }
            else{
                if(s[i]=='0'){
                    if(s[i-1]=='0'||s[i-1]>'2') return 0;
                    else{
                        dp[i]=dp[i-2];//i和i-1只能合起来看
                    }
                }
                else{
                    if(atoi((char*)s.substr(i-1,2).data())<=26&&s[i-1]!='0'){
                        dp[i]=dp[i-1]+dp[i-2];
                    }
                    else{
                        dp[i]=dp[i-1];
                    }
                   
                }
            }
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n-1];
    }
};
```