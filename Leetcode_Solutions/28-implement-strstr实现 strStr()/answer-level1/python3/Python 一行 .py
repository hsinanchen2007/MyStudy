### 解题思路
1. 使用布尔类型判断并转换needle的值为int，若为False则int()成0，返回；
2. 若needle非空则执行and后的 haystack.find(needle) ，若存在则返回下标，否则返回-1。

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
               return  int(bool(needle)) and haystack.find(needle)
```