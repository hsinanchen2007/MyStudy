### 解题思路
1、处理特殊情况：needle=“”，返回0
2、使用Python字符串的find()函数返回needle字符串位置

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        return haystack.find(needle)
```