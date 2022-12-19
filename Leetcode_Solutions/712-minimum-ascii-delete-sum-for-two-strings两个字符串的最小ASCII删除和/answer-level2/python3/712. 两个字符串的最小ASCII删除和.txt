思路：
1. 这是一道比较简单的双序列动态规划的题。
2. 双序列DP通常开二维数组,f[i][j] 表示s1前i个字符和s2前j个字符最小删除和
3. 本题先考虑最后一步就是f[m][n]的最小值，m是s1的长度，n是s2的长度。观察s1的最后一个字符和s2的最后一个字符，有以下几种情况：1相同，那么f[m][n] = f[m-1][n-1]。2不相同：时就需要考虑是删除s1呢还是删除s2呢？删除的依据就是看看删除谁以后最小删除和更小。此时 f[m][n] = min(f[m-1][n]+ord(s1[m-1]),f[m][n-1]+ord(s2[n-1))。（ord是求取当前字符的ascii码）
4. 根据上面很容易的出转移方程：（一切不写出转移方程的动态规划都是在耍流氓）
![捕获.PNG](https://pic.leetcode-cn.com/56b6154e160a04c02aefd77979ee6ac5b2fc020f29ba3be3dfc2c43b54480441-%E6%8D%95%E8%8E%B7.PNG)


5. 初始条件f[0][j]为s2前j个字符对应的ascii码之和（0<=j<=n）。f[i][0]为s1前i个字符对应的ascii码之和（0<=i<=m）。计算顺序：i从小到大，j从小到大。二重循环即可。
6. 时间复杂度O（M * N）,空间复杂度O(M * N),空间复杂度可以优化成O（M）的，这里懒得写了。
## python3代码
```
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)
        f = [[0]*(n+1) for x in range(m+1)]
        for i in range(1,m+1):
            f[i][0] = f[i-1][0] + ord(s1[i-1])
        for j in range(1,n+1):
            f[0][j] = f[0][j-1] + ord(s2[j-1])
        for i in range(1,m+1):
            for j in range(1,n+1):
                if(s1[i-1] == s2[j-1]):
                    f[i][j] = f[i-1][j-1]
                else:
                    f[i][j] = min((f[i-1][j]+ord(s1[i-1])),(f[i][j-1] + ord(s2[j-1])))
        return f[-1][-1]
```