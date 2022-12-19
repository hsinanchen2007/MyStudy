在不进行太多优化的情况下，可以战胜 96.88 % 的 python3 提交记录，:)

## 1. 使用DP获取最少删除数
假设字符串的长度为N。

首先我们可以通过O(N^2)时间和空间复杂度得到最少需要删除多少个无效括号。使用一个(N+1) * (N+1)的矩阵M， 其中M[i, j]代表的是当s[: i]子串中多出来的"("为j个时，s[i: ]最少需要删除多少个字符才能满足整个字符串的合法性。

M[i, j]的递推关系如下：

`M[i, j] = min(M_no[i, j], 1 + M_del[i, j])`

其中M_no[i, j]指不删除s[i]字符时所需的操作数：
- 当s[i] 为 ( 时，留给s[i+1, :]的 ( 多了一个，所以j + 1,  `M_no[i, j] = M[i + 1, j + 1]`
- 当s[i] 为 ) 时，如果s[:i]中已经没有多余的左括号，是必须要删掉s[i]的，所以 `M_no[i, j] = M[i + 1, j - 1] if j > 0 else Inf`
- 当s[i] 为其他字符时，j不变 `M_no[i, j] = M[i + 1, j]`

m_del[i, j]指删除s[i]后所需的操作数：
- 当s[i] 为 ( 或 )时，删掉该字符不影响j，`M_del[i, j] = M[i + 1, j]`
- 当s[i] 为其他字符时，不能删掉该字符，`M_del[i, j] = Inf`

初始化该矩阵最后一行为Inf, 除了 `M[N, 0] = 0`，即当左侧剩余的(为0时，空字符串不需要任何操作，当左侧剩余 (不为0时，空字符串无论如何也不能合法。
接下来从N-1 到 0进行遍历，按照上述公式更新M[i, j]， 更新完毕后M[0, 0]就是整个字符串的最少删除数。

## 2. 回溯找到最优路径
本题需要我们给出最少删除操作后剩余的字符串，所以我们在得到最优解后，还需要通过回溯的方法从M[0, 0]开始找到最优路径，且知道在该路径上每个位置时，是否应该删掉字符。
我们可以以M[0, 0]为根结点进行深度优先搜索，在每个位置重新计算M_no和M_del, 如果`M_no < M_del`, 说明在该位置无需删除字符，反之则需要删除，且当`M_no == M_del`时，需要分别搜索删除和不删除两个叶子路径。在实现过程中为了方便，我使用了一个新的矩阵在DP遍历时存储最优操作。

DP遍历的时间复杂度为O(N^2), 空间复杂度为O(N^2), 由于我们需要找到所有的路径，所以回溯过程的最差时间复杂度为O(2^N)，即最优路径上每个节点删除和非删除都是最优操作，当然这种情况比较难发生。

```
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        if not s:
            return [""]
        n = len(s)
        # save the min del nums
        md = [[float('inf')] * (n + 1) for _ in range(n+1)] 
        md[n][0] = 0 # the md for empty string is 0 only when no ( left  
        # save the operation: 1 for deletion, 2 for nothing, 3 for both
        md_op = [[0] * (n + 1) for _ in range(n+1)] 

        # build dp matrix
        for i in range(n-1, -1, -1):
            for left in range(0, i + 1):
                # perform del
                num_d = 1 + md[i+1][left] if s[i] in ['(', ')'] else float('inf')
                # no del
                if s[i] == '(':
                    num_n = md[i + 1][left + 1]
                elif s[i] == ')':
                    if left - 1 < 0:
                        num_n = float('inf')
                    else:
                        num_n = md[i + 1][left - 1]
                else:
                    num_n = md[i + 1][left]

                md[i][left] = min(num_d, num_n)
                # record opertion
                if num_d < num_n:
                    md_op[i][left] = 1
                elif num_d > num_n:
                    md_op[i][left] = 2
                else:
                    md_op[i][left] = 3
        # backtrack
        result = set()
        def dfs(i, j, r):
            if i == n:
                result.add(r)
                return
            if md_op[i][j] in [2, 3]:
                if s[i] == "(":
                    dfs(i+1, j+1, r + s[i])
                elif s[i] == ")":
                    if j - 1 >= 0:
                        dfs(i+1, j-1, r + s[i])
                else:
                    dfs(i+1, j, r + s[i])
            if md_op[i][j] in [1, 3]:
                dfs(i+1, j, r)
        dfs(0, 0, "")
        return list(result)
```


