class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        lis = []
        for i in range(1,int(n*"9")+1):
            lis.append(i)
        return lis
