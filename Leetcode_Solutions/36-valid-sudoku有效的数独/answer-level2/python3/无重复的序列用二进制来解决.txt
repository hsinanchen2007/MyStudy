如果是有效的数独，那么每行、每列、每个子方格里的数都不重复，因此用二进制来编码这些不重复的数。
虽然时间和内存消耗比不上hash，但是想法直观，代码也比较简单。

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        if not board:   return False
        
        rows=[0 for i in range(9)]
        cols=[0 for j in range(9)]
        boxes=[0 for i in range(9)]
        
        for i in range(9):
            for j in range(9):
                temp = board[i][j]
                if temp!='.':
                    temp = int(temp)
                    if rows[i]&(1<<temp):   return False
                    else:   rows[i] = rows[i] | (1<<temp)
                    if cols[j]&(1<<temp):   return False
                    else:   cols[j] = cols[j] | (1<<temp)
                    box_index = i//3 * 3 + j//3
                    if boxes[box_index]&(1<<temp):   return False
                    else:   boxes[box_index] = boxes[box_index] | (1<<temp)
                        
        return True