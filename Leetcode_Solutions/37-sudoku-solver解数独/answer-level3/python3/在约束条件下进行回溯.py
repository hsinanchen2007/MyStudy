这道题最麻烦的地方就是对于难度较大的数独题目，有些空格是存在多个候选值可以填入的，如果直接修改board,那么我们需要每次记录修改的位置。最简单的办法是考虑复制一下board,但是复制的时候，需要注意一下，不能直接用等号，或者例如： a = board.copy()这类格式，因为这样在对a进行修改时，我们依然是在对board进行修改，其根本原因在于，board是个二维列表，如果真的要完全复制，需要从最底层的列表开始复制。
在复制完成后，就可以试验性地将多个候选值之一填入，并继续往下走，如果要形容就是树的深度遍历，如果发现可以填完所有空缺，那么，恭喜你，你找到了正确的途径
否则，我们需要继续试验。在试验中，可能还会涉及下一次多个候选值情况，因此直接采用递归比较方便
这里有两个注意点：
1.候选值的约束条件尽可能地严格（我是从行、列不能重复以及九宫格内无重复三点考虑的）
2.先把唯一确定的值定下来，再考虑多个候选值值填入同一个空格的情况。
小白一枚，请多多指教
```
class Solution:
    def find_solve(self, board,dic,blank,remain):
        flag = False
        while(remain > 0):
            tem = remain
            for j in range(9):
                for i in range(9):  
                    if  board[i][j] == '.':
                        index = (i//3)+(j//3)*3
                        candidate = []
                        for k in blank[index]:
                            if k != -1 and dic[k][0][i] != -1 and dic[k][1][j] != -1:
                                candidate.append(k)
                        l = len(candidate)
                        if l == 1:
                            re = candidate[0]
                            board[i][j] = str(re)
                            dic[re][0][i] = -1
                            dic[re][1][j] = -1
                            blank[index][re - 1] = -1
                            remain -= 1  
                        elif l == 0:
                            return False
                        elif flag:
                            for v in candidate:
                                a = []
                                b = {}
                                c = {}
                                for d in range(9):
                                    a.append(board[d].copy())
                                    c[d] = blank[d].copy()
                                    d += 1
                                    b[d] = [dic[d][0].copy(),dic[d][1].copy()]                                   
                                a[i][j] = str(v)
                                b[v][0][i] = -1
                                b[v][1][j] = -1
                                c[index][v - 1] = -1
                                return self.find_solve(a,b,c,remain-1)                
            if tem == remain:
                flag = True
        return board

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dic ={}
        blank = {}   #每个九宫格缺的数字
        l = [1,2,3,4,5,6,7,8,9]
        remain = 0
        for i in l:
            dic[i] = [l.copy(),l.copy()]  #每个数字能够填放的位置（i,j）
            blank[i - 1] = l.copy()
        for j in range(9):
            for i in range(9):    #i行j列
                obj = board[i][j]
                if  obj != '.':
                    obj = int(obj)
                    dic[obj][0][i] = -1
                    dic[obj][1][j] = -1
                    blank[(i//3)+(j//3)*3][obj - 1] = -1
                else:
                    remain += 1
        flag = False
        while(remain > 0):
            tem = remain
            for j in range(9):
                for i in range(9):    #i行j列
                    if remain > 0 and board[i][j] == '.':
                        index = (i//3)+(j//3)*3
                        candidate = []
                        for k in blank[index]:
                            if k != -1 and dic[k][0][i] != -1 and dic[k][1][j] != -1:
                                candidate.append(k)
                        l = len(candidate)
                        if l == 1:
                            re = candidate[0]
                            board[i][j] = str(re)
                            dic[re][0][i] = -1
                            dic[re][1][j] = -1
                            blank[index][re - 1] = -1
                            remain -= 1
                        elif flag:
                            for v in candidate:
                                a = []
                                b = {}
                                c = {}
                                for d in range(9):
                                    a.append(board[d].copy())
                                    c[d] = blank[d].copy()
                                    d += 1
                                    b[d] = [dic[d][0].copy(),dic[d][1].copy()]                                   
                                a[i][j] = str(v)
                                b[v][0][i] = -1
                                b[v][1][j] = -1
                                c[index][v - 1] = -1
                                re = self.find_solve(a,b,c,remain-1)
                                if re != False:
                                    for u in range(9):
                                        board[u] = re[u]
                                    remain = 0
                                    break
            if tem == remain:
                flag = True                     
```
