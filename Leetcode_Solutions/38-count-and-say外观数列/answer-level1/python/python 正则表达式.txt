import re
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        pattern = re.compile(r"1+|2+|3+|4+|5+|6+|7+|8+|9+")
        if n == 1:
            return "1"
        else:
            init = "1"
            for i in range(n - 1):
                lst = pattern.findall(init)
                init = ""
                for k in (str(len(val)) + val[0] for val in lst):
                    init += k
            return init
                