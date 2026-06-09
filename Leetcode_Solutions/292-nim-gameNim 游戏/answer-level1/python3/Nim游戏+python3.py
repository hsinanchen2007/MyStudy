递归不行，dp也不行，结果......
```
class Solution:
    def canWinNim(self, n: int) -> bool:
        return not(n%4==0)
```

如果动态规划的话(递归类似)，dp的公式可以表示为：

**`dp[i] = not dp[i-1] or not dp[i-2] or not dp[i-3]`**

因为题目假设的是都在最好的状态下进行游戏的，因此如果要输的话，则从一开始的话，每一步都应该是False，所以如果当前i为真的话，则i-1,i-2,i-3一定有一个假的；如果当前i为假，则i-1，i-2，i-3都为真!