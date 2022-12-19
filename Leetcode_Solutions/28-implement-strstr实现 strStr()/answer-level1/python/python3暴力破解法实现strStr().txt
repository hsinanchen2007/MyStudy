### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i,j,flag = 0,0,0
        while i<len(haystack) and j<len(needle):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                i = i-j+1
                j = 0
        if j == len(needle):
            return i-j
        else:
            return -1
        

```