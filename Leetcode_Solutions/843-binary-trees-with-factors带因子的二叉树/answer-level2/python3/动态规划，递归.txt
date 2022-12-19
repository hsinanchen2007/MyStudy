### 解题思路
以每个值作为root节点，统计它的左右两个节点有多少种组成方式，
公式是：sum(left * right, 对于所有可能的left节点和right节点)
比如：
[2, 5, 10]
以10作为root节点，那么它有两种组成方式5，2或者2，5
2只有一种组成，5也只有一种，所以10的组成方式有 1\*1 + 1\*1 = 2, 加上10本身，一共有3个


### 代码

```python3
from functools import lru_cache
class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        set_A = set(A)
        MOD = 10**9+7

        @lru_cache(None)
        def ways(root):
            return 1 + sum(ways(num)*ways(root//num) for num in A if root % num == 0 and root//num in set_A) % MOD

        return sum(ways(num) for num in A) % MOD
```