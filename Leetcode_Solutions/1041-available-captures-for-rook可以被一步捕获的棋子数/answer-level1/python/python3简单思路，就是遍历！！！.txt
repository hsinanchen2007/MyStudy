### 解题思路
方法大概分为四步：找车位，遍历横轴，遍历纵轴，判定并累加
详细步骤见代码注释：

### 代码

```python3
class Solution:
    def numRookCaptures(self, board) -> int:
        index1 = 0#车的行号
        index2 = 0#车的列号
        num = 0#捕获量
        str_top = ""#车上方的标记量
        str_left = ""#车左边的标记量
        n = len(board)
        for i in range(n):#找车的位置
            if "R" in board[i]:
                index1 = i
                index2 = board[i].index("R")
        for j in range(n):#遍历车所在的纵轴
            if j < index1:
                if board[j][index2] == "B" or board[j][index2] == "p":
                    str_top = board[j][index2]
            if j > index1:
                if board[j][index2] == "B" or board[j][index2] == "p":
                    if board[j][index2] == "B":
                        break
                    if board[j][index2] == "p":
                        num += 1
                        break
        for k in range(len(board[index1])):#遍历车所在的横轴
            if board[index1][k] == "B" or board[index1][k] == "p":
                if k < index2:
                    str_left = board[index1][k]
                elif k > index2:
                    if board[index1][k] == "B":
                        break
                    if board[index1][k] == "p":
                        num += 1
                        break
        #这两个遍历思路是一样的，我那横轴举例，固定车的行号，在车所在的行进行遍历
        #从左至右，我们需要找的是以车为中心两边离车最近的是“B”还是“p”，这里我分了左右两种情况讨论
        #左边：用目标变量记录B或p，最后检验目标变量即可
        #右边：只要第一个碰到B或者p立刻返回
        #遍历车的纵轴如法炮制即可
        #ps：我两个循环判断语句略有不同，第一个稍显拉杂，大家可以相应对比
        if str_left == "p":
            num += 1
        if str_top == "p":
            num += 1
        return num