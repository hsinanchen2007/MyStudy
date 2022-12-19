### 解题思路
先用正则分割路径有用部分，然后依次循环用栈保存路径，最后合并路径即可

### 代码

```python3
import re

class Solution:
    def simplifyPath(self, path: str) -> str:
        pathAry = []
        for val in re.split(r'[\/]+', path):
            if val == "" or val == ".": continue
            if val == "..":
                if len(pathAry) > 0:
                    pathAry.pop()
            else:
                pathAry.append(val)
        return "/" + "/".join(pathAry)
```