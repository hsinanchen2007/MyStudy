### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle is None:
            return 0
        
        if needle in haystack:
            x = haystack.find(needle)
            return x
        else:
            return -1
            
```