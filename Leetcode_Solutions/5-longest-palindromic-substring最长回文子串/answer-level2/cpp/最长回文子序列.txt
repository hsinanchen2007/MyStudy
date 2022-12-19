### 解题思路
看了别人的解题思路才终于把思路屡清楚了的，宝宝太笨，大佬太强呀！
如何判断一段字符串是不是回文？
    （1）首先看它的两端字符是否相同；
    （2）其次是它去头去尾之后的字符串是不是回文
两个条件都满足，则它是一段回文。
满足条件（1）：
头尾重合————true 这段字符串是回文(i=j)
头尾不重合，再去头去尾，去头去尾之后的字符串有3种情况：
    1、空字符串————true 这段字符串是回文(i+1=j)
    2、只包含1个字符————true 这段字符串是回文(i+2=j)
    3、包含超过1个字符————进一步判断 去头去尾之后的字符串是不是回文(j-i>2)
故而状态方程为：
dp[i][j]=dp[i+1][j-1]&&s[i]==s[j]
边界条件：j-i>2
初始条件：dp[x][x]=true;
//要注意dp[i][j]=dp[i+1][j-1]是从dp[i+1][j-1]来的，所以要首先确定dp[i+1][j-1]，那就意味着是从左下角的去确定右上角的，中间空着的可以直接由s[i]==?s[j]确定，所以要先确定左下角的，那么比如第j列，我们应该从下往上确定，也就是行数从i=j-1开始逐渐变小。

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        bool dp[n][n];
        for(int i=0; i<n; i++){
            dp[i][i]=true;
        }
        int maxlen=1, start=0;
        for(int j=1; j<n; j++){
            for(int i=j-1; i>=0; i--){
                if(s[i]==s[j]){
                    if(j-i<=2) dp[i][j]=true;
                    else dp[i][j]=dp[i+1][j-1];
                }
                else dp[i][j]=false;
                if(dp[i][j] && maxlen<j-i+1){
                    maxlen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
```