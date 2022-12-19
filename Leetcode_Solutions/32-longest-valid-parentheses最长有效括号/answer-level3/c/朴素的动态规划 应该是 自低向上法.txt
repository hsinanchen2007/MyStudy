### 解题思路
朴素的动态规划 应该是 自低向上法 寻找最规模的子问题来解答
参考了官方题解动态规划的想法
首先思路是，假定当前 s[i] 是‘）’  才有可能 从i往前组成一个有效串，
因此我们的最小规模子问题就从 s[i] 往前看一个 s[i - 1]
1. 如果 s[i - 1]是‘（’， 那么我们记以 s[i-2] 中元素为结尾的有效串长为dp[i - 2]
   那么最终的dp[i] = dp[i - 2] + 2, 当前要考虑下 i - 2 < 0 的情景， 此时直接就是dp[i] = 0 + 2
2. 如果 s[i - 1]是‘）’， 那这个会稍微麻烦点， 那我们从s[i - 1]往串首看， 如果 dp[i - 1]的长度是 a的话
   那么如果 s[i - a - 1]是‘（’的话，那么其实 长度为dp[i - 1]的这个有效串是包在一个（）里面的， 如下图示：
          （                （）（）（）（）      ）
   s[i - dp[i - 1] - 1]        dp[i - 1]        s[i]
   上图的 dp[i] = 2 + dp[i - 1]
   当然如果 s[i - dp[i - 1] - 1] 的前面还有连续的有效串可以组合起来的话我们也要加起来， 例如下图：
        （()(())）                    （                （）（）（）（）      ）   
   dp[i - dp[i - 1] - 2]    s[i - dp[i - 1] - 1]          dp[i - 1]        s[i]
   那么此时的 dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2]
   当然如果 i - dp[i - 1] - 2 < 0 的话，就回归到 dp[i] = 2 + dp[i - 1] 的情况了

对上面1,2描述的情况从 i = 1开始遍历到字符串结束，区dp[i] 的最大值，就可以获得答案了
### 代码

```c
/* 尝试动态规划 */

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int longestValidParentheses(char * s)
{
    int len, i;
    int *dp = NULL;
    int valid_len = 0;

    len = strlen(s);
    dp = (int *)calloc(1, (1 + len) * sizeof(int));

    for (i = 1; i < len; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                if (i - 2 >= 0){
                    dp[i] = dp[i - 2] + 2;
                } else {
                    dp[i] = 0 + 2;
                }
            } else if (s[i - 1] == ')') {
                if ((i - dp[i - 1] - 1 >= 0) && (s[i - dp[i - 1] - 1] == '(')) {
                    if (i - dp[i - 1] - 2 >= 0) {
                        dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
                    } else {
                        dp[i] = 0 + dp[i - 1] + 2;
                    }
                }
            }
        }
        valid_len = max(dp[i], valid_len);
    }

    return valid_len;
}
