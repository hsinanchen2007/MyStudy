### 解题思路
将字符串先转换成list，在使用sort()进行排序，如果在s的长度内出现不匹配的情况则返回t[i]
循环结束如果没有返回值，说明t中的最后一个就是插入的那个


### 代码

```python
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s = list(s)
        t = list(t)
        s.sort()
        t.sort()
        for i in range(len(s)):
            if s[i] != t[i]:
                return t[i]
        
        return t[-1]



```