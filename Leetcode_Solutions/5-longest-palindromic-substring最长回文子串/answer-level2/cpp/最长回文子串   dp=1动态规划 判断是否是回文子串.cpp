### 解题思路
初始化，长度为1和2的dp
双层循环窗口滑动，长度从3开始。

包含了：
1.dp判断是否是回文串
2. 是回文串则标记起始位置 和 长度。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        int max=1;
        int start=0;
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i=0;i<len;i++){
            dp[i][i]=1;
            if(i+1<len&&s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                max=2;
            }
        }
        for(int l=3;l<=len;l++){//外循环控制长度，注意可以等于len
            for(int i=0;i+l-1<len;i++){//内循环控制固定窗口滑动
                int j=i+l-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);
    }
};
```