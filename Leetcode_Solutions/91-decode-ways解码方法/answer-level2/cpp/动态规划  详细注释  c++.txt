### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int dp[s.size()+1];
        dp[0]=1;dp[1]=1;//dp[i]指长度为i的字符串有多少种编码方式，s[i]对应的是dp[i+1]
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){          //以0结尾单独讨论
                if(s[i-1]=='1'||s[i-1]=='2') 
                    dp[i+1]=dp[i-1];//因为s[i-1]必须与s[i]组合，只有s-2长度的字符能用来编码
                else
                    return 0;//编码失败
            }
            else{
                if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')//字符串末尾两个字符在26以内
                    dp[i+1]=dp[i]+dp[i-1];//末尾可看成单独的两个个字母，也可看成组合
                else 
                    dp[i+1]=dp[i];//末尾只能看成一个单独的字母
            }
        }
        return dp[s.size()];
    }
};
```