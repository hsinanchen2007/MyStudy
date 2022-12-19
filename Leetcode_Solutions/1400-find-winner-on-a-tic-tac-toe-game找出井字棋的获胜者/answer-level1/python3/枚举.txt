### 解题思路
一共就这么几种情况，直接枚举就是了，字典来加快查询速度

### 代码

```python3
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        length = len(moves)
        if length < 5:
            return "Pending"
        else:
            # 一共就八种情况，直接枚举了
            row_dict = {0:0, 1:0, 2:0}
            col_dict = {0:0, 1:0, 2:0}
            x_dict = {1:0, 2:0}
            for a_step in range(0,length,2):
                row_dict[moves[a_step][0]] = row_dict[moves[a_step][0]] + 1
                col_dict[moves[a_step][1]] = col_dict[moves[a_step][1]] + 1
                if moves[a_step][0] == moves[a_step][1]:
                    x_dict[1] = x_dict[1] + 1
                if moves[a_step][0] == 0 and moves[a_step][1] == 2 or moves[a_step][0] == 1 and moves[a_step][1] == 1 or moves[a_step][0] == 2 and moves[a_step][1] == 0:
                    x_dict[2] = x_dict[2] + 1
            if row_dict[0] == 3 or row_dict[1] == 3 or row_dict[2] == 3 or col_dict[0] == 3 or col_dict[1] == 3 or col_dict[2] == 3 or x_dict[1] == 3 or x_dict[2] == 3:
                return "A"
            row_dict = {0:0, 1:0, 2:0}
            col_dict = {0:0, 1:0, 2:0}
            x_dict = {1:0, 2:0}
            for a_step in range(1,length,2):
                row_dict[moves[a_step][0]] = row_dict[moves[a_step][0]] + 1
                col_dict[moves[a_step][1]] = col_dict[moves[a_step][1]] + 1
                if moves[a_step][0] == moves[a_step][1]:
                    x_dict[1] = x_dict[1] + 1
                if moves[a_step][0] == 0 and moves[a_step][1] == 2 or moves[a_step][0] == 1 and moves[a_step][1] == 1 or moves[a_step][0] == 2 and moves[a_step][1] == 0:
                    x_dict[2] = x_dict[2] + 1
            if row_dict[0] == 3 or row_dict[1] == 3 or row_dict[2] == 3 or col_dict[0] == 3 or col_dict[1] == 3 or col_dict[2] == 3 or x_dict[1] == 3 or x_dict[2] == 3:
                return "B"
            if length == 9:
                return "Draw"
            return "Pending"
            
                



```