class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        left=0
        right=x
        while left<=right:
            mid=left+(right-left)//2
            if mid*mid==x:
                return mid
            elif mid*mid>x:
                right=mid-1
            else:
                left=mid+1
        return right
传统的二分法，至于等号还有return哪个值就是慢慢试出来的。。。  也花不了多少时间