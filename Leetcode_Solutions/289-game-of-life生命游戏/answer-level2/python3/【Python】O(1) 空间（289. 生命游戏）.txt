
# 使用额外的额空间

## 思路

我们可以copy一份完全一样的board， 然后按照copy的board进行更新细胞状态即可。

我写了一个函数cntLiveCell(i, j)  用来计算 board[i][j] 周围的活细胞数目。

## 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m = len(board)
        n = len(board[0])
        if m <= 0 or n <= 0:
            return []
        old = copy.deepcopy(board)

        def cntLiveCell(i, j):
            cnt = 0
            directions = [(0, 1), (0, -1), (-1, 0), (1, 0),
                          (1, 1), (1, -1), (-1, 1), (-1, -1)]
            for (dx, dy) in directions:
                if i + dx >= 0 and i + dx < m and j + dy >= 0 and j + dy < n:
                    cnt += old[i + dx][j + dy]

            return cnt

        for i in range(m):
            for j in range(n):
                # 八个方向有几个活细胞
                cnt = cntLiveCell(i, j)
                if old[i][j] == 0 and cnt == 3:
                    board[i][j] = 1
                if old[i][j] == 1 and (cnt > 3 or cnt < 2):
                    board[i][j] = 0
```

***复杂度分析***
- 时间复杂度：$O(m * n)$
- 空间复杂度：$O(m * n)$

# 不使用额外的空间

## 思路

如何不使用额外的空间是这道题“中等”的原因。 

由于 board 中的数字只能是 0 或者 1，我们考虑用一个 bit 来存储这个信息。然后我们将这个细胞周围有多少活细胞这个信息，存储到高位（即从第二位开始）。

![image.png](https://pic.leetcode-cn.com/bf59e91ca71449f3f0d144551165a7626be9e736dcee707e25b13dd8c1897824-image.png)

我们一次遍历进行上述的数据处理。 之后我们再进行一次遍历。将之前存储的数据取出来，最后一位表示之前的细胞状态，剩下位表示周围的活细胞个数。计数逻辑，以及这之后的逻辑就和上面的解法一样了。


## 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m = len(board)
        n = len(board[0])
        if m <= 0 or n <= 0:
            return []

        def cntLiveCell(i, j):
            cnt = 0
            directions = [(0, 1), (0, -1), (-1, 0), (1, 0),
                          (1, 1), (1, -1), (-1, 1), (-1, -1)]
            for (dx, dy) in directions:
                if i + dx >= 0 and i + dx < m and j + dy >= 0 and j + dy < n:
                    cnt += (board[i + dx][j + dy] & 1)
            return cnt
        for i in range(m):
            for j in range(n):
                # 八个方向有几个活细胞
                cnt = cntLiveCell(i, j)
                board[i][j] |= cnt << 1
        for i in range(m):
            for j in range(n):
                # 变化之前当前cell的值
                cell = board[i][j] & 1
                cnt = board[i][j] >> 1
                if cell == 0 and cnt == 3:
                    board[i][j] = 1
                elif cell == 1 and (cnt > 3 or cnt < 2):
                    board[i][j] = 0
                else:
                    board[i][j] = cell
```


***复杂度分析***
- 时间复杂度：$O(m * n)$
- 空间复杂度：$O(1)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)