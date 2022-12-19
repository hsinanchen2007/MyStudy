### 解题思路
参考自labuladong大神

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        track = []

        def isValid(track, row, col):
            if not track:
                return True
            for i in range(row):
                if track[i][col] == 'Q':  # 本列
                    return False
            i  = row - 1
            j  = col - 1
            while i >= 0 and j >= 0: #左上
                if track[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            i = row - 1
            j = col + 1
            while i >= 0 and j < n: # 右上
                if track[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            return True

        def backtrack(track, row):
            #ans = [.]*n 容易出错, 循环中,需要改回来
            #print(track)
            if len(track) == n:
                res.append(track[:])
                return
            for i in range(n):#n:col
                ans = ['.'] * n #改在这里,就不需要回退时处理了不然会出现[Q,Q]
                if isValid(track, row, i):
                    ans[i] = 'Q'
                    track.append(list(ans))
                    backtrack(track,row + 1)
                    track.pop()#这里除了需要还
        backtrack([], 0)
        res2 = [[] for _ in range(len(res))]
        for index,re in enumerate(res):
            for r in re:    
                r_str = "".join(r)
                res2[index].append(r_str)
            
        return res2
```