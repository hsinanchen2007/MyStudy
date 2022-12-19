**思路分析：**
假设字符串的下标**从1开始**；使用dp[i][j]表示s的前i个字符和p的前j个字符是否匹配。考虑以下情况：
（1）s[i] == p[j]：此时只需要关注s的前i-1个字符和p的前j-1个字符是否匹配，一旦匹配了，那么s的前i个字符和p的前j个字符一定匹配，所以dp[i][j] = dp[i-1][j-1]；
（2）s[i] != p[j]，此时考虑以下情况：
① p[j] == '?'：由于问号可以消去一个字符，所以dp[i][j] = dp[i-1][j-1]；
② p[j] == '*'：此时又可以细分为以下情况：
- 用'*'消去s中的一个字符，即dp[i-1][j-1]
- 用'*'消去一个空字符串，即dp[i][j-1]
- 考虑s的前i-1个字符和p的前j个字符是否匹配，即dp[i-1][j]；如果匹配，即使s加上第i个字符也无所谓，因为'*'可以消去任意的字符串

所以此时dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j]

③其他情况下，dp[i][j] = 0，这里在数组初始化时完成就可以了

**注意考虑边界条件：**
- dp[0][0] = 1：空字符串能够相互匹配
- dp[i][0] = 0：如果s非空而p为空，肯定不匹配
- dp[0][i]：如果p[i]=='*'，那么dp[0][i]=1，因为一串连续的'*'相当于一个空字符串；一旦出现'*'以外的字符，那么在其后面所有的dp[0][i]都置为0，因为其后的子串不可能再等同于一个空字符了

**时空复杂度：**
时间复杂度O(mn)，空间复杂度O(mn)，m和n分别为两个字符串的长度

**参考代码：**
```
bool isMatch(char * s, char * p){
    int len_s = strlen(s), len_p = strlen(p);
    
    int** dp = (int**)malloc(sizeof(int*)*(len_s+1));
    for (int i = 0; i <= len_s; ++i){
        *(dp+i) = (int*)malloc(sizeof(int)*(len_p+1));
        memset(*(dp+i), 0, sizeof(int)*(len_p+1));
    }

    dp[0][0] = 1;
    for (int i = 1; i <= len_p; ++i){ // 考虑边界条件
        if (p[i-1] == '*')
            dp[0][i] = 1;
        else
            break;
    }

    for (int i = 1; i <= len_s; ++i){
        for (int j = 1; j <= len_p; ++j){
            if (s[i-1] == p[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                if (p[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
            }
        }
    }

    return dp[len_s][len_p];
}
```
