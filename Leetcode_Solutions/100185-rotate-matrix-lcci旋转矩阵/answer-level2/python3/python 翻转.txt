由外到内一层一层进行翻转。


```
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def swap(a,b):
            a ^= b
            b ^= a
            a ^= b
            return a,b

        def helper(matrix,layer):
            i = len(matrix)-layer-1
            for j in range(len(matrix)-2*layer-1):
                matrix[i][layer+j], matrix[i-j][i] = swap(matrix[i][layer+j] , matrix[i-j][i])
                matrix[i-j][i] , matrix[layer][i-j] = swap(matrix[i-j][i] , matrix[layer][i-j])
                matrix[layer][i-j] , matrix[layer+j][layer] = swap(matrix[layer][i-j] , matrix[layer+j][layer])
            return matrix
            
        for layer in range(len(matrix)//2):
            matrix = helper(matrix,layer)
```
