方法1：尝试一种简单暴力
```
从haystack字符第j个开始遍历
neddle字符串和haystack第j个元素之后开始是否重合。

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle)==0:
            return 0
        if len(haystack)<len(needle):
            return -1

        for j in range(len(haystack)):
            if  haystack[j] != needle[0]:
                continue
            for i in range(len(needle)):
                if i+j>=len(haystack) or haystack[j+i] != needle[i]:
                    break
                elif i==(len(needle)-1):
                    return j
                else:
                    continue
        
        return -1
```
