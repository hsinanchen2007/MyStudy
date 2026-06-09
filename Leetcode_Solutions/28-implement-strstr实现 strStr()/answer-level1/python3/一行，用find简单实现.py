### 解题思路
此处撰写解题思路
在find函数中若没有查到对应返回值就是-1不需要重新判断。
### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
```