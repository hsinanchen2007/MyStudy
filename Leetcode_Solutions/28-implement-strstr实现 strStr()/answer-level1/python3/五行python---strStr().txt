
使用python自带的子串查询函数
直接返回子串首字母的index

```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0        
        if needle in haystack:
            return haystack.find(needle,0,len(haystack))
        else: return -1
```
