### 解题思路
此处撰写解题思路
括号匹配，先进后出。注意特殊情况，如：判栈空等
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        s_l = ['(', '{', '[']
        s_r = [')', '}', ']']
        stack = []
        FLAG = True
        for idx, i in enumerate(s):
            try:
                l_idx = s_l.index(i)
                stack.append(l_idx)
            except ValueError:
                r_idx = s_r.index(i)
                if not len(stack):
                    FLAG = False
                    break
                else:
                    if stack.pop() != r_idx:
                        FLAG = False
                        break
        if len(stack):
            FLAG = False
        return FLAG
```