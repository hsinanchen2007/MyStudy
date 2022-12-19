```
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        for i in s:
            if i in t:
                t = t.replace(i,'',1)
        return t

```
遍历一遍s，只要在t中就用空字符串替换t中的当前字符最后输出t即可