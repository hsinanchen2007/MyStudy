class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix is None:
            return False
        o=len(matrix)
        for i in range(o):
            n=len(matrix[i])
            j=0
            k=n-1
            while j<=k:
                mid=(j+k)//2
                if target>matrix[i][mid]:
                    j=mid+1
                elif target<matrix[i][mid]:
                    k=mid-1
                else:
                    return True
        return False
内存占用超过100%用户