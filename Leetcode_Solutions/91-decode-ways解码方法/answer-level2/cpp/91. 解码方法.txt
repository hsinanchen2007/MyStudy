### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numDecodings(string s) {
        
        const int str_len = s.length();
        int dp [str_len] = {0};
        
        for(int i = 0; i<str_len; ++i){

            if (i == 0){
                if(s[i] == '0') return 0;
                else dp[i] = 1;
            }

            if (i == 1){
                if(s[i] == '0' ){
                    if(s[i-1] == '1' || s[i-1] == '2') {dp[i] = 1;}
                    else return 0;                   
                }
                if(s[i]>'6'){
                    if(s[i-1] >='2'){ dp[i] = 1;}
                    if(s[i-1] == '0'){return 0;}
                    if(s[i-1] == '1'){dp[i] = 2;}
                }
                if(s[i]<='6'&& s[i]!='0'){
                    if(s[i-1] == '1' || s[i-1] == '2') {dp[i] = 2;}
                    if(s[i-1] == '0'){return 0;}
                    if(s[i-1]>'2'){dp[i] = 1;}
                }
            }


            if(i>1){
                if(s[i] == '0' ){
                    if(s[i-1] == '1' || s[i-1] == '2') {dp[i] = dp[i-2];}
                    else return 0;                   
                }
                if(s[i]>'6'){
                    if(s[i-1] >='2'){ dp[i] = dp[i-1];}
                    if(s[i-1] == '0'){dp[i] = dp[i-1];}
                    if(s[i-1] == '1'){dp[i] = dp[i-2]+dp[i-1];}
                }
                if(s[i]<='6'&& s[i]!='0'){
                    if(s[i-1] == '1' || s[i-1] == '2') {dp[i] = dp[i-2]+dp[i-1];}
                    if(s[i-1] == '0'){return dp[i-1];}
                    if(s[i-1]>'2'){dp[i] = dp[i-1];}
                }
            }
        }

        return dp[str_len-1];


    }
};
```
我想这是所有题解里面最死板的最生硬的强行动态规划解法了
如果不分情况那么规律可以是这样想：

每当增加一个新元素时所能解码的情况 = 把这个新元素孤立来解的做法 + 把这个新元素和前面一个元素拼在一起来解的做法（因为解码方法最多能2个拼一起）
dp[i] = 最后一个元素单拆 [...],1 的所有情况 + 最后两个元素 [...],21
      = dp[i-1]  + dp[i-2]          

当然灵魂还是试子问题，然后找规律咯