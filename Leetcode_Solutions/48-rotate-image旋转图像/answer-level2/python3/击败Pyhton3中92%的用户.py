from typing import List
class Solution:
    #my Solution
    def rotate(self, matrix: List[List[int]]) :
        matrix_len = len(matrix) #get martix dims
        for i in range(0,matrix_len//2): # operate the image by each ixi outside edge
            #[i,matrix-i)
            for j in  range(i,matrix_len-i-1):
                value0 = matrix[i][j]
                value1 = matrix[j][matrix_len-1-i]
                matrix[j][matrix_len-1-i] = value0
                value2 = matrix[matrix_len-1-i][matrix_len-1-j]
                matrix[matrix_len-1-i][matrix_len-1-j] = value1
                value3 = matrix[matrix_len-1-j][i]
                matrix[matrix_len-1-j][i] = value2
                matrix[i][j] = value3
        return matrix

test = Solution()
print (test.rotate([[1,2,3],[4,5,6],[7,8,9]]))