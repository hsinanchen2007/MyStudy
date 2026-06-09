### 解题思路
状态转移方程：
$$
dp[i][j] =
\begin{cases} dp[i-1][j-1]+1 & \text{s1[i]==s2[j]} \\
max(dp[i-1][j],dp[i][j-1])& \text{s1[i]!=s2[j]}
\end{cases}
$$

从上面看出，我们只参考状态`dp[i-1][j-1]`和`dp[i-1][j]`也就是上面一行的状态，但是可能会问，这里不是还有`dp[i][j-1]`，其状态明显是从左、上和左上转化过来的！

想要优化，那么就是用一个变量存`dp[i][j-1]`这个值，防止覆盖即可。

### 一维DP

```c []
#define max(a, b) ((a) > (b) ? (a) : (b))

int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1), len2 = strlen(text2);
    int *dp = (int *)calloc(len2 + 1, sizeof(int));  // 初始化0，即t1空串
    int prev, next;  // next:dp[i-1][j]随j参考后填充，然后prev记录next代表dp[i-1][j-1](且每行更新),
    for (int i = 1; i <= len1; i++) {
        prev = dp[0];  // 1.每行起始作为dp[i-1][j-1]
        for (int j = 1; j <= len2; j++) {
            next = dp[j];  // dp[i-1][j]:目的是j++后变成左上角dp[i-1][j-1]
            if (text1[i-1] == text2[j-1]) {
                // 两个相等+1，状态是dp[i-1][j-1]即prev
                dp[j] = prev + 1;
            } else {
                /* 两个不同，状态取决于两个之前dp[i][j-1]和dp[i-1][j]
                * 而dp[i][j-1]就是这里dp[j-1]先求出的值，那么dp[i+1][j]就是此时待更新的格
                * 由于这里更新后，下轮dp[j]就被覆盖，j+1无法参考预先左上角的值，所以上面next存着
                */
                dp[j] = max(dp[j], dp[j-1]);
            }
            prev = next;  // 最重要的！prev更新dp[i-1][j]，下轮就是左上角了
        }
    }
    return dp[len2];
}
```

### "滚动"数组
这里其实可以创建两层数组，然后取余实现滚动填充，但是更好的方法就是变量两两交换的方式。或者第二个数组一直创建，然后第一个去复制第二个。

1. 不停申请第二层数组
```python3 []
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1, len2 = len(text1), len(text2)
        dp1 = [0] * (len2 + 1)  # 第一数组，共len2+1列(其实初始化了text1为空串情况)
        for i in range(1, len1 + 1):
            dp2 = [0] * (len2 + 1)  # 第二数组，共len2+1列(进行当前填充)dp2[0]=0初始化了text2为空
            for j in range(1, len2 + 1):
                if text1[i-1] == text2[j-1]:
                    dp2[j] = dp1[j-1] + 1  # dp[i-1][j-1]左上角实现
                else:
                    dp2[j] = max(dp2[j-1], dp1[j])  # dp[i-1][j]:第一行数组储存的;dp[i][j-1]本数组
            dp1 = dp2  # 引用（后面dp1不用被gc)
        return dp1[-1]
```
2. 两两交换操作

```python3 []
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        len1, len2 = len(text1), len(text2)
        dp1 = [0] * (len2 + 1)  # 第一数组，共len2+1列(其实初始化了text1为空串情况)
        dp2 = [0] * (len2 + 1)  # 第二数组，共len2+1列(进行当前填充)dp2[0]=0初始化了text2为空
        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if text1[i-1] == text2[j-1]:
                    dp2[j] = dp1[j-1] + 1  # dp[i-1][j-1]左上角实现
                else:
                    dp2[j] = max(dp2[j-1], dp1[j])  # dp[i-1][j]:第一行数组储存的;dp[i][j-1]本数组
            dp1, dp2 = dp2, dp1  # 交换，行倒转填充(关键，相当于取余实现的二维数组滚动！)
        return dp1[-1]
```