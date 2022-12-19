![image.png](https://pic.leetcode-cn.com/119a7c15d75b3c5b98a807dd77692eb047b76c4393f47d547ccb003ddfc4827c-image.png)


第一次遍历，以奇偶行来确定当前值是否变更，如果状态需要变更就在原数组`+2`，
第二次遍历，如果出现`board[i][j]>1`的情况，就恢复到`[0, 1]`大小并改变其奇偶性。

```python []
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m, n = len(board), len(board[0])
        d = ((0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1))
        for i, j in itertools.product(range(m), range(n)):
            t = 0
            for r, c in d:
                x, y = i + r, j + c
                if 0 <= x < m and 0 <= y < n:
                    t += board[x][y] % 2
            if board[i][j] and 2 != t != 3 or not board[i][j] and t == 3:
                board[i][j] += 2
        for i, j in itertools.product(range(m), range(n)):
            if board[i][j] > 1:
                board[i][j] = 1 - board[i][j] % 2
```
