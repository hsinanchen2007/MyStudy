### 解题思路
栈是最正宗解法
正则试过了，感觉不行，如果有大佬指点，感激不尽
其他花哨的比如翻转之类的，其实还是在使用栈的思想
只能想到这些了

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        dict = {")": "(", "}": "{", "]": "["}
        for char in s:
            if char in dict:
                if stack:
                    top=stack.pop()
                    if top!=dict[char]:
                        return False
                else:
                   return False
            else:
                stack.append(char)
        return not stack

```