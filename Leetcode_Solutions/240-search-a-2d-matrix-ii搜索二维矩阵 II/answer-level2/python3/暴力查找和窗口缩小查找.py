1、暴力查找如下：
```
    # array 二维列表
    def Find(self, target, array):
        # write code here
        #if matrix[0] == []:
        #    return False
        #for i in range(len(matrix)):
        #    for j in range(len(matrix)):
        #        if target == matrix[i][j]:
        #            return True
        #return False
```
复杂度起码应该是O(n),二维数组中所有元素都遍历过了；
2、缩小窗口模式如下：根据题中按序排列规则，从右上角开始缩小范围查找：
```
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if matrix == []:
            return False
        if matrix[0]==[]:
            return False
        i = 0
        j = len(matrix[0])-1
        while i<len(matrix) and j >=0:
            value = matrix[i][j]
            if value == target:
                return True
            elif value < target:
                i+=1
            else:
                j-=1
        return False
```
