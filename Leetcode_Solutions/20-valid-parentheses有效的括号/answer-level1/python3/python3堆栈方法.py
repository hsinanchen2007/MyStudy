### 解题思路
先定义好括号的映射用于检查是否对应，遍历字符串中的元素，如果是字典中的键（左括号），就压入堆栈，否则（是右括号）检查堆栈是否为空，如果非空则检查栈顶的括号是不是右括号对应的左括号，是则继续循环，否则返回False，遍历结束时检查栈是否为空，是则返回True，否则返回False。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        parentheses_map = {
            '(': ')',
            '[': ']',
            '{': '}'
        }
        parentheses_stack = []
        for x in s:
            if x in parentheses_map:
                parentheses_stack.append(x)
            else:
                if parentheses_stack:
                    if parentheses_map[parentheses_stack.pop()] == x:
                        continue
                    else:
                        return False
                else:
                    return False
        return not parentheses_stack
```