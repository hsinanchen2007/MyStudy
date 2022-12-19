s.split() 用法

str.split() 以空格为分隔符，包含 \n
https://www.runoob.com/python/att-string-split.html

`
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s.split())
`