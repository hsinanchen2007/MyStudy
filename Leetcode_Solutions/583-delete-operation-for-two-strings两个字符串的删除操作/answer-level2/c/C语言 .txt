```
/*
 * 算法思想：
 * 动态规划解编辑距离问题，与题目  712. 两个字符串的最小ASCII删除和
 * 本题中dp[i][j]表示s1匹配到i位置，s2匹配到j位置时候的最小结果。
 * Notes：
 * 1. dp[0][index]表示当s1为空串时，和s2进行匹配的结果；
 * 2. dp[index][0]表示当s2为空串时，和s2进行匹配的结果；
 * 3. 当匹配到i，j位置时，有以下几种情况：
 *   1> s1[i-1] == s2[j-1],此时表示当前所需匹配的两个字符相等，则 dp[i][j] = dp[i-1][j-1];
 *   2> s1[i-1] != s2[j-1],此时表示当前所需匹配的两个字符不相等，则需要看需要删除哪个，有以下几种方案：(选最优方案，即最小方案即可)
 *        a) tmp1 = dp[i-1][j-1] + 2;表示两个均删除，加上前面已经匹配的dp[i-1][j-1];
          b) tmp2 = dp[i-1][j] + 1; 表示删除s1字符串中的s1[i-1],前面已经匹配的为dp[i-1][j];
          c) tmp3 = dp[i][j-1] + 1; 表示删除s1字符串中的s2[j-1],前面已经匹配的为dp[i][j-1];
          d)上面三种取最小即可；
     3> 注意，当i==len1， j==len2时，表示匹配到两个字符串结尾，最后一个字符均为'\0'。
 **/


int min(int a, int b){
    return a>b  ?  b :a;
}
int max(int a, int b){
    return a> b ? a:b;
}

int minDistance(char * s1, char * s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    int i, j, tmp1, tmp2, tmp3;
    if(!len2) return len1;
    if(!len1) return len2;
    
    int dp[len1+1][len2+1];
    for(i=0; i<=len2; i++){
        dp[0][i] = i;   
    }    
    for(i=0; i<=len1; i++){
        dp[i][0] = i;
    }
    
    for(i=1; i<=len1; i++){
        for(j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }else{
                 tmp1 = dp[i-1][j-1] + 2;
                 tmp2 = dp[i-1][j] + 1;
                 tmp3 = dp[i][j-1] + 1;
                dp[i][j] = min(min(tmp1, tmp2), tmp3); 
            }
        }
    }    
   
    return dp[len1][len2];
}