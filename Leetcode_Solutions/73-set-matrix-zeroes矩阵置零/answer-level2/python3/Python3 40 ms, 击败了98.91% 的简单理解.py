```
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        if not matrix :
            return []
        temp_row = []      #用于储存有值为0的列
        m = len(matrix)
        n = len(matrix[0])


        for i, row in enumerate(matrix) :
            flags = False    #用于记录有值为0的行，False为行不存在0
            for j, num in enumerate(row) :
                if num == 0 :
                    if j not in temp_row : #j列不在储存的列表中
                        temp_row.append(j) 
                        for k in range(m) : 
                            if k<i and matrix[k][j]!= 0: #遍历这一列中的值，如果列中的行值小于当前行，直接赋值为0
                                matrix[k][j] = 0
                            elif k>i :  #如果列中的行值大于当前行，不为0的值则赋值为"a"，用作标记，为0的值不用管
                                matrix[k][j] = "a" if matrix[k][j]!= 0 else 0 
                    if not flags : 
                        for k in range(j) : #遍历这一行中的值，如果行中的列值小于当前列，直接赋值为0
                            matrix[i][k] = 0
                        flags = True #修改当前行的0值标记为True
                else :
                    if flags or num=="a" :  #遍历值不为0时，如果存在行值标记或则值为"a" 则直接修改为0
                        matrix[i][j] = 0
```
