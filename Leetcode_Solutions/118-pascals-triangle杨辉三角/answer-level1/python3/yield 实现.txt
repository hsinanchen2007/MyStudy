class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        list = [1]
        n = 0
        while n < numRows:
            yield list
            list = [1] + [list[i] + list[i + 1] for i in range(len(list) - 1)] + [1]
            n += 1