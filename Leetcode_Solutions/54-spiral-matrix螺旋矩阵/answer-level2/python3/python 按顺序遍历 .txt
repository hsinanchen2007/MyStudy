![image.png](https://pic.leetcode-cn.com/a8ce62fcce83378f98beb9d0b0d9a218a7d7532bcb6207e338fd2c1f036f5dc9-image.png)
检测边界条件，不满足就跳出，比不上大佬的[::-1]和zip方法求转置牛逼，但是好像这样快一点
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        def is_boundry():
            if left>=right or up>=down:
                return True
            else:
                return False

        left=up=0
        right,down=len(matrix[0]),len(matrix)
        res=[]
        while True:
            for i in range(left,right):
                res.append(matrix[up][i])
            up+=1
            if is_boundry():
                break
            for i in range(up,down):
                res.append(matrix[i][right-1])
            right-=1
            if is_boundry():
                break
            for i in range(right-1,left-1,-1):
                res.append(matrix[down-1][i])
            down-=1
            if is_boundry():
                break
            for i in range(down-1,up-1,-1):
                res.append(matrix[i][left])
            left+=1
            if is_boundry():
                break
        return res
```
