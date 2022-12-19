### 解题思路
![image.png](https://pic.leetcode-cn.com/019e0e6dc75a3a4eeb8ad6df5765a3e42ae8db4aa42b6a6c58f9d95ebc9d756b-image.png)


### 代码

```python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        islands = [[0] * n for _ in range(m)]
        areas = collections.defaultdict(lambda : [[],0])
        last_index = 0
        # areas = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    # print(i,j)
                    if islands[i][j] == 0 :

                        curr = last_index + 1
                        last_index = curr

                        islands[i][j] = curr
                        areas[curr][0].append((i,j))
                        areas[curr][1] += 1
                    else :
                        curr = islands[i][j]

                    if i<m-1 and grid[i+1][j] == 1 :
                        if islands[i+1][j] == 0:
                            islands[i+1][j] = curr
                            areas[curr][1] += 1
                            areas[curr][0].append((i+1,j))
                        elif islands[i+1][j] != curr:
                            next = islands[i+1][j]
                            for x,y in areas[next][0]:
                                islands[x][y] = curr
                            areas[curr][0].extend(areas[next][0])
                            areas[curr][1] += areas[next][1]
                            areas.pop(next)
                            
                    if j<n-1 and grid[i][j+1] == 1 :
                        if islands[i][j+1] == 0:
                            islands[i][j+1] = curr
                            areas[curr][0].append((i,j+1))
                            areas[curr][1] += 1
                        elif islands[i][j+1] != curr:
                            next = islands[i][j+1]
                            for x,y in areas[next][0]:
                                islands[x][y] = curr
                            areas[curr][0].extend(areas[next][0])
                            areas[curr][1] += areas[next][1]
                            areas.pop(next)
        # print(islands)
        # print(areas)
        if not areas:
            return 0
        return max([v[1] for v in areas.values()])

                     


```