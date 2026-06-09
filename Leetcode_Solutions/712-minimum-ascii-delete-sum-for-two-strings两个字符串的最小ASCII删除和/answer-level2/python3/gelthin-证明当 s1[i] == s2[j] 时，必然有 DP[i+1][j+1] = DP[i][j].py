### 解题思路
这一题就比 [583. 两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings/) 更有意思一点了。不单纯地考虑数量，还要考虑删去字符对应的 ASCII 值大小。但本质上，最后居然仍然是一样的。

+ 无法直接转换成最长公共子序列问题了，转换也是转为 “最大累计ASCII值公共子序列”。
+ 见讨论 [考虑DP[i][j] + ord(s1[i]) + ord(s2[j])](https://leetcode-cn.com/problems/delete-operation-for-two-strings/solution/liang-ge-zi-fu-chuan-de-shan-chu-cao-zuo-by-leetco/225028), 这里仍然不用考虑 DP[i][j] + ord(s1[i]) + ord(s2[j]), 这个仍然是会被考虑到 DP[i+1][j] 和 DP[i][j+1] 里面。

+ 在本题中，即使 s1[i] == s2[j], 似乎并不一定有 DP[i+1][j+1] = DP[i][j], 也许 DP[i][j+1] + ord(s1[i]) 或 DP[i+1][j] + ord(s2[j]) 会更小，因为现在不是单纯考虑个数累加 1 了。 
+ 但是官方题解，以及所有的测试样例都表明，当s1[i] == s2[j], 直接令 DP[i+1][j+1] = DP[i][j] 仍然正确。因此，我尝试去严格证明这个。

#### 下面证明，当 s1[i] == s2[j] 时，必然有  DP[i+1][j+1] = DP[i][j]
考虑到 DP[i+1][j+1] 的更新方式， 需要证明 DP[i][j] <= min(DP[i][j+1] + ord(s1[i]), DP[i+1][j] + ord(s2[j]))。

证明如下：

先证 DP[i][j] <= DP[i][j+1] + ord(s1[i]), 考虑 DP[i][j+1] 这一值对应的最优删除结果，
+ 1. 若在最优结果中 s2[j] 被删除了， 那么 DP[i][j+1] = DP[i][j] + ord(s2[j]), 自然有所需证的结果成立。
+ 2. 若在最优结果中 s2[j] 对应于 s1[k], 那么也就是 s1[k] == s2[j]. 考虑 DP[i][j], 由于缺少 s2[j], 故可以考虑在 DP[i][j+1] 的解的基础上，删去 s1[k] 和 s2[j] 对应关系，其构成了 DP[i][j] 的一个可行解，但不一定是最优解， 即有 DP[i][j] <= DP[i][j+1] + ord(s1[k]) = DP[i][j+1] + ord(s2[j]) = DP[i][j+1] + ord(s1[i]) (最后一步是由于 s1[i] == s2[j])
+ 3. 同理，可证 DP[i][j] <= DP[i+1][j] + ord(s2[j])


### 代码

```python3
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        # 这一题比起 [583. 两个字符串的删除操作] 就更有意思一些了
        # DP[i][j] 表示 s1[:i] 到 s2[:j] 所需的删除字符的 ASCII 值最小和
        m, n = len(s1), len(s2)
        DP = [[None for j in range(n+1)] for i in range(m+1)]
        
        # 初始化
        DP[0][0] = 0
        cum_s = 0
        for j in range(1, n+1):
            cum_s += ord(s2[j-1])
            DP[0][j] = cum_s
        cum_s = 0
        for i in range(1, m+1):
            cum_s += ord(s1[i-1])
            DP[i][0] = cum_s
        # DP 过程
        for i in range(1, m+1):
            for j in range(1, n+1):
                #DP[i][j] = min([DP[i-1][j] + ord(s1[i-1]), DP[i][j-1] + ord(s2[j-1]), DP[i-1][j-1]+ord(s1[i-1]) + ord(s2[j-1])])
                DP[i][j] = min(DP[i-1][j] + ord(s1[i-1]), DP[i][j-1] + ord(s2[j-1]))
                if s1[i-1] == s2[j-1]: # 如果相同，多一种考虑
                    DP[i][j] = min(DP[i][j], DP[i-1][j-1])
        return DP[m][n]
```