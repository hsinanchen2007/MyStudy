class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        multi = 1
        sumM = 0
        for i in range(len(str(n))):
            multi = multi * int(str(n)[i])
            sumM = sumM + int(str(n)[i])