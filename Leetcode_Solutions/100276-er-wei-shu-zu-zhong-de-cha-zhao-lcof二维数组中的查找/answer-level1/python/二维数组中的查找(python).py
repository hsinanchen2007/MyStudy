思路一因为每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序,所以从左上角(右下角)开始与标签值比较，当`matrix[i][j]>targe`t则左移,等于返回`True`，否者下移，这样可以最快判断数组中是否含有该整数。
```
class Solution(object):
    def findNumberIn2DArray(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n=len(matrix)
        if n==0:
            return False
        m=len(matrix[0])
        i=0
        j=m-1
        # 从右上角开始找
        while i<n and j>=0:
            
            if target>matrix[i][j]: #向下移动
                i+=1
            elif target==matrix[i][j]:
                return True
            else:  #向左移动
                j-=1
        return False
```
