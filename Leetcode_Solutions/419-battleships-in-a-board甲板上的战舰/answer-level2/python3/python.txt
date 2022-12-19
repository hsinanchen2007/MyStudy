### 解题思路
逐个查找x，如果既不是首行首例列，左边和上边都不为空就不计算。
### 代码

```python3
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        num_ship = 0
        for line_no , line in enumerate(board):
            for i,item in enumerate(line):
                if item == 'X':
                    if ((board[line_no - 1][i] == 'X')and line_no> 0) or ((line[i - 1] == 'X') and i>0):
                        continue
                    num_ship+=1
        return num_ship
```