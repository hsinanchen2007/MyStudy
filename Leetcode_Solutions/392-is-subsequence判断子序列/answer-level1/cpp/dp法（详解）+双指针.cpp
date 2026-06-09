用的dp法做，先写一下dp法的思路：

两个字符串的问题，一般都是二维dp：

状态：s的前i个元素，t的前j个元素位置

dp数组含义：dp\[i][j]代表s的前i个元素是否为t的前j个元素的子序列，是则true，否则false

然后是状态转移方程：$$dp[i][j] = \begin{cases}dp[i - 1][j - 1]&s[i] = t[j]\\dp[i][j-1]&s[i]\neq t[j] \end{cases}$$

> 这里解释一下状态转移方程的得来：
>
> 当s[i] == t[j]时，这两个元素就不重要了，取决于dp\[i-1][j-1]是什么
>
> 当s[i] != t[j]时，那么t[j]就不重要了，取决于dp\[i][j-1]是什么

base case：

容易想到：

$dp[i][j] = false ,i>j$  这一条可以直接在二重循环中体现: `int j = i`

$dp[0][j] = true,j\in [0,n]$

转换为代码：

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));  //dp
        //base case
        for(int i = 0; i <= n; i++) {
            dp[0][i] = true;
        }
        for(int i  = 1; i <= m; i++) {
            for(int j = i; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) { //由于i-1即第i个
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
                if(i == m && dp[i][j] == true) return true;  //剪枝
            }
        }
        return dp[m][n];
    }
};
```

不过很可惜，会超时，哪怕我还做点了剪枝（对true情况有效），再怎么剪就不会了。。。

看了看大家的题解，基本都没有用dp做的。的确，dp是基于穷举的优化，自然不会快。

然后自己参考了一个双指针的做法，代码如下：

```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int i = 0, j = 0; 
        while(i < m && j < n) {
            if(s[i] != t[j]){
                j++;
            }else{
                i++, j++;
            }
        }
        if(i == m) return true;
        return false;
    }
};
```

