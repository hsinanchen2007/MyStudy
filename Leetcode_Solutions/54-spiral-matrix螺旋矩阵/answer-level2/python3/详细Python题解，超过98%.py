思路和官方题解一致，用方向数组来控制遍历的方向，但是用set来保存已经遍历过点，加快了速度。

```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:return []
        m,n = len(matrix),len(matrix[0])
        x = y = di = 0
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]
        res = []
        visited = set()

        for i in range(m*n):
            res.append(matrix[x][y])
            visited.add((x,y))
            nx,ny = x+dx[di],y+dy[di]
            if 0<=nx<m and 0<=ny<n and (nx,ny) not in visited:
                x,y = nx,ny   
            else:
                di = (di+1)%4  # 如果不满足条件，换一个方向进行遍历
                x,y = x+dx[di],y+dy[di]
        return res
```

**关于Python的详细题解记录在[github](https://github.com/linxid/Leetcode_Python)，有兴趣的小伙伴可以关注下。**
![image.png](https://pic.leetcode-cn.com/8582136a33cde7cd29627e03daf10eb98dd4cbb9c33f209d37e66edbaf128b31-image.png)

