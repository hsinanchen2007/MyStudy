### 解题思路
1、化繁为简
2、对K的取值，当超过数组本身长度时，需要对其求余。
### 代码

```python3
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        n,m=len(grid),len(grid[0])
        num=n*m
        temp=[]
        k=k%num
        for j in range(n):
            temp=temp+grid[j] 
        Temp=temp[num-k:num]+temp[0:num-k]
        for i in range(n):
            for j in range(m):
                grid[i][j]=Temp[i*m+j]
        return grid

```