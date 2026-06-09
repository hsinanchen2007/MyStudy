看了好些都是使用的KMP等方法， 但是复杂度都是O(NM)，所以尝试了暴力破解，复杂度为O(N)
使用for循环时判断条件太多，还是使用while比较舒服。
```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if len(needle)>len(haystack):
            return -1
        #while 循环
        i=0
        while i < len(haystack)-len(needle)+1:
            if haystack[i:i+len(needle)]==needle:
                    return i
            else: i+=1

        #for 循环
        # for i in range(len(haystack)-len(needle)+1):
        #     if i+len(needle)<len(haystack):
        #         if haystack[i:i+len(needle)]==needle:
        #             return i
        #     elif i+len(needle)==len(haystack):
        #         if haystack[i:]==needle:
        #             return i
        #         else:return -1
        
        return -1
```
