这是一道典型的最长公共子串问题，动态规划解法如下：

解法一：最简单的写法就如楼上“你现在拿到offer了吗”写的一样。\
__时间复杂度 O(m*n), 空间复杂度 O(m*n)__。\
用dp(i,j)表示以A[i]和B[j]为结尾的相同子串的最大长度,应该不难递推出dp[i, j]和dp[i+1,j+1]之间的关系，因为两者其实只差A[i+1]和B[j+1]这一对字符。若A那么[i+1]和B[j+1]不同，dp[i+1, j+1]自然应该是0，因为任何以它们为结尾的子串都不可能完全相同；而如果A[i+1]和B[j+1]相同，那么就只要在以A[i]和B[j]结尾的最长相同子串之后分别添上这两个字符即可，这样就可以让长度增加一位。\
合并上述两种情况，也就得到：状态转移方程如下：\
dp[i+1][j+1] = ( A[i+1] == B[j+1] ? (dp[i][j]+1) : 0 ); 
```java
public int findLength(int[] A, int[] B) {
    int m = A.length, n = B.length;
    if (m == 0 || n == 0) return 0;
    // 0的位置初始化为0，省的判断越界问题了
    int[][] dp = new int[m + 1][n + 1];
    int longest = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (A[i] != B[j]) {
                dp[i + 1][j + 1] = 0;
            } else {
                dp[i + 1][j + 1] = 1 + dp[i][j];
                longest = Math.max(longest, dp[i + 1][j + 1]);
            }
        }
    }
    return longest;
}
```


解法二：优化了一下空间复杂度，使用两行数组进行滚动。\
__时间复杂度 O(m*n), 空间复杂度 O(n)__。\
参考博文：https://www.cnblogs.com/ider/p/longest-common-substring-problem-optimization.html 
```java
public int findLength(int[] A, int[] B) {
    int m = A.length, n = B.length;
    if (m == 0 || n == 0) return 0;
    int[][] dp = new int[2][n];
    int longest = 0;
    for (int j = 0; j < n; j++) {
        if (A[0] == B[j]) {
            longest = 1;
            dp[0][j] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        // 这个地方使用上下滚动数组
        int cur = (i & 1) == 1 ? 1 : 0;
        int pre = (i & 1) == 0 ? 1 : 0;
        dp[cur][0] = 0;
        if (A[i] == B[0]) {
            dp[cur][0] = 1;
            longest = Math.max(longest, 1);
        }
        for (int j = 1; j < n; j++) {
            if (A[i] == B[j]) {
                dp[cur][j] = dp[pre][j - 1] + 1;
                longest = Math.max(longest, dp[cur][j]);
            } else {
                dp[cur][j] = 0;
            }
        }
    }
    return longest;
}
```