### 解题思路
DFS

1. 每次生成左括号或右括号，直到括号数小于或等于2n
2. 每次生成需要满足右括号数量小于左括号数量，且左括号数量小于n


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.res = []
        self.max_level = 2 * n
        self.dfs(0, 0, 0, '')
        return self.res

    def dfs(self, level: int, left: int, right: int, s: str) -> str:
        if level >= self.max_level:
            self.res.append(s)
        if left < self.max_level >> 1:
            self.dfs(level + 1, left + 1, right, s + '(')
        if right < left:
            self.dfs(level + 1, left, right + 1, s + ')')

```