首先分析一下题目，车可以朝上下左右四个方向移动，移动的路径上面有卒就可以捕捉，前提是没有象挡住，而且同一方向只能捕捉一个卒
意思就是，我们只需要找到多少个车和卒可以直接相连没有阻碍的就行了。

题目上面有一句话可能会比较误导大家：**返回车能够在一次移动中捕获到的卒的数量。**
但结合给出的示例来看，其实是要求出每次可以吃到卒的方法有几种

方法一：
先找出车（R）的位置
再找出卒（p）的位置
同样象（B）的位置也找出来

所有的棋子的坐标都找出来之后，我们再看一下车和每个卒之间有没有阻碍，有阻碍的就舍弃掉不能捕捉，没有阻碍的就可以捕捉result+1
```
class Solution1(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        '''
        board.length == board[i].length == 8
        board[i][j] 可以是 'R'，'.'，'B' 或 'p'
        只有一个格子上存在 board[i][j] == 'R'
        '''
        '''
        R : 车
        B ： 象
        p ： 车
        '''
        # 先找出 R 的坐标
        R_index = [(line, index) for line in range(8) for index in range(8) if board[line][index] == 'R'][0]
        # 找出 B 的坐标
        B_index = [(line, index) for line in range(8) for index in range(8) if board[line][index] == 'B']
        # 找出 p 的坐标
        p_index = [(line, index) for line in range(8) for index in range(8) if board[line][index] == 'p']
        # 先忽略B的存在,找出能被 R 捕捉到的 p
        catch_p = [row for row in p_index if row[0] == R_index[0] or row[1] == R_index[1]]
        # R和p之间那些可能被遮挡的点
        result = 0
        for row in catch_p:
            # 当R和p在同一排
            if row[0] == R_index[0]:
                before, after = min(row[1], R_index[1]), max(row[1], R_index[1])
                # 计算有无遮挡
                occlude = [(row[0], i) for i in range(before + 1, after) if
                           (row[0], i) in B_index or (row[0], i) in catch_p]
                # 如果没有被遮挡则可以捕捉
                if not occlude: result += 1
            # 当R和p在同一列
            if row[1] == R_index[1]:
                before, after = min(row[0], R_index[0]), max(row[0], R_index[0])
                occlude = [(i, row[1]) for i in range(before + 1, after) if
                           (i, row[1]) in B_index or (i, row[1]) in catch_p]
                if not occlude: result += 1
        return result

```

方法二：
这个方法和1有点类似，但出发点不同
这里我们只需要找出车(R)的位置，再从R的位置开始朝上下左右四个方向进攻
如果前进的过程碰到了象（B）那这条路就走不通了
如果前进的时候没有遇到象，然后捕捉到了一个卒（p），那么在这条路上的进攻也就结束了，因为每条路只能捕捉一个卒
```
class Solution2(object):
    def numRookCaptures(self, board):
        R_index = [(line, index) for line in range(8) for index in range(8) if board[line][index] == 'R'][0]
        row_index, clo_index = R_index[0], R_index[1]
        print(R_index)
        # 从R的上下左右扩散寻找
        result = 0
        # 上
        for row in range(row_index - 1, -1, -1):
            if board[row][clo_index] == 'p':
                result += 1
                break
            elif board[row][clo_index] == 'B':
                break
        # 下
        for row in range(row_index + 1, 8):
            if board[row][clo_index] == 'p':
                result += 1
                break
            elif board[row][clo_index] == 'B':
                break
        print(result)
        # 左
        for clo in range(clo_index - 1, -1, -1):
            if board[row_index][clo] == 'p':
                result += 1
                break
            elif board[row_index][clo] == 'B':
                break
        # 右
        for clo in range(clo_index + 1, 8):
            if board[row_index][clo] == 'p':
                result += 1
                break
            elif board[row_index][clo] == 'B':
                break
        return result

```

方法三：
这个方法相比前面两个有点取巧，但是中心思想还是不变，就是找到车和卒相邻即"pR"或"Rp"即可

首先是横向搜索，将每横的棋子连起来，然后再将所有横的棋子连起来，因为每横的棋子是要分开搜索的所以我这里用了“，”隔开。
然后是纵向搜索，同样是将每列的棋子连起来，然后再找出pR和Rp
在纵向搜索的时候，我是先把矩阵进行了转置即将棋盘旋转了90度，然后如再按横向搜索的方法进行查找。
```
class Solution3(object):
    def numRookCaptures(self, board):
        # 横向数据组成字符串
        rowStr = ','.join([''.join(row).replace('.', '') for row in board])
        # 将矩阵转置一下
        board = [[row[i] for row in board] for i in range(8)]
        # 纵向数据组成字符串
        cloStr = ','.join([''.join(row).replace('.', '') for row in board])
        return sum([rowStr.count("pR"), rowStr.count("Rp"), cloStr.count("pR"), cloStr.count("Rp")])
```

