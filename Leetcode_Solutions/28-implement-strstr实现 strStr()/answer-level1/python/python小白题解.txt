### 解题思路
小白第一次写解题思路，我的想法很简单，首先判断字符串needle有没有在haystack里面，没有在的话返回-1，如果在的话，进一步判断是不是这两个字符串是相等的，相等的话，返回0，接下来的情况是needle在haystack里面，且len(needle)<len(haystack)，这时以len(needle)为扫描的长度，以1为步长，进行每个字符串的扫描，当检测到haystack里有等于needle的字符串，返回其首位置i，解题完毕。

### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle not in haystack:return -1
        elif needle ==haystack:return 0
        else:
            length=len(needle)
            for i in range(len(haystack)):
                if haystack[i:length+i] ==needle:
                    return i
                
```