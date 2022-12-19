class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix==[]:
            return False
        
        row=len(matrix)
        col=len(matrix[0])
        
        for i in range(row):
            try:
                matrix[i].index(target)
                return True
            except:
                continue
        return False