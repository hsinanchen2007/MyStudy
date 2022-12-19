class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        i=0
        j=0
        sum1=-1#统计存活细胞周围其他存活细胞的个数，统计时会统计到自身因此初始为-1
        while j<len(board):#开始遍历数组，寻找数组中存活细胞的位置
            while i<len(board[j]):
                if board[j][i]==1:#找到存活的细胞
                    for u in range(-1,2):#对存活细胞周围进行遍历
                        if (j+u)>=0 and (j+u)<len(board):#保证不越界
                            for k in range(-1,2):
                                if (i+k)>=0 and (i+k)<len(board[j]):#保证不越界
                                    if board[j+u][i+k]<1:#只要这个位置没有活细胞就将他的数值减1
                                        board[j+u][i+k]-=1
                                    else:#统计存活细胞个数
                                        sum1+=1
                    else:
                        if sum1==2 or sum1==3:#判断是否满足存活条件
                            sum1=-1
                        else:#无法存活就将他数值修改大于1
                            sum1=-1
                            board[j][i]=2
                i+=1
            else:
                i=0
            j+=1
        i=0
        j=0
        while j<len(board):#对遍历一边后的数组进行整理，2表示下一个状态会死亡，-3表示可以复活
            while i<len(board[j]):
                if board[j][i]==2:#等于2表示没存活
                    board[j][i]=0
                elif board[j][i]<1:#小于1时，判断是否复活
                    if board[j][i]==-3:#等于-3可以复活
                        board[j][i]=1
                    else:
                        board[j][i]=0
                i+=1
            else:
                i=0
            j+=1

