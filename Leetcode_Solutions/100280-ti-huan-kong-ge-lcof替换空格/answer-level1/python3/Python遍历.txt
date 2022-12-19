### 解题思路
非空格则直接加入，空格则替换。

### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
        snew = ''
        for text in s:
            if text == ' ':
                snew += '%20'
            else:
                snew += text
        return snew
```