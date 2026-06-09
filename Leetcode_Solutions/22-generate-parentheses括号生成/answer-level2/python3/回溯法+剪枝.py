每次递归深入都有两种选择，一种是添加'('，另一种是添加')'，如果不是有效串，回溯，否则继续深入，直到串的长度为2n。这里的有效串是指还允许往里添加括号
```python3
class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        def isValid(stack, cl, cr):
            if cl > n: return False
            elif cl < cr and stack[-1] == ')': return False
            elif len(stack) > n*2: return False
            return True
            pass
        # cl是左括号数，cr为右括号数
        def generate(stack, cl, cr):
            if not isValid(stack, cl, cr):
                return
            if isValid(stack, cl, cr) and len(stack) == 2*n:
                result.append(stack)
                return
            generate(stack+'(', cl+1, cr)
            generate(stack+')', cl, cr+1)
        generate('', 0, 0)
        return result
```
