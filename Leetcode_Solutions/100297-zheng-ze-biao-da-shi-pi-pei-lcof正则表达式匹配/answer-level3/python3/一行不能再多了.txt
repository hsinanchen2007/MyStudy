### 解题思路
使用python的正则表达式

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return True if re.match("^"+p+"$",s) else False

```