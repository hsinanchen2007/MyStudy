### 解题思路
没有剪枝，有些多余路径...

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0: return ['']
        s, result = '(', []
        self.parenthesis(s, n, result)
        return result


    def parenthesis(self, s, n, result):
        if len(s) == n * 2:
            if s.count('(') == s.count(')'):
                result.append(s)
            return

        if s.count('(') < s.count(')'):
            return
        self.parenthesis(s+'(', n, result)
        self.parenthesis(s+')', n, result)
```