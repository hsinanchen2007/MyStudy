1. 先创建一个字典，key是第一行，第二行。。。。第二列，第一方格，相当于有27个key。字典的value是当前行，列，方格已经存在的数。比如说 {（1，3）=【1，2，3】} 就代表第三列已经有1，2，3了
2. 剩下的自己看把
```
class Solution:
    '''
    用于判断当前位置位于哪个小方块内
    '''
    def whichcube(self, row, col):
        if row <= 2 and col <= 2:
            return 0
        elif row <= 2 and col <= 5:
            return 1
        elif row <= 2:
            return 2
        elif row <= 5 and col <= 2:
            return 3
        elif row <= 5 and col <= 5:
            return 4
        elif row <= 5:
            return 5
        elif col <= 2:
            return 6
        elif col <= 5:
            return 7
        else:
            return 8

    '''
    当我们分析完数独以后，会发现基于当前情况，很多空格都只有一种可能性，把这些只有一种可能性的空格更新进去
    '''
    def updateSudoku(self,board,hashmap,res):
        first_time = True
        markdown = 0
        while first_time or markdown != 0:
            first_time = False
            markdown = 0
            del_list = []
            for row, col in res:
                cube = self.whichcube(row, col)
                row_list = hashmap[(0, row)] if (0, row) in hashmap else []
                col_list = hashmap[(1, col)] if (1, col) in hashmap else []
                cube_list = hashmap[(2, cube)] if (2, cube) in hashmap else []

                sum_list = list(set(row_list).union(set(col_list)).union(set(cube_list)))
                ref = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
                final_list = list(set(ref).difference(set(sum_list)))
                if (len(final_list) == 1):
                    markdown += 1
                    board[row][col] = final_list[0]
                    hashmap[(0, row)].append(final_list[0])
                    hashmap[(1, col)].append(final_list[0])
                    hashmap[(2, cube)].append(final_list[0])
                    del_list.append((row, col))

                else:
                    res[(row, col)] = final_list
            for x in del_list:
                del res[x]

    
    '''
    先得到一个目前来说最优的数独，也就是说在循环之前，先把那些一定是这个数的空格先填上
    '''
    def getoptSudoku(self, board, hashmap,res):
        for row in range(9):
            for col in range(9):
                curr = board[row][col]
                cube = self.whichcube(row, col)
                if curr != '.':
                    if (0, row) in hashmap:
                        hashmap[(0, row)].append(curr)
                    else:
                        hashmap[(0, row)] = [curr]

                    if (1, col) in hashmap:
                        hashmap[(1, col)].append(curr)
                    else:
                        hashmap[(1, col)] = [curr]

                    if (2, cube) in hashmap:
                        hashmap[(2, cube)].append(curr)
                    else:
                        hashmap[(2, cube)] = [curr]

        for row in range(9):
            for col in range(9):
                curr = board[row][col]
                if curr == '.':
                    cube = self.whichcube(row, col)
                    row_list = hashmap[(0, row)] if (0, row) in hashmap else []
                    col_list = hashmap[(1, col)] if (1, col) in hashmap else []
                    cube_list = hashmap[(2, cube)] if (2, cube) in hashmap else []
                    sum_list = list(set(row_list).union(set(col_list)).union(set(cube_list)))
                    ref = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
                    final_list = list(set(ref).difference(set(sum_list)))
                    if (len(final_list) == 1):
                        board[row][col] = final_list[0]
                        hashmap[(0, row)].append(final_list[0])
                        hashmap[(1, col)].append(final_list[0])
                        hashmap[(2, cube)].append(final_list[0])
                    else:
                        res[(row, col)] = final_list


        self.updateSudoku(board,hashmap,res)


    '''
    用于循环未知的数，基本上就是一顿试
    '''
    def recusiveSolveSudoku(self, board, hashmap, res):
        if len(res) == 0:
            return True
        for row, col in res:
            cube = self.whichcube(row,col)
            values = res[row, col]
            for value in values:
                if (0, row) not in hashmap:
                    hashmap[(0, row)] = []
                if (1, col) not in hashmap:
                    hashmap[(1, col)] = []
                if (2,cube) not in hashmap:
                    hashmap[(2,cube)] = []

                if value in hashmap[(0, row)] or value in hashmap[(1, col)] or value in hashmap[(2, cube)]:
                    continue
                else:
                    hashmap[(0, row)].append(value)
                    hashmap[(1, col)].append(value)
                    hashmap[(2, cube)].append(value)
                    del (res[(row, col)])
                    board[row][col] = value
                    if self.recusiveSolveSudoku(board, hashmap, res):
                        return True
                    else:
                        res[(row, col)] = values
                        board[row][col] = '.'
                        hashmap[(0, row)].pop()
                        hashmap[(1, col)].pop()
                        hashmap[(2, cube)].pop()

            return False


    '''
    主程序
    '''
    def solveSudoku(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        #res是用来放置当前这个位置所有有可能的数
        #比如 res[(0,1)] = [3,8] 代表了(0,1)这个位置只有可能是3或者8
        res = {}
        # 0- row
        # 1- col
        # 2 - cube
        #hashmap代表了当前状态下，行，列，方块已经存在的数
        hashmap = {}
        self.getoptSudoku(board,hashmap,res)
        self.recusiveSolveSudoku(board,hashmap,res)
```
