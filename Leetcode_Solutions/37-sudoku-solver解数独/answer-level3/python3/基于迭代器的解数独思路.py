### 解题思路
核心思路是不停地迭代二维数组,直到找出解
三个函数fill_single,get_two,check代码重复较多,还有优化空间

### 代码

```python3
from copy import deepcopy

class Solution:
    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        self.board = board
        self.run()

    @staticmethod
    def get_cube(map_, r, c):
        list01 = []
        if r < 3:
            r0 = 0
        elif r < 6:
            r0 = 3
        else:
            r0 = 6
        if c < 3:
            c0 = 0
        elif c < 6:
            c0 = 3
        else:
            c0 = 6

        for r in range(r0, r0 + 3):
            for c in range(c0, c0 + 3):
                list01.append(map_[r][c])
        return list01

    def fill_single(self, map_):

        while True:
            map_copy = deepcopy(map_)
            for r in range(len(map_)):
                for c in range(len(map_[0])):
                    if map_[r][c] == '.':
                        number_list = self.get_number_list(r, c, map_)
                        if len(number_list) == 1:
                            map_[r][c] = number_list[0]
            if map_copy == map_:
                count = sum([row.count('.') for row in map_])
                if not count:
                    return map_
                break

    def get_number_list(self, r, c, map_):
        all_ = ['.', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        row = map_[r]
        column = [row[c] for row in map_]
        cube = self.get_cube(map_, r, c)
        re = set(row + column + cube)
        number_list = [n for n in all_ if n not in re]
        return number_list

    def get_two(self, map_):
        for r in range(len(map_)):
            for c in range(len(map_[0])):
                if map_[r][c] == '.':
                    number_list = self.get_number_list(r, c, map_)
                    if len(number_list) == 2:
                        map_[r][c] = number_list[0]
                        map01 = deepcopy(map_)
                        map_[r][c] = number_list[1]
                        map02 = deepcopy(map_)
                        map_[r][c] = '.'
                        return map01, map02

    def check(self, map_):
        for r in range(len(map_)):
            for c in range(len(map_[0])):
                if map_[r][c] == '.':
                    number_list = self.get_number_list(r, c, map_)
                    if len(number_list) == 0:
                        return False
        return True

    def core(self):
        main_list = [self.board]
        for index, map_ in enumerate(main_list):
            # main_list[index] = None
            if self.fill_single(map_):
                self.board[:] = map_
                return
            if not self.check(map_):
                continue
            main_list += self.get_two(map_)

    def run(self):
        self.core()
```