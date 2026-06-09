一、算法思想
由于二维数组每行每列皆有序，可考虑从右上角开始查找。当当前元素为目标时，返回真。当当前元素小于目标时，则其左侧元素也小于目标，为此可将当前元素下移一位，从以新元素为右上角顶点向左向下的矩形区域里查找。当当前元素大于目标时，则其下方元素也大于目标，为此可将该元素左移一位，从以新元素为右上角顶点的矩形区域里查找。
二、算法实现
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        m = len(matrix)
        n = len(matrix[0])
        i, j = 0, n-1
        while i < m and j > -1:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1
        return False
```
三、复杂度分析
1.时间复杂度：O(M+N)。M为矩阵行数，N为矩阵列数。
2.空间复杂度：O(1)。