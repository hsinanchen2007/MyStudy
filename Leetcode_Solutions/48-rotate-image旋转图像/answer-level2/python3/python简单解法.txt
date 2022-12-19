```
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for layer in range(n//2):#分层, 像甜甜圈
            for index in range(layer,n-layer-1):#matrix[index][index]就是该圈左上角
                # print(layer,index)
                matrix[layer][index],matrix[index][n-layer-1],matrix[n-layer-1][n-index-1],matrix[n-index-1][layer]=matrix[n-index-1][layer],matrix[layer][index],matrix[index][n-layer-1],matrix[n-layer-1][n-index-1]
```
