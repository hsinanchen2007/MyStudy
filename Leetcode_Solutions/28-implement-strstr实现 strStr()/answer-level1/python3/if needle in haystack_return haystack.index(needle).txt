### 解题思路
def strStr(self, haystack: str, needle: str) -> int:
        if needle and not haystack: return -1
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1

### 代码

```python3
# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:
#         res = -1
#         if not haystack and not needle:
#             return 0
        
#         j=len(needle)
#         for i in range(len(haystack)):
           
#             if haystack[i:i+j]==needle:
#                 return i
#         return res

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle and not haystack: return -1
        if needle in haystack:
            return haystack.index(needle)
        else:
            return -1
```