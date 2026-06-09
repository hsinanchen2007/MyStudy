**题解：**
本题属于[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)的子题，求的就是**不为最长回文子序列的字符个数，所以我们只需要用字符串长度减去最长回文子序列的长度就是最少插入次数了**。

**思路：**
>* 动态规划
>
>* 状态dp[i][j]：表示s[i...j]的最大回文子序列长度
>
>* 状态转移方程：若`s[i]==s[j],则dp[i][j]=dp[i+1][j-1]+2`，**表示若s[i]==s[j]相等，那么它们俩的长度加上 s[i+1..j-1] 中的最长回文子序列就是 s[i..j] 的最长回文子序列**；若`s[i]!=s[j]，则dp[i][j]=max(dp[i][j-1],dp[i+1][j])`，**表示若s[i]!=s[j]，那么把它们两分别加入 s[i+1..j-1] 中，看看哪个子串产生的回文子序列更长即可**。
>
>* 注意：我们需要从后往前遍历，因为每一个dp[i][j]取决于它前面的最大回文子序列长度
>
>* 初始化：dp[i][i]=1，表示单个字符的回文长度为1

**代码如下：**
```cpp
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;--i){
            dp[i][i]=1;
            for(int j=i+1;j<n;++j){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[0][n-1];
    }
};
```


