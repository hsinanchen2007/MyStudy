### 解题思路
本题的关键在于如何基于ways[0], ways[1], ..., ways[k-1]的基础上推导出ways[k]，具体如代码中的解释；
另外，[@windliang](/u/windliang/)的题解[解法三](https://leetcode-cn.com/problems/palindrome-partitioning-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-3-8/)中所列出的中心扩展法。

### 代码

```python3
class Solution:
    """
    1. 计算dp表：dp[i][j]：表示字符串s[i,j+1]是否为回文串；
    2. list ways[i]表示字符串s[:i+1]的最小分割数，显然ways[0] = 0; 
    3. 若ways[:k]已知，则可以求ways[k+1]，即字符串s[:k+1]的最小分割数：遍历i=range(k+1)并判断dp[i][k+1]==1，若是则分割数可为ways[i-1]+1，在遍历的过程中保存计算过程中的最小值即为ways[k+1]的值；
    4. 通过归纳总结逐步计算到ways[row-1]即为字符串s的最小分割数；
    """
    def minCut(self, s: str) -> int:
        # 检查输入参数的有效性
        row = len(s)
        if row == 0 or row == 1:
            return 0
        
        # 计算dp表: dp[i][j]=1表示字符串s[i,j+1]为回文串
        dp = [[0]*row for _ in range(row)]
        for j in range(row):
            for i in range(j, -1, -1):
                if j - i == 0:
                    dp[i][j] = 1
                elif j - i == 1 and s[i] == s[j]:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i+1][j-1] and (s[i] == s[j])
        
        # ways[i]表示s[:i+1]最小分割数；
        ways = [float('inf')]*row
        # 遍历整个字符串s，分别计算出ways[0],ways[1],...,ways[row-1]的值
        for i in range(row):
            for j in range(i, -1, -1):
                if dp[j][i] == 1 and (j-1<0 or ways[j-1]+1<ways[i]):
                    if j-1 < 0:
                        ways[i] = 0
                    else:
                        ways[i] = ways[j-1]+1
        return ways[row-1]
```