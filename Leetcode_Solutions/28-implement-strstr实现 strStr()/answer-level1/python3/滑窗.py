### 解题思路
滑窗从前往后遍历haystack

### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        n = len(haystack)
        m = len(needle)
        if m == 0: return 0
        exsist = 0
        for i in range(n-m+1):
            if haystack[i:i+m] == needle:
                return i
    
        return -1


```