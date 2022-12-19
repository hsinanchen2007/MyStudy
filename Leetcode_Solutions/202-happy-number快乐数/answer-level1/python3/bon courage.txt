class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        r = []
        while n not in r:
            r.append(n)
            n = sum([int(ele)**2 for ele in str(n)])
            if n == 1:
                return True
        return False
        