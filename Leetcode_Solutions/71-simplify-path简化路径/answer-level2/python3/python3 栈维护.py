### 解题思路
栈维护

### 代码

```python3
class Solution:
    def simplifyPath(self, path: str) -> str:
        tmp = path.split("/")
        stack = []
        for i in tmp:
            if i == '.' or i=='':
                continue
            elif i=='..':
                if len(stack)!=0:
                    stack.pop()
            else:
                stack.append(i)
        res = ""
        for i in stack:
            res+='/'+i
        if len(res)==0:
            return '/'
        return res
```