### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        map = {')': '(', ']': '[', '}': '{'}
        t = []
        for i in s:
            if i not in map:
                t.append(i)
            elif not t or map[i] != t.pop():
                return False
        return not t


```

第一个元素必须是左括号，否则不是有效的括号。
是左括号都压入栈
是右括号，则判断栈顶元素是否与此右括号匹配，同时将栈顶元素弹出，
如果不匹配则说明不是有效的括号。如果匹配则继续匹配下一个元素，直到栈为空。
如果栈最后不为空，则说明不是有效的括号


