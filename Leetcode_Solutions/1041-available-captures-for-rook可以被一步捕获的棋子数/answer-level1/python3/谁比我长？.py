### 解题思路
暴力法
1.遍历一遍，找到车的坐标
2.在车所在的行设置双指针进行前后查找，遇到'B'，结束这一指针的查找，遇到'p'，计数器+1，并结束这一指针查找，因为一个指针最多遇到一个'p'
3.在车的所在列进行同第二步的查找.
4.返回计数器
### 代码

```python3
class Solution:
    def numRookCaptures(self, board) -> int:
        rrow = 0
        rcol = 0
        for i in range(7):
            for j in range(7):
                if board[i][j] == 'R':
                    rrow = i
                    rcol = j
                    break
        tmprow1 = tmprow2 = rrow
        tmpcol1 = tmpcol2 = rcol
        count = 0
        flag_tmprow1 = True
        flag_tmprow2 = True
        flag_tmpcol1 = True
        flag_tmpcol2 = True
        while flag_tmprow1 or flag_tmprow2:
            if flag_tmprow1:
                if board[tmprow1][rcol] == 'B':
                    flag_tmprow1 = False

                if board[tmprow1][rcol] == 'p':
                    count += 1
                    flag_tmprow1 = False
            if flag_tmprow2:
                if board[tmprow2][rcol] == 'p':
                    count += 1
                    flag_tmprow2 = False
                if board[tmprow2][rcol] == 'B':
                    flag_tmprow2 = False
            tmprow1 -= 1
            tmprow2 += 1
            if tmprow1==-1:
                flag_tmprow1=False
            if tmprow2==8:
                flag_tmprow2 = False
        while flag_tmpcol1 or flag_tmpcol2:
            if flag_tmpcol1:

                if board[rrow][tmpcol1] == 'B':
                    flag_tmpcol1 = False

                if board[rrow][tmpcol1] == 'p':
                    count += 1
                    flag_tmpcol1 = False
            if flag_tmpcol2:
                if board[rrow][tmpcol2] == 'p':
                    count += 1
                    flag_tmpcol2 = False
                if board[rrow][tmpcol2] == 'B':
                    flag_tmpcol2 = False
            tmpcol1 -= 1
            tmpcol2 += 1
            if tmpcol1==-1:
                flag_tmpcol1=False
            if tmpcol2==8:
                flag_tmpcol2=False
        return count      
            

             


```