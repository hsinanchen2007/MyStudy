### 解题思路
此处撰写解题思路

### 代码

```python3
from functools import lru_cache
class Solution:
    @lru_cache()
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']
        return [f'({x}){y}' for c in range(n) for x in self.generateParenthesis(c) for y in self.generateParenthesis(n-1-c)]

```