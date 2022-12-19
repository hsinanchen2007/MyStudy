### 解题思路
动态规划
状态关系：dp[start][end] : 从起始到结束位置的回文字符个数
转移方程：dp[start][end] = dp[start + 1][end - 1] // 注意这里需要判断前一个的状态
初始状态：
dp[start][end] = 1 start == end // 1个字符
dp[start][end] = 2 end - start == 2 // 两个字符

### 代码

```c
#define MAXLEN 1000
#define PRINTF // printf
int countSubstrings(char * s){
    int iRetTot = 0;
    if (s == NULL) {
        goto END;
    }
    int len = strlen(s);
    if(len > MAXLEN) {
        goto END;
    }
    int dp[MAXLEN][MAXLEN] = {0};
    for(int end = 0; end < len; end++) { // 结束
        for(int start = 0; start <= end; start++) { // 开始
            if (s[start] != s[end]) { // 非环回特点
                dp[start][end] = 0;
                continue;
            }
            if ((start == end) || ((end - start) == 1)) { // 初始条件
                dp[start][end] = (end - start + 1);
                iRetTot++;
            } else if(dp[start + 1][end - 1] > 0){ // 异常等价类用例不通过
                dp[start][end] = dp[start + 1][end - 1] + 2;
                iRetTot++;
            } else { // 非环回
                dp[start][end] = 0;
            }
            PRINTF("%d %d %d %d\n",start, end, dp[start][end], iRetTot);
        }
    }
END:
    return iRetTot;
}
```