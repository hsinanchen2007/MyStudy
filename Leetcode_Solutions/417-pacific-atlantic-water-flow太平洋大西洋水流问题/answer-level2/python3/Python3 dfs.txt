```
from typing import List


def pacific_atlantic(matrix: List[List[int]]) -> List[List[int]]:
    if not matrix:
        return []

    m, n, res = len(matrix), len(matrix[0]), []
    # 表示能流到太平洋的点
    p_visited = [[False for _ in range(n)] for _ in range(m)]
    # 表示能流到大西洋的点
    a_visited = [[False for _ in range(n)] for _ in range(m)]

    for i in range(m):
        # 对于太平洋，第一列都是能流到太平洋的
        dfs(matrix, i, 0, p_visited, m, n)
        # 对于大西洋，最后一列都是能流到大西洋的
        dfs(matrix, i, n-1, a_visited, m, n)

    for j in range(n):
        # 对于太平洋，第一行都是能流到太平洋的
        dfs(matrix, 0, j, p_visited, m, n)
        # 对于大西洋，最后一行都是能流到大西洋的
        dfs(matrix, m-1, j, a_visited, m, n)

    # 最后一次遍历，只有既能流到太平洋，又能流到大西洋的点，才是符合要求的
    for i in range(m):
        for j in range(n):
            if p_visited[i][j] and a_visited[i][j]:
                res.append([i, j])
    return res


def dfs(matrix: List[List[int]], i: int, j: int,
        visited: List[List[int]], m: int, n: int) -> None:
    # 能进来dfs这里，说明肯定是符合条件的，直接就标记这点为True
    visited[i][j] = True
    for x_offset, y_offset in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        x, y = i + x_offset, j + y_offset
        # 只要超出边界，或者已经访问过，或者不是满足题目的“水往低处流”的要求
        # (注意这里是反向找，根据已知条件，太平洋和大西洋各有2边是能直接流到的，然后通过倒推，
        #  即如果下一个点高度比当前还大，说明下一个点能流到当前的点)，
        # 都直接跳过，进行下一个方向的判断
        if x < 0 or x >= m or y < 0 or y >= n or \
           visited[x][y] or matrix[x][y] < matrix[i][j]:
            continue
        dfs(matrix, x, y, visited, m, n)
```
