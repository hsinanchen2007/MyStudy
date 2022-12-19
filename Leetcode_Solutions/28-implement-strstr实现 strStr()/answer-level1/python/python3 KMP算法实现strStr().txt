### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        def getNext(needle):
            index, m = 0, len(needle)
            pnext = [0]*m
            i = 1
            while i < m:
                if (needle[i] == needle[index]):
                    pnext[i] = index + 1
                    index += 1
                    i += 1
                elif (index!=0):
                    index = pnext[index-1]
                else:
                    pnext[i] = 0
                    i += 1
            return pnext
        pnext = getNext(needle)
        i,j = 0,0
        while i<len(haystack) and j<len(needle):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
            elif j!=0:
                j = pnext[j-1]
            else:
                i += 1
        if j == len(needle):
            return i-j
        else:
            return -1

    


```