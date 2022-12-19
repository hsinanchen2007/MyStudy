解法一：暴力，依次遍历二维数组，时间复杂度m*n
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool: 
        if matrix==None or len(matrix)==0:
            return False
        rows = len(matrix)  # 矩阵行数
        columns = len(matrix[0])  # 矩阵列数
        for i in range(rows):
            for j in range(columns):
                if matrix[i][j]==target:
                    return True
        return False
```

解法二：因为二维数组的每一行都按照从左到右递增的顺序排序，遍历二维数组的每一行，对每一行使用二分查找方法进行查找
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix==None or len(matrix)==0:
            return False
        rows = len(matrix)
        for i in range(rows):
            start = 0
            end = len(matrix[i])-1
            while start <= end:  #  对每一行用二查找方法查找
                mid = start+(end-start)//2
                if matrix[i][mid]>target:
                    end = mid-1
                elif matrix[i][mid]<target:
                    start = mid+1
                else:
                    return True
        return False
```


解法三：从左下角开始判断，如果左下角的数字比target大，删除所在行；反之，删除所在列，逐渐向右上角逼近
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix==None and len(matrix)==0:
            return False
        rows = len(matrix)-1
        columns = 0
        while rows>=0 and columns<=len(matrix[0])-1:
            if matrix[rows][columns]>target:
                rows -= 1
            elif matrix[rows][columns]<target:
                columns += 1
            else:
                return True
        return False
```


解法四：从右上角开始判断，如果右上角的数字比target大，删除所在列；反之，删除所在行，逐渐逼近左下角
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if matrix==None or len(matrix)==0:
            return False
        # 从右上角开始判断，如果右上角的数字比target大，删除所在列；反之，删除所在行，逐渐逼近左下角
        rows = 0
        columns = len(matrix[0])-1
        while rows<=len(matrix)-1 and columns>=0:
            if matrix[rows][columns]>target:
                columns -= 1
            elif matrix[rows][columns]<target:
                rows += 1
            else:
                return True
        return False
```