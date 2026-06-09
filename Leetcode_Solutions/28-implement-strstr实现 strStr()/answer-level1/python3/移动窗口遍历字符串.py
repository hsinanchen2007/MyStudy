### 解题思路
在遍历时分成两种情况，当haystack的长度小于needle的长度，直接返回-1，当haystack的长度大于等于needle的长度则利用滑动窗口遍历，遍历时i的范围为haystack的长度减去needle的长度加一，去haystack的第i到i+len(needle)的字符与needle进行比较，若相等则返回i若不相等则返回-1
### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        
        if len(haystack)<len(needle):
            return -1


        elif len(haystack)>len(needle) or len(haystack)==len(needle):
            for i in range(len(haystack)-len(needle)+1):
                if haystack[i:i+len(needle)]==needle:
                    return i
            return -1            
```
