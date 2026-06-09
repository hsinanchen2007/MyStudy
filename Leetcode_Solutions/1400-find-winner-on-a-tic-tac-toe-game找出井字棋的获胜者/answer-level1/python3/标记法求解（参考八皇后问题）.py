设立好标记数组，只要数组中某一行某一列或者某一对角线上的数为3就获胜
```Python3
class Solution:
    def judge(self, x, y, nums):
        nums[0][x] += 1
        nums[1][y] += 1
        if x == y:
            nums[2][y - x] += 1
        if y + x == 2:
            nums[3][y + x] += 1

    def Check(self, nums) -> bool:
        for x in nums:
            for y in x:
                if y == 3:
                    return True
        return False

    def tictactoe(self, moves: List[List[int]]) -> str:
        flag = True
        """
        judge 第一组代表行
        judge 第二组代表列
        judge 第三组代表右对角线
        judge 第四组代表左对角线
        """
        judgeA = [[0] * 3 for i in range(4)]
        judgeB = [[0] * 3 for i in range(4)]
        for coordinate in moves:
            if flag:
                self.judge(coordinate[0], coordinate[1], judgeA)
                flag = False
            else:
                self.judge(coordinate[0], coordinate[1], judgeB)
                flag = True
        if self.Check(judgeA):
            return "A"
        if self.Check(judgeB):
            return "B"
        if len(moves) == 9:
            return "Draw"
        else:
            return "Pending"

```
