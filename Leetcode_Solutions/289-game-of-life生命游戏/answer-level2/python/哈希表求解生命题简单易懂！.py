### 解题思路
第一次中等难度的题没看题解也一次提交通过的！！！
这道题如果读懂题意的话就很好做了。要求按照board初始细胞状态，找到下一个状态。
最简单的想法是将board复制一份，然后考虑board中的每一个格子，参照复制的board（因为原来的board会发生变化）统计周围八个方位的活细胞数量，根据题目给出的规则改变格子细胞的状态即可。但是题目要求用原地算法求解，也就是说，不能这么简单粗暴地复制一份board。
于是转换思路，想到了字典。
思路是：
1、用字典来统计每个格子周围的活细胞的数量，格子坐标为key,活细胞数量为value
2、对于字典中的每一个格子，按照题目给出的规则来改变格子中细胞的状态

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) < 1:
            return
        #对照着初始的状态，按照这四个规则找下一个状态
        #先将board复制一份，然后更改board的状态
        #但是本题需要用到原地算法求解
        #可以定义一个字典，key为节点（i,j）,值为周围活细胞的数量，然后根据字典的值来更新board
        
        dx = [0,0,1,1,-1,-1,1,-1]
        dy = [1,-1,0,-1,0,1,1,-1] #8个方位
        n = len(board)
        m = len(board[0])
        dic = {}

        for i in range(n):
            for j in range(m):
                live = 0
                for k in range(8):
                    next_i, next_j = i+dx[k],j+dy[k]
                    if next_i < 0 or next_i==n or next_j < 0 or next_j == m :
                        continue
                    if board[next_i][next_j] == 1:
                        live += 1

                dic[(i,j)] = live
        for (i, j) in dic.keys():
            if board[i][j] == 1:#活细胞
                if dic[(i,j)] < 2 or dic[(i,j)] > 3:
                    board[i][j] = 0 #活细胞死亡
            else: #死细胞
                if dic[(i,j)] == 3:
                    board[i][j] = 1 #死细胞复活



```