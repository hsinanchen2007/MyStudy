### 解题思路
此处撰写解题思路
![2.png](https://pic.leetcode-cn.com/e6bfb0f21fbd6c04a4cb8ddf467df5c6f4a17a1a220d83eb966b5a8511a8bf7b-2.png)

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        result = True
        try:
            int(s)
        except ValueError:
            try:
                float(s)
            except ValueError:
                result = False
            else:
                result = True
        else:
            result = True
        return result
```