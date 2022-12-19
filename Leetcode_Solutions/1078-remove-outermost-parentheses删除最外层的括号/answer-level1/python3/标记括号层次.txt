执行用时 :48 ms, 在所有 Python3 提交中击败了96.12%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.61%的用户
```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        mark = 0
        stack = []
        for s in S:
            if s == '(':
                if mark != 0:
                    stack.append(s)
                mark += 1
            if s == ')':
                mark -= 1
                if mark != 0:
                    stack.append(s)
        return ''.join(stack)
```
