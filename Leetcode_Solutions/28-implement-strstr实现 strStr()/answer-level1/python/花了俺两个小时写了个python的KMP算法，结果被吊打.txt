### 解题思路
先用getnext获得next列表，后面就是常规操作了

### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        def getnext(needle):
            _next=[0]*len(needle)
            i=0
            j=-1
            _next[0]=-1
            while i<len(_next)-1:
                if j==-1 or needle[i]==needle[j]:
                    i+=1
                    j+=1
                    _next[i]=j
                else:
                    j=_next[j]
            return _next
        
        if len(needle) > len(haystack):return -1
        if needle=="": return 0 
        _next=getnext(needle)
        # print(_next)
        i=0
        j=0
        while i<len(haystack) and j <len(needle):
            if j==-1 or haystack[i]==needle[j]:
                i+=1
                j+=1
            else:
                j=_next[j]
        return i-j if j==len(_next) else -1
        
        
        
```