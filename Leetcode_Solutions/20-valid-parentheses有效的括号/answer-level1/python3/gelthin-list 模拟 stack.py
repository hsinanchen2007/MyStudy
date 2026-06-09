### 解题思路
用了 python list 的功能 pop() append()  来模拟了 stack 

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair = {')':'(', '}':'{', ']':'['}
        for x in s:
            if x == '(' or x =='{' or x=='[':
                stack.append(x)
            elif x == ')' or x =='}' or x==']':  # 题目中要求只包含，其实这里直接用 else 即可
                if len(stack) == 0 or pair[x] != stack.pop():
                    return False
            else:
                pass
        if len(stack)>0:
            return False
        else:
            return True
```