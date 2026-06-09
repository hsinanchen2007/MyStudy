### 解题思路
主要是使用dfs的思想来做这道题，具体的思路可以看注释

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = list()
        res = [['.']*n for i in range(n)] # 保存最终的结果
        col = [False] *2*n # 指示某一列是否可以放元素
        dg = [False] *2*n # 指示对角线是否合法
        udg = [False] *2*n # 指示反对角线是否合法

        def dfs(u):
            list_1 = list()
            # 搜到一个可行答案
            if u == n:
                for i in range(n):
                    list_1.append(''.join(res[i]))
                ans.append(list_1)
                return
            
            # 判断应该在哪一列放皇后
            for i in range(n):
                if not col[i] and not dg[u+i] and not udg[n-u+i]:
                    res[u][i] = 'Q'
                    col[i] = dg[u+i] = udg[n-u+i] = True
                    dfs(u+1)
                    # 恢复现场
                    res[u][i] = '.'
                    col[i] = dg[u+i] = udg[n-u+i] = False
        
        # 从第0行开始搜
        dfs(0)
        return ans
```