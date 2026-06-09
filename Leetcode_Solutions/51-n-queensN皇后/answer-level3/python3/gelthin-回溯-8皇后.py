### 解题思路
同习题 [面试题 08.12. 八皇后](https://leetcode-cn.com/problems/eight-queens-lcci/solution/gelthin-hui-su-fa-jie-ba-huang-hou-deepcopy-nonloc/)

回溯 效率好低， 20*20 无法解。超时。
之前好像是 liweiwei 大神分析了一下回溯的复杂度，超难分析，超复杂。

这里小改了一下先前的代码：
1. avai 作为参数传递
2. 对角线和反对角线，一直延伸横跨整个矩阵




### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # 同后面习题
        def dfs(tmp, i, avai):
            if len(tmp) == n:
                res.append(tmp)
            if i>=n or not any(avai[i]):  # i 超界，或者 这一行都不可取
                return False
            for j in range(n):
                if avai[i][j]:
                    import copy
                    tmp_avai = copy.deepcopy(avai)
                    # 行列
                    for k in range(n):
                        avai[i][k] = False
                        avai[k][j] = False

                    k = -min(i, j) # 从左上到右下
                    while 0<=i+k<n and 0<=j+k<n:
                        avai[i+k][j+k] = False
                        k += 1
                    
                    k = -min(i, n-1-j)  #从右上到左下
                    while 0<=i+k<n and 0<=j-k<n:
                        avai[i+k][j-k] = False
                        k += 1
                    
                    dfs(tmp+[[i,j]], i+1, avai)
                    avai = tmp_avai

        avai = [[True]*n for _ in range(n)]
        res = []
        dfs([], 0, avai)
        
        result = []
        for x in res:
            tmp = []
            for i,j in x:
                tmp.append('.'*j+'Q'+'.'*(n-1-j))
            result.append(tmp)
        return result

## 回溯 效率好低， 20*20 无法解。超时


```