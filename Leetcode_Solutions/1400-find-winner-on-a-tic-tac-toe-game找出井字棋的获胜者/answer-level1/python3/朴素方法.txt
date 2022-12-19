```python []
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        
        A_moves = {tuple(moves[i]) for i in range(len(moves)) if not i & 1}  # 把A下的位置找出来
        B_moves = {tuple(moves[i]) for i in range(len(moves)) if i & 1}  # 把B下的位置找出来
        win = [                  
            {(1,1),(2,2),(0,0)},
            {(0,2),(1,1),(2,0)},
            {(1,0),(1,1),(1,2)},
            {(0,0),(0,1),(0,2)},  # 赢的可能有8中：任意一行、任意一列、两个对角线
            {(2,0),(2,1),(2,2)},
            {(0,0),(1,0),(2,0)},
            {(0,1),(1,1),(2,1)},
            {(0,2),(1,2),(2,2)},
              ]
        for i in win:  # 逐一地问，A赢了没有？B赢了没有
            if i <= A_moves:return 'A'  # P <= Q 表示P为Q的子集。如果A赢了，return 'A'
            if i <= B_moves:return 'B'  # 如果B赢了，return 'B'
        if len(moves) == 9:  # 如果没有人赢并且格子走完了，return 'Draw'
            return 'Draw'  
        return 'Pending'  # 如果没有人赢并且格子没走完，return 'Pending'
```
