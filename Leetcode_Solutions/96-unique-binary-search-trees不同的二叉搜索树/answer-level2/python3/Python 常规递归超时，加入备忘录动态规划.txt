### 解题思路

[1, n] 的每个值都可以用来做根节点，则计算左边搜索树的总数乘以右边搜索树总数，全部相加即可

### 代码

```python3
class Solution:
    def __init__(self):
        self.memo = {0: 1, 1: 1, 2: 2}
    def numTrees(self, n: int) -> int:
        if n not in self.memo:
            self.memo[n] = sum(self.numTrees(left) * self.numTrees(n-left-1) for left in range(0, n))
        return self.memo[n]

```