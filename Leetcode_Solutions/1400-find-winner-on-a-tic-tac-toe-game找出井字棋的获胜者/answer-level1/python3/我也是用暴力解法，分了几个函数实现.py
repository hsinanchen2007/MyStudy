遍历所有可能解，看两位选手的棋子是否满足其一
再比较选手的情况，解决~~~
```
class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        if len(moves) < 5:
            return "Pending"
        else:
            move_a = self.chose(moves, 0)
            move_b = self.chose(moves, 1)
            a = self.doSth(move_a)
            b = self.doSth(move_b)
            if a:
                return "A"
            elif b:
                return 'B'
            elif len(moves) == 9:
                return "Draw"
            else:
                return "Pending"

    # 遍历所有可能解，看选手的棋子是否满足其一
    def doSth(self, moves):
        """
        return bool: T or F 
        """
        winning_list = self.generate_list()
        for stra in winning_list:
            count = 0
            for tic in moves:
                if tic in stra:
                    count += 1
            if count == 3:
                return True
        return False

    # 生成所有可能解
    def generate_list(self):
        """
        return list: 
        """
        winning_list = []
        for x in range(0, 3):
            col = []
            row = []
            for y in range(0, 3):
                col.append([x, y])
                row.append([y, x])
            winning_list.append(col)
            winning_list.append(row)
        winning_list.append([[0, 0], [1, 1], [2, 2]])
        winning_list.append([[2, 0], [1, 1], [0, 2]])
        return winning_list

    # 生成相应选手的棋子
    def chose(self, moves, turn):
        m = []
        for i in range(turn, len(moves), 2):
            m.append(moves[i])
        return m
```

就酱~~
