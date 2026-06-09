### 解题思路
代码换行反斜杠，`all`所有为真返回true

### 代码

```python
class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
        first,second = "XO"
        x_num = sum(r.count("X") for r in board)
        o_num = sum(r.count("O") for r in board)
        def win(XO:str)->bool:
            for i in range(3):
                if all([board[i][j]==XO for j in range(3)]) or \
                all([board[j][i]==XO for j in range(3)]):
                    return True
            if all([board[i][i]==XO for i in range(3)]) or\
            all([board[i][2-i]==XO for i in range(3)]):
                return True
        if o_num not in {x_num,x_num-1}:
            return False
        if win(first):
            return o_num==(x_num-1)
        if win(second):
            return o_num==x_num
        return True
```