### 解题思路
起初我想试试str.index()传参能否传入复数字节，后来成功了

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1
```