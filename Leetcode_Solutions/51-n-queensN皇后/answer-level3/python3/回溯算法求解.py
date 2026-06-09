### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def solveNQueens(self, n):
        res, path = [], []
        visit = [0 for i in range(n)]
        self.BackTracking(n, res, path, visit)
        result = []
        temp = []
        for re in res:
            for i in range(n):
                temp.append("." * re[i] + "Q" + "." * (n - re[i] - 1))
            result.append(temp)
            temp = []
        return result

    def BackTracking(self, n, res, path, visit):
        if len(path) == n:
            res.append(path[:])
            return
        for i in range(n):
            if visit[i] == 0 and len(path) < n and (path == [] or (path != [] and abs(i - path[-1]) > 1)) :
                path.append(i)
                if self.JudgeReasonable(path, n) :
                    visit[i] = 1
                    self.BackTracking(n, res, path, visit)
                    path.pop()
                    visit[i] = 0
                else:
                    path.pop()
            else:
                if len(path) == n:
                    return
                else:
                    continue

    def JudgeReasonable(self, path, n):
        # row是path中元素的个数,也是行数
        row = len(path)
        status = [[0 for i in range(n)] for i in range(row)]
        for i, value in enumerate(path):
            status[i][value] = 1
        for i in range(len(path)):
            x, y = i, path[i]
            for m in range(row):
                for k in range(n):
                    if m != x and k != y and status[m][k] != 0 and abs(m - x) == abs(k - y):
                        return False
        return True

```