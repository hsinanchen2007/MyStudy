### 解题思路
递归深度优先

### 代码

```python3
class Solution:
    def __init__(self):
        self.res = []
        self.n = 0

    def generateParenthesis(self, n: int) -> List[str]:
        if n < 1:
            return []
        self.n = n
        self.generate('', 0, 0)
        return self.res

    def generate(self, string, l_count, r_count):
        if l_count < r_count:
            return
        if l_count == self.n and r_count == self.n:
            self.res.append(string)
        elif self.n > l_count > r_count:
            self.generate(string+'(', l_count+1, r_count)
            self.generate(string+')', l_count, r_count+1)
        elif self.n > l_count == r_count:
            self.generate(string + '(', l_count+1, r_count)
        elif l_count == self.n:
            self.generate(string+')', l_count, r_count+1)
        elif r_count == self.n:
            self.generate(string + '(', l_count+1, r_count)
```