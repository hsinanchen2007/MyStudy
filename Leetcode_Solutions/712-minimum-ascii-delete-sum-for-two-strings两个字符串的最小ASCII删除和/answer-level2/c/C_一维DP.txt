### 解题思路
思路同1143和删除操作那题一模一样！优化Dp空间到O(1)代码可读性可能没有二维好。

### 代码

```c
#define min(a, b) ((a) > (b) ? (b) : (a))

int minimumDeleteSum(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    int *dp = (int *)malloc(sizeof(int) * (len2 + 1));
    int i, j, prev, next;
    // 1.base case:初始化s1为空的情况
    dp[0] = 0;
    for (j = 1; j <= len2; j++) {
        dp[j] = dp[j-1] + s2[j-1];
    }
    /* 状态转移方程
    * s[i]=t[j]:dp[i][j]=dp[i-1][j-1](不删除)
    * s[i]!=t[j]:dp[i][j]=max(dp[i-1][j], dp[i][j-1]) 任意删除其中一个
    */
    for (i = 1; i <= len1; i++) {
        prev = dp[0];  // 获得左上角的值
        dp[0] += s1[i-1];  // 初始化s2为空情况(累加！)
        for (j = 1; j <= len2; j++) {
            next = dp[j];  // 保存此时下轮变成左上角的值
            if (s1[i-1] != s2[j-1]) {
                /* 左和上参考最小的+此时到底删除谁的ASCII码
                * 左：就是删除s2[j-1]，因此需要加上自己ASCII
                * 上：就是上次尚未覆盖，删除s1[i-1]+s1[i-1]
                */
                dp[j] = min(dp[j] + s1[i-1], dp[j-1] + s2[j-1]);
            } else dp[j] = prev;  // 不删除：左上角参考
            // 更新prev=next使得下次prev是左上角的值
            prev = next;
        }
    }
    return dp[len2];
}
```