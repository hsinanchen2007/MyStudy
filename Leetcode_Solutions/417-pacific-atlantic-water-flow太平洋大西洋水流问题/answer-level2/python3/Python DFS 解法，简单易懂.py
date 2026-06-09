### 解题思路
从中间找可以流向四周的高点很难，因为不知道河流往哪里走。所以我们这里要从河边开始倒着推。如果已知某个格可以流进海洋，那么只要它隔壁的格子（上下左右）的数值`>=`当前数值，我们就知道隔壁这个格子也可以流进海洋。

对于大西洋，已知最左边那一列和最上面那一行都是可以流进去的。对于太平洋，已知最右边那一列和最下面那一行都是可以流进去的。我们用`pacific`和`atlantic`两个matrix来记录两次遍历的结果，通过recursion逐个格来判断。最后只要看哪个格子既可以流进大西洋又可以流进太平洋，就是最终答案。

### 代码

```python
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        # get matrix size
        nRow = len(matrix)
        if nRow == 0:
            return []
        nCol = len(matrix[0])
        if nCol == 0:
            return []

        # pacific stores a map with same size as matrix
        # True means it can flows to Pacific, vise versa
        # the same is true for atlantic
        pacific = [[False] * nCol for i in range(nRow)]
        atlantic = [[False] * nCol for i in range(nRow)]

        # helper parameters & array:
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        def isValid(i, j):
            return i >= 0 and i < nRow and j >= 0 and j < nCol
        
        # dfs: mark the adjacent cells in 4 directions as True
        # if it's higher than current cell (meaning it can flow
        # into Pacific or Atlantic)
        def worker(i, j, isPacific):
            for direction in directions:
                new_x = i + direction[0]
                new_y = j + direction[1]
                if isValid(new_x, new_y) and (matrix[new_x][new_y] >= matrix[i][j]):
                    if isPacific:
                        if pacific[new_x][new_y] is False:
                            pacific[new_x][new_y] = True
                            worker(new_x, new_y, isPacific)
                    else:
                        if atlantic[new_x][new_y] is False:
                            atlantic[new_x][new_y] = True
                            worker(new_x, new_y, isPacific)

        # for Pacific case:
        # mark all cells in the top row and in the left column as True
        # and start from these cells with dfs to find all cells that
        # can flow into Pacific
        for i in range(nRow):
            for j in range(nCol):
                if (i == 0) or (j == 0):
                    pacific[i][j] = True
                if pacific[i][j] is True:
                    worker(i, j, True)

        # for Atlantic case:
        # mark all cells in the bottom row and in the right column 
        # as True and start from these cells with dfs to find all
        # cells that can flow into Atlantic
        for i in reversed(range(nRow)):
            for j in reversed(range(nCol)):
                if (i == nRow-1) or (j == nCol-1):
                    atlantic[i][j] = True
                    if atlantic[i][j] is True:
                        worker(i, j, False)

        # return cells that are both True in pacific and atlantic
        result = []
        for i in range(nRow):
            for j in range(nCol):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        return result
```