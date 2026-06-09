一般来说，这种求**方案总数、最大值、最小值**的题目，十有八九是要用DP。

对于两个序列（字符串或者数组）S，T的DP题目，状态十有八九定义为`dp[i][j]`,表示用`S[0...i]`匹配`T[0...j]`的个数。

然后转移方程依据题目的要求进行变化。  
为了方便处理，我们在S和T的开始都添加一个空格，那么**真实字符串的下标是从1开始的**。

```
给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数.  
一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
```
对于DP来说，解决这类问题其实就是确定**状态、选择、base case**。  
状态已经设定好了，那么选择是什么呢？其实题目中也透露了：对S中的字符**删除或者不删除**。
$$
dp[i][j]=
 \begin{cases}
   dp[i-1][j] & S[i] != T[j] \\
   dp[i-1][j] + dp[i-1][j-1] & S[i]==T[j]
  \end{cases}
$$
解释：  
如果`S[i] ！= T[j]`，那么只能将S[i]删除，此时`d[i][j] = d[i-1][j]`;  
如果`S[i]==T[j]`，此时就可以删除，也可以不删除，分类讨论用加法也就是`dp[i][j] = dp[i-1][j] + dp[i-1][j-1]`

对于base base，其实就是`dp[i][0] = 1`,也就是任意的`S[0...i]`匹配`S[0...0]`（也就是空字符串）的个数是1，就是把`S[0...i]`所有的字符都删掉。

AC code:
```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        s.insert(s.begin(), ' ');
        t.insert(t.begin(), ' ');
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        for (int i = 0;i <= m;++i)
            dp[i][0] = 1;
        for (int i = 1;i <= m;++i)
        for (int j = 1;j <= n;++j){
            dp[i][j] = dp[i-1][j];
            if (s[i]==t[j]){
                dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
```