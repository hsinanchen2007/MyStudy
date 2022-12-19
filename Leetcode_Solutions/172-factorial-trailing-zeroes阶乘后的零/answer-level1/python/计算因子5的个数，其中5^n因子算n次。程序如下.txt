class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n < 5:
            return 0
        temp = 5
        count = 0
        factor = 1
        while n >= temp:
            count += factor * (n / temp - n/(5 * temp))
            temp *= 5
            factor += 1
        return count