
**思路：用一个二维数组来记录每个位的最长重复长度**
动态方程应该是当 s[i] == s[j] 时 dp[i][j] = dp[i-1][j-1] + 1;
记录方式如下图,比如输入字符串为 "abcsabc" 时：


![image.png](https://pic.leetcode-cn.com/40d85bcfb3546d89f5a68493c4e99c6f4876a704f4682aba0d4bbc75a158a24f-image.png)



```

int longestRepeatingSubstring(char * s){
    if(s == NULL)return 0;
    int len = strlen(s);
    if(len <= 1)return 0;
    int max = 0;
    
    int **dp = (int**)malloc(sizeof(int*) * (len + 1));
    for(int i = 0; i < len; i++){
        dp[i] = (int*)malloc(sizeof(int) * (len + 1));
    }
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i < len; i++){
        if(s[0] == s[i]){
            dp[0][i] = 1;
        }
    }
    for(int i = 1; i < len; i++){
        if(s[0] == s[i]){
            dp[i][0] = 1;
        }
    }
    for(int i = 1; i < len; i++){
        for(int j = 1; j < len; j++){
            if(s[i] == s[j] && i != j){
                dp[i][j] = dp[i-1][j-1] + 1;
                max = max > dp[i][j] ? max : dp[i][j];
            }
        }
    }
    return max;
}
```



