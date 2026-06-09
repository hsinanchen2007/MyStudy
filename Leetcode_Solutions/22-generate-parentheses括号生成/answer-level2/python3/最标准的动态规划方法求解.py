### 解题思路
没有采用任何递归或者简化，就是最标准的动态规划方法。
状态s[i][j]的含义是：具有i个')'和j个'('所能组成的符合要求的字符串。
s[i][j]必然由s[i-1][j]和s[i][j-1]转移过来。
从i-1到i，增加了一个')'，将它放在字符串的最后。
从j-1到j，增加了一个'('，将它放在字符串的最后。
需要注意的是只计算状态矩阵的上三角，因为下三角)比(多，显然是不对的。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return []
        ans = [[0]*(n+1) for i in range(n+1)]
        for i in range(n+1):
            for j in range(i,n+1):
                if j-1>=i:
                    if ans[i][j-1] != 0:
                        ans[i][j] = [s+'(' for s in ans[i][j-1]]
                    else:
                        ans[i][j] = ['(']
                if i-1>=0:
                    if ans[i-1][j] != 0:
                        if ans[i][j] != 0:
                            ans[i][j] += [s+')' for s in ans[i-1][j]]
                        else:
                            ans[i][j] = [s+')' for s in ans[i-1][j]]
                        
        return ans[-1][-1]
```