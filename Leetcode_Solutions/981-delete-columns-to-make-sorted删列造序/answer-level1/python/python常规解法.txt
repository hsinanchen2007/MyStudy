class Solution(object):
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        y=0
        for j in range(len(A[0])):
            for i in range(len(A)-1):
                if A[i][j]>A[i+1][j]:
                    y=y+1
                    break
        return y