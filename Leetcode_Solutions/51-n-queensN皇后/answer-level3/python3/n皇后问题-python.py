```
class Solution:
    def solveNQueens(self, n: int):
        #不能使得他们在同一直线上或者对角线上
        res = []
        def conflict(queen_str,cur_queen):
            queen_length=len(queen_str)
            for index in range(queen_length):
                if abs(cur_queen-int(queen_str[index])) in (0,queen_length-index):# 如果当前的公主-以及存在的公主位置，在 0或公主长度-index的时候说明其在一条线上或者是对角线。
                    return True
            return False

        def back(queen_str):
            if len(queen_str)==n:
                res.append(queen_str)
                return
            for index in range(n):
                Flag = conflict(queen_str,index)
                if not Flag:
                    back(queen_str+str(index))
        def printQueen(res):
            final = []
            if res==[]:return []
            queen_len=len(res[0]) # n
            for i in res:# i种解法 用字符串存储
                tmp = ["."*queen_len for _ in range(queen_len)]
                for x,y in enumerate(i):
                    y=int(y)
                    tmp[x] = tmp[x][:y] + "Q" + tmp[x][y + 1:]
                final.append(tmp)
            return final
        back("")
        return printQueen(res)
#
```
