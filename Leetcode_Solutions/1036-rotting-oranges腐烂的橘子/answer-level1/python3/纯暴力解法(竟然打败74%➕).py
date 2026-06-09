### 解题思路
此处撰写解题思路
本以为会挂在打卡第三天

### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        length1=len(grid)
        length2=len(grid[0][:])

        def judge(grid):
            # 查看坏橘子周围有木有好橘子，将好橘子位置保存，下一步变成坏橘子
            res=[]
            for i in range(length1):
                for j in range(length2):
                    if grid[i][j]==2:
                        if j!=0:
                            if grid[i][j-1]==1:
                                res.append([i,j-1])
                        if j!=length2-1:
                            if grid[i][j+1]==1:
                                res.append([i,j+1])
                        if i!=0:
                            if grid[i-1][j]==1:
                                res.append([i-1,j])
                        if i!=length1-1:
                            if grid[i+1][j]==1:
                                res.append([i+1,j])
            return res
        
        res=judge(grid)
        count=0
        while 1:
            res=judge(grid)
            # res不为空 即下一时刻会有坏橘子产生时间➕1
            if len(res)>0:
                count+=1
                for [i,j] in res:
                    grid[i][j]=2
            else:
                # 下一刻没有坏橘子，循环结束，判断里面有无好橘子，有则返回-1
                for i in range(length1):
                    for j in range(length2):
                        if grid[i][j]==1:
                            return -1
                return count
```