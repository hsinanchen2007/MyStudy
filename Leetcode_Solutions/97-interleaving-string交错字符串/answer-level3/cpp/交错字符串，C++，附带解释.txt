
``` c++
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /* 基本原理：已知前面的都匹配了，那么这一位是否匹配，取决于上一位是否匹配（也就是i-1或j-1）
         *          如果有匹配，那么就看这一位是否匹配
         * 状态方程：dp[i][j] = dp[i-1][j] && s1[i] == s3[i+j-1]    ||    dp[i][j-1] && s2[j] == s3[i+j-1]
         * 初始条件：dp[0][0] = true
         * 边界情况：i = 0 || j = 0 提前处理即可
         */
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1+len2!=len3) return false;
        s1 = "#" + s1;
        s2 = "#" + s2; //加个井号要么还需要处理某个s为空
        vector<vector<bool>> V(len1+1,vector<bool>(len2+1,false));//动态规划矩阵
        V[0][0] = true;
        for(int i = 1; i<=len1;i++) V[i][0] = s3[i-1] == s1[i] && V[i-1][0]; //处理第一行
        for(int j = 1; j <= len2; j++) V[0][j] = s3[j-1] == s2[j] && V[0][j-1];//处理第一列
        for(int i= 1; i<=len1;i++){
            for(int j = 1; j<=len2;j++){//每一个单位的值取决于左边或者右边
                V[i][j] = s3[i + j - 1] == s1[i] && V[i-1][j] || s3[i + j - 1] == s2[j] && V[i][j-1];
            }
        }
        return V[len1][len2];
    }
};
```
