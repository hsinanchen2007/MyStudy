class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        ien = len(digits)-1
        while ien>=0:
            if digits[ien]!=9:
                digits[ien]+=1
                return digits
            digits[ien]=0
            ien-=1
        digits.insert(0,'1')
        return digits

速度还可以如果使用for in的话估计会快点，整体思路就是在最后的数如果不足9就renturn，如果足9就重置为0。