### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        if not rows: return
        cols = len(board[0])
        dt = [
            (0, -1), (0, 1), (-1, 0), (1, 0),
            (-1, -1), (-1, 1), (1, -1), (1, 1)
        ]
        **tmp = [[board[row][col] for col in range(cols)] for row in range(rows)]**
        for r in range(rows):
            for c in range(cols):
                live_cell = 0
                for i in dt:
                    x = r + i[0]
                    y = c + i[1]
                    if x >= 0 and y >= 0 and x < rows and y < cols and tmp[x][y] == 1:
                        live_cell += 1
                if tmp[r][c] == 1:
                    if live_cell < 2 or live_cell > 3:
                        board[r][c] = 0
                if tmp[r][c] == 0:
                    if live_cell == 3:
                        board[r][c] = 1
                print(live_cell)

        
```
加粗部分，本来我写的是tmp = list(board),这里有个坑。此举复制一维数组时没有问题，操作tmp不会改变board中的内容，但是当操作的一维数组中有可变对象时，对tmp的操作会改变board中的内容，因为此时这个指向的是同一对象的引用！！！
忘记了这个，我想着我的逻辑没问题呀，调试了半天，看到官方题解才想起，用Python写的老哥切记切记！！
