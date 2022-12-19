### 解题思路
熟悉 find 和 index的区别就很好做了。。KMP实在手写不来

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
```