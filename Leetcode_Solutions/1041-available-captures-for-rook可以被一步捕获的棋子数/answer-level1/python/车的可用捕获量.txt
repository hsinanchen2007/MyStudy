### 解题思路
根据题意模拟即可：

遍历棋盘确定白色车的下标，用 (st,ed)(st,ed) 表示。

模拟车移动的规则，朝四个基本方向移动，直到碰到卒或者白色象或者碰到棋盘边缘时停止，用 \textit{cnt}cnt 记录捕获到的卒的数量。

那么如何模拟车移动的规则呢？我们可以建立方向数组表示在这个方向上移动一步的增量，比如向北移动一步的时候，白色车的 x 轴坐标减 1，而 y 轴坐标不会变化，所以我们可以用 (-1, 0) 表示白色车向北移动一步的增量，其它三个方向同理。建立了方向数组，则白色车在某个方向移动 \textit{step}step 步的坐标增量就可以直接计算得到，比如向北移动 \textit{step}step 步的坐标增量即为 (-step, 0)。

方向数组也可以根据相应的题意自行扩展，比如模拟象棋中马跳的坐标增量。


### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        cnt,st,ed = 0,0,0
        dx,dy = [0,1,0,-1],[1,0,-1,0]
        for i in range(8):
            for j in range(8):
                if board[i][j] == "R":
                    st,ed = i,j
        for i in range(4):
            step =0
            while True:
                tx = st + step * dx[i]
                ty = ed + step * dy[i]
                if tx < 0 or tx>=8 or ty<0 or ty>=8 or board[tx][ty] == "B":
                    break
                if board[tx][ty] == "p":
                    cnt += 1
                    break
                step +=1
        return cnt
                
                
                
```