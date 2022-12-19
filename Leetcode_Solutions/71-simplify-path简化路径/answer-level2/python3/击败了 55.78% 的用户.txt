### 解题思路
此处撰写解题思路
利用栈
### 代码

```python3
class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = path.split("/")
        stack = []
        for item in path_list:
            if item in ("", "."):
                continue
            elif item == "..":
                if  stack:
                    stack.pop()
            else:
                stack.append(item)
        return "/" + "/".join(stack)
```