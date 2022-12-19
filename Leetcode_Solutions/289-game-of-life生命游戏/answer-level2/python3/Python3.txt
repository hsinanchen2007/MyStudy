### 解题思路
正负数区分0和1

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                # 防止0和1的周围8个位置都没有1, 那么存储0的话就不知道这个位置原来是0还是1了, 
                # 因为我们是靠正数负数来判断这个位置原本的值的
                count = 1
                # 遍历周围8个细胞
                for x, y in [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]:
                    # 为1的位置, 肯定大于0, 为0的位置是原数组没更新,更新之后的0都变成了负数, 就算周围没有1,也是存的-1
                    if 0<= i + x < m and 0<= j + y < n and board[i+x][j+y] >= 1:
                        count += 1
                board[i][j] = count if board[i][j] == 1 else -count
        for i in range(m):
            for j in range(n):
                # 因为加了1, 所以要减去
                count = abs(board[i][j])- 1
                # 都给劳资死
                if count < 2:
                    board[i][j] = 0
                # 活的依旧活, 死的依旧死
                elif count == 2:
                    board[i][j] = int(board[i][j] > 0)
                # 活的依旧活, 死的会复活, 反正都是活
                elif count == 3:
                    board[i][j] = 1
                # 都给劳资死
                elif count > 3:
                    board[i][j] = 0
```