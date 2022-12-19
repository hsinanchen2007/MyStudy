# 思路
    采用动态规划的思想，申请一个二维数组dp[i][j],表示由i 到 j的最长回文子串的个数。
        第一步，初始化，毫无疑问，每个字符本身就是一个回文子串，长度为1，于是dp[i][i]=1。
        第二步，开始算每一中情况的最长回文子序列，dp[i][j]的值按如下得到
                    如果s[i] == s[j],  那么dp[i][j] = dp[i-1][j-1] + 2;
                    如果s[i] != s[j],  那么dp[i][j] = max{dp[i+1][j], dp[i][j-1]}
        第三步，dp[0][length-1],表示下表从0到length-1的字符串的最长子序列，就是结果。
        第四步，释放所申请的空间
        第五步，嘿嘿，愣着干嘛，赶紧总结写题解呀。
# 代码
```
int longestPalindromeSubseq(char * s){
    int length = 0;
    int i = 0;
    int j = 0;
    int result = 0;
    for (length = 0; s[length]; length++);
    // 申请空间
    int **dp = (int **)calloc(length, sizeof(int*));
    for (i = 0; i < length; i++) {
        dp[i] = (int *)calloc(length, sizeof(int));
    }
    
    for (i = 0; i < length; i++) {
        dp[i][i] = 1;   
    }
    
    for (i = 1; i < length; i++) {
        for (j = i-1; j >= 0; j--) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i-1][j+1] + 2;
            } else {
                dp[i][j] = dp[i-1][j] > dp[i][j+1] ? dp[i-1][j] : dp[i][j+1];
            }
        }
    }
    result = dp[length-1][0];

    // 释放空间
    for (i = 0; i < length; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return result;
}
```
注意：上面代码中的dp[i][j]含义是从j到i的最长回文子序列的个数，但是原理和上面是一样的

