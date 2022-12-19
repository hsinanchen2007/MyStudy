# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:

    def firstBadVersion(self, n):

        """
        :type n: int
        :rtype: int
        """

        l = 0
        r = n-1
        mid = (l+r)//2
        while l-r <1:
            if isBadVersion(mid):           #说明错误发生在更早以前
                r= mid-1
                mid = (l+r)//2
                
            elif isBadVersion(mid) != True:     #说明错误发生在更晚的版本
                l = mid+1
                mid = (l+r)//2
                
        for i in [l,r]:
            if isBadVersion(i) == True:
                return i