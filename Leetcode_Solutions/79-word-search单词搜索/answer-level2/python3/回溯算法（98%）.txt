不加par(模式判断，判断是否有可能组成word)时间是600ms,加了以后速度提升到250ms(98%)
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if word == "":
            return False
        m = len(board)
        if m == 0:
            return False
        n = len(board[0])
        if n == 0:
            return False
        par = {}
        dic = {}
        count = 0
        for i in word:
            if i not in par:
                par[i] = 1
                dic[i] = [0,[]]
                count += 1
            else:
                par[i] += 1
        for i in range(m):
            for j in range(n):
                tem = board[i][j]
                if tem in dic:
                    dic[tem][0] += 1
                    dic[tem][1].append([i,j])
                    if dic[tem][0] == par[tem]:
                        count -= 1
        if count > 0:
            return False
        l = len(word)
        if l == 1:
            return True
        def solve(cor,i,queue):
            tem = dic[word[i]]
            mode = [cor[0],cor[1] + 1]
            re = False
            if mode not in queue and mode in tem[1]:
                if i == l-1:
                    return True
                re = solve(mode,i+1,queue + [mode])
            if re == False:
                mode = [cor[0],cor[1] - 1]
                if mode not in queue and mode in tem[1]:
                    if i == l-1:
                        return True
                    re = solve(mode,i+1,queue + [mode])
            if re == False:
                mode = [cor[0]-1,cor[1]]
                if mode not in queue and mode in tem[1]:
                    if i == l-1:
                        return True
                    re = solve(mode,i+1,queue + [mode])
            if re == False:
                mode = [cor[0]+1,cor[1]]
                if mode not in queue and mode in tem[1]:
                    if i == l-1:
                        return True
                    re = solve(mode,i+1,queue + [mode])
            return re

        for i in range(dic[word[0]][0]):
            tem = dic[word[0]][1][i]
            if solve(tem,1,[tem]) == True:
                return True
        return False
```
