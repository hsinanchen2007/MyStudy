### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix or not matrix[0]:
            return []
        
        def dfs(i, j, to_where):
            # 记录dfs搜索过的路径
            to_where.add((i, j))
            # 探索点(i, j) 上下左右四个方向
            for x, y in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                # i, j加上偏移量x, y后， 需要在边界内， 并且是向地势高的地方走， 并且不能是已经探索过的点
                if 0 <= i + x < len(matrix) and 0 <= j + y < len(matrix[0]) and matrix[i+x][j+y] >= matrix[i][j] and (i+x, j+y) not in to_where:
                    dfs(i+x, j+y, to_where)
        # 从第一行，向地势高的地方走，并记录在to_Pacific 中
        to_Pacific = set()
        for i in range(len(matrix)):
            dfs(i, 0, to_Pacific)
        # 从第一列，向地势高的地方走，并记录在to_Pacific 中
        for i in range(len(matrix[0])):
            dfs(0, i, to_Pacific)
        # 至此 to_Pacific 记录了所有可以到太平洋的点
        to_Atlantic = set()
        # 从最后一列，向地势高的地方走，并记录在to_Atlantic 中
        for i in range(len(matrix)):
            dfs(i, len(matrix[0])-1, to_Atlantic)
        # 从最后一行，向地势高的地方走，并记录在to_Atlantic 中
        for i in range(len(matrix[0])):
            dfs(len(matrix)-1, i, to_Atlantic)
        # to_Pacific 和 to_Atlantic 的交集即为即能到太平洋， 又能到大西洋的点
        return to_Pacific.intersection(to_Atlantic)
```