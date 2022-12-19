解题思路：
1. 先生成一个表示棋盘位置是否可用的标志二位数组
2. 根据标志二维数组生成一个棋盘的邻接数可用的个数的状态数组，每个棋子最多由上下左右四个邻接，因此值为0~4
3. 先将状态数组中值为1的位置将与他相连的可用位置与他本身的标志为设为不可用，且将可放卡牌数加1
4. 将这两个位置相邻的可用的位置的状态值减1，并且如果状态值变更为1，则也要将该位置与其唯一相邻的位置标志位1，递归这个过程
5. 完成之后，状态数组中只由大于1的状态值还可用，此时遍历可用的位置
6. 随机将该位置与他相邻的位置组合，更新可用标识和相邻的可用位置的状态，同时如果相邻的位置的状态为1，则递归将该位置与相邻的进行匹配
7. 遍历完成后，则可以返回结果了

效率问题：
1. 处理邻接为1的复杂度为O(nm).因为对于每个元素，找到邻接元素为最多4次操作，组合后更新邻接状态，为6次操作。递归组合邻接元素，因为元素的个数确定，因此递归次数最多为nm，因此复杂度为O(nm)
2. 处理邻接大于1的复杂度也为O（nm）
3. 因此最终复杂对为O(nm),空间也为O(nm)

```
class Solution:
    moves = [[0, 1], [1, 0], [-1, 0], [0, -1]]
    count=0

    def domino(self, n: int, m: int, broken: List[List[int]]) -> int:
        self.n=n
        self.m=m
        self.mark = [[1 for i in range(m)] for j in range(n)]
        self.stat = [[1 for i in range(m)] for j in range(n)]
        # 初始化位置可用信息
        for b in broken:
            self.mark[b[0]][b[1]] = 0
        # 初始化位置的邻接可用个数信息 O(nm)
        for i in range(n):
            for j in range(m):
                self.stat[i][j] = self.sumStat(i, j)
        # 先处理邻接可用为1的位置，让他与唯一的位置组合
        for i in range(n):
            for j in range(m):
                self.flashChain(i, j)
        # 剩下邻接大于1的位置，随机与邻接位置组合，如果无法组合则直接标志为不可用
        for i in range(n):
            for j in range(m):
                if self.mark[i][j] == 1:
                    ci, cj = self.getFlashMember(i, j)
                    self.mark[i][j] = 0
                    if ci is not None:
                        self.mark[ci][cj] = 0
                        self.count+=1
                        self.reduceNeighbour(i, j)
                        self.reduceNeighbour(ci, cj)
        return self.count
    # 计算位置的邻接可用个数
    def sumStat(self, i, j):
        result = 0
        for move in self.moves:
            ii, jj = i + move[0], j + move[1]
            if ii < self.n and jj < self.m  and ii >=0 and jj >=0:
                result = result + self.mark[ii][jj]
        return result
    # 对邻接可用个数为1的数据进行组合
    def flashChain(self, i, j):
        if self.mark[i][j] != 0:
            if self.stat[i][j] == 1:
                ci, cj = self.getFlashMember(i, j)
                self.mark[i][j] = 0
                if ci is not None:
                    self.mark[ci][cj] = 0
                    self.count+=1
                    if self.stat[ci][cj] > 1:
                        self.reduceNeighbour(ci, cj)
    # 找一个位置可用使用的邻接位置进行组合
    def getFlashMember(self, i, j):
        for move in self.moves:
            ii, jj = i + move[0], j + move[1]
            if ii > self.n - 1 or jj > self.m - 1 or ii < 0 or jj < 0:
                continue
            if self.mark[ii][jj] == 1:
                return ii, jj
        return None,None
    # 减少邻接位置的状态数，并且如果状态值为1，则需要进行组合
    def reduceNeighbour(self, i, j):
        for move in self.moves:
            ii, jj = i + move[0], j + move[1]
            if ii > self.n - 1 or jj > self.m - 1 or ii < 0 or jj < 0:
                continue
            self.stat[ii][jj] = self.stat[ii][jj] - 1
            if self.stat[ii][jj] == 1:
                self.flashChain(ii, jj)

```