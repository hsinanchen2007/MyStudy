### 解题思路
先判断是不是空,是空就返回0
再判断needle在不在haystack里面 不在就返回-1
在的话就把haystack按照needle拆分. 
因为只要第一个开始的位置,所以返回拆分之后列表的第0个字符长度即可.

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle.strip()) == 0:
            return 0
        else:
            if needle in haystack:
                return len(haystack.split(needle)[0])
            else:
                return -1

```