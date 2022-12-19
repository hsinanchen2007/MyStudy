### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:

        if haystack=="" and needle=="":
           return 0
        if haystack=="" and needle!="":
            return -1
        if haystack!="" and needle=="":
            return 0
        if len(haystack)<len(needle):
            return -1

        index=0
        haystack=list(haystack)
        needle=list(needle)
        while 1:
            if haystack[index:index+len(needle)]==needle:
                print(index)
                return index
            else:
                if index+len(needle)>len(haystack)-1:

                    return -1
                if haystack[index+len(needle)] not in needle:
                    index=index+len(needle)
                    
                else:
                    
                    index=index+1
                    if index+1>len(haystack)-1:
                        return -1
                    
```