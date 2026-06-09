```
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix: return []
        
        R = len(matrix)
        C = len(matrix[0])

        def neighbors(i, j):
            for row, col in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                if 0<=row<R and 0<=col<C:
                    yield row, col

        # 大西洋与太平洋的边界点
        pac_list = [(0, i) for i in range(C)] + [(i, 0) for i in range(1, R)]
        atl_list = [(R-1, i) for i in range(C)] + [(i, C-1) for i in range(R-1)]

        # 对两个大洋，分别记录是否可以访问到某点
        pacific = [[False] * C for _ in range(R)]
        atlantic = [[False] * C for _ in range(R)]

        # 依次对边界上的点进行DFS, 将未访问且大于matrix[cur[0]][cur[1]]的相邻的点加入queue中
        for el in pac_list:
            queue = [el]
            while queue:
                cur = queue.pop(0)
                pacific[cur[0]][cur[1]] = True
                
                for i, j in neighbors(cur[0], cur[1]):
                    if not pacific[i][j] and matrix[i][j] >= matrix[cur[0]][cur[1]]:
                        pacific[i][j] = True
                        queue.append((i, j))
                    
        
        for el in atl_list:
            queue = [el]
            while queue:
                cur = queue.pop(0)
                atlantic[cur[0]][cur[1]] = True
                
                for i, j in neighbors(cur[0], cur[1]):
                    if not atlantic[i][j] and matrix[i][j] >= matrix[cur[0]][cur[1]]:
                        atlantic[i][j] = True
                        queue.append((i, j))

        # 在两个matrix里均标记为True的点，即为最终答案
        res = []
        for i in range(R):
            for j in range(C):
                if pacific[i][j] and atlantic[i][j]:
                    res.append((i, j))

        return res
```
