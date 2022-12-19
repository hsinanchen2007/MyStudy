### 解题思路
![image.png](https://pic.leetcode-cn.com/d088fc0c2f0f5cf9a0c11299a8d348a14c3a66c2f7a4bd56d4453c3d1086ac45-image.png)
基本回溯就不说了，我在回溯之前加了个扫描，先把所有可以直接求解的解出来，可以成倍的减少回溯次数。

### 代码

```python3
NUM = [str(x) for x in range(1, 10)]
class Solution:
    def solveSudoku(self, in_board: list) -> None:
        pre = self.file_the_singlesolu_hole(in_board) # 把能填的先填上减少回溯
        # 新建可用列表
        avaliable_row = [set(str(x) for x in range(1, 10)) for _ in range(9)]
        avaliable_col = [set(str(x) for x in range(1, 10)) for _ in range(9)]
        avaliable_cube = [set(str(x) for x in range(1, 10)) for _ in range(9)]
        empty_hole = [(i, j) for i in range(9) for j in range(9) if in_board[i][j] == '.']  # local to file
        for i in range(9):  # 更新可用列表
            for j in range(9):
                if in_board[i][j] != '.':
                    avaliable_row[i].remove(in_board[i][j])
                    avaliable_col[j].remove(in_board[i][j])
                    avaliable_cube[(i//3)*3+j//3].remove(in_board[i][j])
        def getback(times):  # 填充次数等于洞洞长度就是整完了，返回
            if times == len(empty_hole):
                return True
            i, j = empty_hole[times]
            for to_file in avaliable_row[i] & avaliable_col[j] & avaliable_cube[(i//3)*3+j//3]:
                avaliable_row[i].remove(to_file)
                avaliable_col[j].remove(to_file)
                avaliable_cube[(i//3)*3+j//3].remove(to_file)
                in_board[i][j] = to_file
                if getback(times+1):
                    return True
                # 回溯
                avaliable_row[i].add(to_file)
                avaliable_col[j].add(to_file)
                avaliable_cube[(i//3)*3+j//3].add(to_file)
            return False

        getback(0)


    def file_the_singlesolu_hole(self, in_board: list):  # 把能填的填上,直到需要猜
        temp = 81
        while True:
            num_of_black = 0
            for i in range(len(in_board)):
                for j in range(len(in_board[0])):
                    if in_board[i][j] == '.':
                        solut = self.get_solu(i, j, in_board)
                        if len(solut) == 1:
                            in_board[i][j] = solut[0]
                        else: num_of_black += 1
            if num_of_black < temp: temp = num_of_black
            else: break
        return True

    def get_solu(self, i, j, in_board):  # 给一个坐标，得到该点可能的解
        row = [x for x in in_board[i] if x != '.']
        clo = [x for x in list(zip(*in_board))[j] if x != '.']
        cube = [in_board[3*(i//3)+m][3*(j//3)+n] for m in range(3) for n in range(3)
                if in_board[3*(i//3)+m][3*(j//3)+n] != '.']
        return [x for x in NUM if x not in (*row, *clo, *cube)]

    def sudoku_print(self, in_board: list):  # 用来打印
        for _ in in_board:
            print(_)
```