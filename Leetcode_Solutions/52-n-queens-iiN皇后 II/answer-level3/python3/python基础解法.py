### 解题思路
方法和51的N皇后一样，很来打算用count计数的，结果定义全局变量的时候报错，只好先用个list代替一下

### 代码

```python3
class Solution:
    def totalNQueens(self, n: int) -> int:
        res = [['.']*n for i in range(n)]
        col = [False] * 2 * n
        dg = [False] * 2 * n
        udg = [False] * 2 * n
        count_list = []

        def dfs(u):
            if u == n:
                count_list.append(1)
                return
            
            for i in range(n):
                if not col[i] and not dg[u+i] and not udg[n-u+i]:
                    res[u][i] = 'Q'
                    col[i] = dg[u+i] = udg[n-u+i] = True
                    dfs(u+1)
                    res[u][i] = '.'
                    col[i] = dg[u+i] = udg[n-u+i] = False
        
        dfs(0)
        return len(count_list)

```