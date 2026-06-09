### 解题思路
此题可以转换为 [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)， 把非公共子序列的字符都要删去。

类似习题 [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/), 留下来一个难题: 无法一眼看出当 w1[i]==w2[j], 一定是 DP[i][j]+1.

但这里比较好证明： DP[i+1][j+1] = max(DP[i][j]+1, DP[i+1][j], DP[i][j+1]).
然后注意到，DP[i+1][j] <= DP[i][j]+1 且 DP[i][j+1] <= DP[i][j]+1, 多增加一个元素，至多匹配个数多 1. 这个看上去就是对的，虽然严格证明比较绕。

上面证明过程不是很清晰，下面来分类讨论：
1. 若 DP[i+1][j] 对应的匹配结果中 w1[i] 没有匹配任何数，那么 DP[i][j] = DP[i+1][j]
2. 若 DP[i+1][j] 对应的匹配结果中 w1[i] 匹配到了 w2[k], 那么考虑 (w1[:i], w2[:j]) 现在少了字符 w1[i], 从 DP[i+1][j] 中删去 w1[i] 和 w2[k] 的匹配，构成了(w1[:i], w2[:j])一个可行的匹配结果，故 DP[i][j] >= DP[i+1][j]-1.


官方题解中提供了另外一种 DP 的思路，也就是直接用 DP[i][j] 代表 w1[:i] 到 w2[:j] 所需删除的数量，然后推导出递归方程，然后就可以求解。

对这个思路也是可以证明：当 w1[i] == w2[j] 时， DP[i+1][j+1] = DP[i][j] 的
同习题 [712. 两个字符串的最小ASCII删除和](https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings/solution/gelthin-dpguo-cheng-tan-xin-by-gelthin/)



### 代码

```python3
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 这个似乎可以转换为 最长公共子序列问题， 把非公共子序列的字符都要删去。
        # DP[i][j] 代表 word1[:i] 和 word2[:j] 的最长公共子序列

        m, n = len(word1), len(word2)
        DP = [[0 for j in range(n+1)] for i in range(m+1)]
        for i in range(m):
            for j in range(n):
                # if word1[i] == word2[j]:  # 无法一眼看出当 w1[i]==w2[j], 一定是 DP[i][j]+1
                #     DP[i+1][j+1] = DP[i][j] + 1
                # else:
                #     DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1])
                DP[i+1][j+1] = max(DP[i+1][j], DP[i][j+1])
                if word1[i] == word2[j]:
                    DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j]+1)
        return m+n - 2*DP[m][n]

```