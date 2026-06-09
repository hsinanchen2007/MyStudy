```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0]*n for i in range(n)]
        j,k = 0,0
#定义行和列增减列表
        col_dirs = [1,0,-1,0]
        row_dirs = [0,1,0,-1]
        num = 1
#定义模拟整个过程中方向改变的总次数recycle
        recycle = 2*n-1+0**n
        for i in range(recycle):
#当前方向dir，下一个方向dir_next
            dir = i%4 
            dir_next = (i+1)%4
            #print(dir)
#定义while的边界条件
            while (j >=0 and j < n and k < n and k >= 0) and matrix[j][k]==0 :
                matrix[j][k] = num
                num += 1
                j += row_dirs[dir]
                k += col_dirs[dir]
#跳出while，退回当前方向增量，增加下一个方向增量
            j +=row_dirs[dir_next] - row_dirs[dir]
            k +=col_dirs[dir_next] - col_dirs[dir]    
        return matrix
```


