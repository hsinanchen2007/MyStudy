### 解题思路
此处撰写解题思路
时间复杂度：o(n)
空间复杂度：o(1)
### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(needle)
        for i in range(len(haystack)-m+1):
            if haystack[i:m+i] == needle:
                return i
        return -1
    


            

```