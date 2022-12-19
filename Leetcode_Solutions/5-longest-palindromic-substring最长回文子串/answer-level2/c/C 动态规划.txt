
怎么没有中心扩散法快呢
### 解题思路
![image.png](https://pic.leetcode-cn.com/1e37f73052359c83f41346602ee9e18205fcbba308008fe1e3e404729ac64618-image.png)
此处撰写解题思路

### 代码

```c
// 动态规划 dynamic programming
char * longestPalindrome(char * s){  
    int n = strlen(s);
    if(n < 2) return s;
    int maxLen = 1;
    int start = 0;
    bool dp[n][n];
    // 一个字符长度的，都是true
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    for(int j = 1; j < n; j++){
        for(int i = 0; i < j; i++){
            if(s[j] == s[i]){
                if(j - i < 3){
                    dp[i][j] = true;// 2/3个字符长度的，可以直接判断
                }
                else{
                    dp[i][j] = dp[i + 1][j - 1];// 大于3个字符长度的根据前一个判断
                }
            }
            else{
                dp[i][j] = false;
            }
            if(dp[i][j]){
                int tmp = j - i + 1;
                if(tmp > maxLen){
                    maxLen = tmp;
                    start = i;
                }
            }
        }
    }
    s[start + maxLen] = '\0';
    return s + start;
}
    


```