### 解题思路
路径以”/“分割后，判断目录的几种情况：
1. .，当前目录不需要压栈
2. ..，栈弹出元素，如果栈只剩下根目录，则无需弹出元素
3. 正常，栈压入元素
4. 空，为空是因为有double slash， 不需要对栈任何操作

### 代码

```python3
import os
import re


class Solution:
    def simplifyPath(self, path: str) -> str:
        dirs = path.split(f'{os.sep}')
        stack = ["/"]
        for directory in dirs:
            if not directory:
                continue
            if re.search(rf'^\.\.$', directory):
                if len(stack) > 1:
                    stack.pop()
                continue
            if re.search(rf'^\.$', directory):
                continue
            stack.append(directory)
        return f"{stack[0]}{f'{os.sep}'.join(stack[1:])}"

```