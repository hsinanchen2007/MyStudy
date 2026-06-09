![捕获.PNG](https://pic.leetcode-cn.com/9e4794fc33b78ebff3dcb1cd9ccec0e615e2405cfe333e430ab8c31eeb628ba9-%E6%8D%95%E8%8E%B7.PNG)

基本是按照官方题解的思路来的，然后就出现了这么迷的操作，**本地计算正确，传上去就出问题**

还望大神能解答哪里出问题了
```
int minValue(int a, int b, int c){
    return (a<b?a:b)>c?c:(a<b?a:b);
}

int dp[100][100] = {0};

int calculate(char * word1, char * word2, int add1, int add2){
    if(strlen(word1) == 0)  return strlen(word2);
    if(strlen(word2) == 0)  return strlen(word1);
    if(dp[add1+1][add2] == 0){
        dp[add1+1][add2] = calculate(word1+1, word2, add1+1, add2);
    }
    if(dp[add1][add2+1] == 0){
        dp[add1][add2+1] = calculate(word1, word2+1, add1, add2+1);
    }
    if(dp[add1+1][add2+1] == 0){
        dp[add1+1][add2+1] = calculate(word1+1, word2+1, add1+1, add2+1);
    }
    return minValue(dp[add1+1][add2]+1, dp[add1][add2+1]+1, dp[add1+1][add2+1]+(int)(word1[0] != word2[0]));
}


int minDistance(char * word1, char * word2){
    return calculate(word1, word2, 0, 0);
}
```