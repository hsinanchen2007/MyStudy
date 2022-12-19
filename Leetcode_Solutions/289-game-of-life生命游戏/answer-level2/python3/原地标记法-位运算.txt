1. 对面板每个元素的周围活细胞进行统计，对元素进行位操作，高四位保存该细胞周围的活细胞数，低四位保存本次的状态（0 或 1）
2. 对高四位进行判断，本身为活细胞且周围细胞数为2或周围细胞数为3，则将高四位置为0001表示下次的状态为活，其余情况则将高四位置为0000.
2. 遍历面板的所有元素进行上述操作
3. 遍历面板的所有元素取出该元素高四位的值

```python
def gameOfLife(self, board: List[List[int]]) -> None:
        if not board or not board[0]:
            return
        row = len(board)
        col = len(board[0])

        def countCeil(x: int, y: int) -> int:
            count = 0
            for x_offset in range(-1, 2):
                for y_offset in range(-1, 2):
                    if x_offset == y_offset == 0:
                        continue
                    if 0 <= x + x_offset < row and 0 <= y + y_offset < col:
                        count += board[x + x_offset][y + y_offset] & 0x0F
            if count == 3 or (board[x][y] and count == 2):
                count = 1  # the next status of self
            else:
                count = 0
            board[x][y] |= (count << 4)

        for x in range(row):
            for y in range(col):
                countCeil(x, y)
        for x in range(row):
            for y in range(col):
                board[x][y] = (board[x][y] & 0xF0) >> 4
```
