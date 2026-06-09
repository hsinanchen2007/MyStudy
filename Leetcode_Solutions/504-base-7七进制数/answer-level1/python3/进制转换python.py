class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        else:
            res = ''
            n = abs(num)
            while n>0 :
                res = str(n%7) +res
                n = n/7
        if num < 0:
            res = '-'+res
        return res