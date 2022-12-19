class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        list = [1]
        n = 0
        while n < rowIndex:
            list = [1] + [list[i] + list[i + 1] for i in range(len(list) - 1)] + [1]
            n += 1
        return list