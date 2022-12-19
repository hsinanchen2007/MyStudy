# 思路
- 用两个对象来记录 o x 每一步，计数每一行、每一列、两个斜对角有棋子的个数
- 每次计数都判断是否有一项达到了3（有人赢了）返回对应获胜者
- 遍历 moves 长度之后如果没人获胜，判断长度是否为9，得出是 Draw 还是 Pending
# Code
```
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        def check(obj, r, c, name):
            obj['row'][r] += 1
            obj['col'][c] += 1
            
            if r == c:
                obj['dig'][0] += 1 # 左斜线
            if r + c == 2:
                obj['dig'][1] += 1 # 右
            # print(name, obj)
            if obj['row'][r] == 3 or obj['col'][c] == 3 or obj['dig'][0] == 3 or obj['dig'][1] == 3:
                return name

        default = {0: 0, 1: 0, 2: 0}
        x = {'row': default.copy(), 'col': default.copy(), 'dig': default.copy()}
        o = {'row': default.copy(), 'col': default.copy(), 'dig': default.copy()}
        for i, (move_row, move_col) in enumerate(moves):
            # print(i, row_m, col_m)
            if i % 2 == 0: # A
                res = check(x, move_row, move_col, 'A')
            else: # B
                res = check(o, move_row, move_col, 'B')
            if res is not None:
                return res
        return 'Draw' if len(moves) == 9 else 'Pending'
```
