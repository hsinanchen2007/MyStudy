### 解题思路
时间复杂度O（1），空间复杂度O（1）,因为复杂度固定在9*9宫格内
核心思想采用字典映射，存储每行，每列，每个小型9宫格的元素出现个数，总共有9行9列9块。
最后采用set，缩减遍历的次数，一旦出现不等于1的值，return False，其他情况下return True。
**注：通过list(dict.values())可以将字典的值转为列表形式。**


### 代码

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # 规定每9小格为一个box
        boxs = [{} for _ in range(9)]
        rows = [{} for _ in range(9)]
        columns = [{} for _ in range(9)]
        boxs_number = 0
        for i in range(9):
            if i%3 == 0 and i != 0:
                boxs_number += 3
            for j in range(9):
                if board[i][j] != '.':
                    rows[i][board[i][j]] = rows[i].setdefault(board[i][j],0) + 1
                    columns[j][board[i][j]] = columns[j].setdefault(board[i][j],0) + 1
                    boxs[boxs_number+j//3][board[i][j]] = boxs[boxs_number+j//3].setdefault(board[i][j],0) + 1
        for i in range(9):
            b = set(list(boxs[i].values()))
            r = set(list(rows[i].values()))
            c = set(list(columns[i].values()))
            for i in b:
                if i != 1:
                    return False
            for i in r:
                if i != 1:
                    return False
            for i in c:
                if i != 1:
                    return False
        return True


```