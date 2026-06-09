# 设置上下左右四个边界，模拟过程，思路清晰。

# 代码
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix: return 
        up,down=0,len(matrix)-1
        left,right=0,len(matrix[0])-1
        res=[]
        while left<=right and up<=down:
            for i in range(left,right+1):#左到右
                res.append(matrix[up][i])
            up+=1
            if up>down: break
            for i in range(up,down+1):#上到下
                res.append(matrix[i][right])
            right-=1
            if left>right: break
            for i in range(right,left-1,-1):#右到左
                res.append(matrix[down][i])
            down-=1
            for i in range(down,up-1,-1):#下到上
                res.append(matrix[i][left])
            left+=1
        return res
```
