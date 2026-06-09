看到了大家写的DP似乎大多数都是用布尔类型，特别简洁，然后我就看不懂了 T^T, 于是自己写了个数字的，发现也可以，而且意外发现能够通过DP Table找到交错的路径，放出来给大家看一下。
```
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        int len1 = s1.size();
        int len2 = s2.size();
        int dp[len1+1][len2+1] = {0};
        memset(dp, 0, sizeof(dp));

        for(int i=0;i<=len1; i++) {
            for(int j=0;j<=len2; j++) {
                if(i+j==0)
                    dp[i][j] = 0;
                if(i == 0 && j>0){
                    if(s2[j-1]==s3[j-1]){
                        dp[0][j] = dp[0][j-1]+1;
                    }
                }
                if(j == 0 && i>0) {
                    if(s1[i-1]==s3[i-1]){
                        dp[i][0] = dp[i-1][0]+1;
                    }
                }
                if(i>0 && j>0)
                    if(s2[j-1]==s3[i+j-1]){  
                        if(s2[j-1] == s1[i-1])
                            dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]+1);
                        else
                            dp[i][j] = dp[i][j-1]+1;

                    } else if(s1[i-1]==s3[i+j-1]){
                        if(s2[j-1] == s1[i-1])
                            dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]+1);
                        else
                            dp[i][j] = dp[i-1][j]+1;
                    }
                
            }
        }
    }
};
```
这里把DP数组定义为了dp[i][j] 是 s1的前i个字符和s2的前j个字符能够组成最长的s3前缀的长度，最后判断dp[s1.length()][s2.length()]是否等于s3.length()。前面边界的处理很好理解，值得注意的是下面这一段：
```
if(i>0 && j>0)
    if(s2[j-1]==s3[i+j-1]){  
        if(s2[j-1] == s1[i-1])
            dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]+1);
        else
            dp[i][j] = dp[i][j-1]+1;

    } else if(s1[i-1]==s3[i+j-1]){
        if(s2[j-1] == s1[i-1])
            dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]+1);
        else
            dp[i][j] = dp[i-1][j]+1;
    }
```
一开始我没注意，WA了4，5次，后来发现需要对左边和上面的情况进行判断。如果s1[i] 和 s2[j] 都可以进行匹配，那肯定是选择一个最长的。但是不能直接这样取最大的选择，因为会漏掉某些错误的.如假设s3中存在重复的如 “aa”,这样的重复字符，而s1[j] 中的”a“在计算时就有可能被“滥用”，即用一个“a”，匹配了两个，这样就会使得某些错误的被误判为正确的。最后放上一个DP Table，大家有兴趣可以再写个DP输出下所有交错路径。
"aabcc"
"dbbca"
"aadbbcbcac"
```
0 0 0 0 0 0 
1 1 0 1 0 0 
2 3 4 5 6 0 
0 4 5 0 7 0 
0 0 6 7 8 9 
0 1 2 8 0 10 
```
