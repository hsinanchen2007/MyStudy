### 思路1：动态规划
&ensp;动态规划最重要的两部我认为就是明确**dp数组**的含义以及写出**状态转移方程**
$dp[i][j]$的含义是，字符串$s$的前$i$个字符和字符串$p$的前$j$个字符的匹配情况
&ensp;那么现在重点来了，如何写出状态转移方程
$$ dp[i][j]=\left\{
\begin{aligned}
dp[i-1][j-1] \quad①\\
dp[i][j-1] ||dp[i-1][j-1] \quad②
\end{aligned}
\right.
$$
$<1>$ 首先是当$s[i - 1] == p[j - 1] || p[j - 1] == '?'$时，也就是字符匹配或者p[j-1]为'?'通配，这时很显然直接有①式。
$<2>$ 重点是当p[j-1]为$*$时，有两种情况，第一种是$*$用做空字符串及相当于这个$*$没有了,也就有了②式的前部分dp[i][j-1]：前面的若是匹配上了，那就不管我目前这个$*$的事情了
$eg: abcd  和 abcd*$ 在这里前面四个都匹配上了，那我就可以当做空串直接匹配
第二种情况：用做很多个，这时候可能遇到的困难是考虑到$*$可能匹配多个字符串，因此我们只需要判断dp[i-1][j]是否匹配，因为$*$能匹配一切，因此只$*$在时**前面的匹配上了**，我$*$把话撂在这，我现在也能保证你现在还可匹配，为啥？ ：因为 $*$能匹配多个嘛
代码如下：
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector< vector<bool> > dp(n+1, vector<bool>(m+1, false)); dp[0][0] = true;

        // initialize 
        for (int i = 1; i <= m; ++ i){
            if(p[i - 1] == '*' && dp[0][i - 1]) dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];// ismatch, move on
                }else if (p[j - 1] == '*'){
                    bool zero, mul;// '*' act as zero, '*' act as multiple characters
                    zero = (j < m && s[i - 1] == p[j] && dp[i - 1][j - 1]) || dp[i][j - 1];
                    mul = dp[i -1][j];
                    dp[i][j] = zero || mul;
                }
            }
        }

        return dp[n][m];
    }
};
```
### 思路2： 贪心与双指针
其实在分析动态规划的时候我就觉得能用双指针做，只是当时有一个问题没有解决**如何表示\*匹配多个的情况呢**,考虑之后发现增加**回溯**的步骤即可
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, i_star = -1, j_star = -1, m = s.size(), n = p.size();
        
while (i < m){
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                ++ i, ++ j;// 指针同时往后自增1，表示匹配
            }else if (j < n && p[j] == '*') {// 记录回溯的位置
                i_star = i;// 记录星号
                j_star = j++;// 并且j移到下一位,准备下个循环s[i]和p[j]的匹配
                             //(也就是匹配0个字符)
            }else if (i_star >= 0) {// 发现字符不匹配且没有星号出现,但是istar>0 
                                   // 说明*匹配的字符数可能出错 回溯
                i = ++ i_star;//i回溯到i_star+1，显然匹配字符的量出错，现在多匹配一个，且自身加一
                j = j_star + 1;//j回溯到j_star+1 重新使用p串*后的部分开始对齐s串i_star
            } else return false;
        }
        while (j < n && p[j] == '*') ++ j;// 去除多余星号

        return j == n;
    }
};
```
