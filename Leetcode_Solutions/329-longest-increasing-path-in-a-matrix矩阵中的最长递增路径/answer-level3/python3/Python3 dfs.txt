```
from typing import List


def longest_increasing_path(matrix: List[List[int]]) -> int:
    if not matrix:
        return 0

    m, n, res = len(matrix), len(matrix[0]), 0
    # 用于记录每个点的最长递增路径的长度
    cache = [[-1 for _ in range(n)] for _ in range(m)]

    for i in range(m):
        for j in range(n):
            # 每次寻找该点的最长递增路径的长度，并且更新全局的长度
            cur_len = dfs(i, j, matrix, cache, m, n)
            res = max(res, cur_len)
    return res


def dfs(i: int, j: int, matrix: List[List[int]],
        cache: List[List[int]], m: int, n: int) -> int:
    # 如果不等于-1，说明之前已经有记录了(即包含了这个点的最长递增路径的长度)
    if cache[i][j] != -1:
        return cache[i][j]
    res = 1
    for x_offset, y_offset in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        x, y = i + x_offset, j + y_offset
        if x < 0 or x >= m or y < 0 or y >= n or matrix[x][y] <= matrix[i][j]:
            continue
        length = 1 + dfs(x, y, matrix, cache, m, n)
        res = max(length, res)
    # 记录当前这个点的最长递增路径长度
    cache[i][j] = res
    return res


if __name__ == '__main__':
    nums1 = [
        [9, 9, 4],
        [6, 6, 8],
        [2, 1, 1]
    ]
    print(longest_increasing_path(nums1))

    nums2 = [
        [3, 4, 5],
        [3, 2, 6],
        [2, 2, 1]
    ]
    print(longest_increasing_path(nums2))
```
