我们的思路是用两个for循环来寻找可能的头，一旦头找到了，就进入DFS（回朔法）
但是这里需要注意三个问题：

1. privacy leak：
    这个问题太过于关键，对于python而言，只要是mutable variable，不管你是作为传参也好，还是直接赋值也好，都是通过赋值物理地址，这就导致了，无论你更改哪个相关变量，原变量都会发生改变。也就是说，privacy leak就一定会发生

    我们可以选择通过copy来避免privacy leak的发生：
    但由于参数都是两层的list， copy（浅复制）没有什么用。
    但是通过deepcopy 耗时巨大，且内存消耗严重

但是我们反而可以利用privacy leak 实现一个全局变量的功能。
        我们之所以可以这么做是因为，我们总归只要找到一个track就行了，因此我们不需要记录多组track，那么我们也就不需要多组path tracking来分别记录track
    
2. 回朔法的结构：
    回朔法的结构并不局限于：
    if -> 出口
    for -> 同一层的循环
    
    回朔法的本质还是在于层层递归而已，只要能实现层层递归即可。
    
    这里我们实现的方式是通过 if的堆叠来实现的。
    
    但是一定要注意回朔的基本结构：
        判定于记录数据
        递归向更深处走
        回朔清理！！        回朔清理太重要了！！！！一定要做好清理工作。回朔清理是为了当回退的时候，能把走错的路的痕迹抹去。

3. 递归的终止：
    递归中return只能返回，并不能终止递归！！！ 当return执行了以后，只是终止了当前层的继续执行，上一层的内容还要继续。你没办法停的
    
    因此递归的shut down变的很重要， 递归关闭的方法通常有两种：
    1. 用exception，但是这回大量占用内存和时间
    2. 建立全局标志位！ 而后层层递归！！（最常用的代价小的终止递归的方法）
        这就需要在每个递归结束的位置都要判定递归标志位。


```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        break_signal = False
        path_tracking = [[False for _ in range(len(board[0]))] for _ in range(len(board))]

        for x in range(len(board)):
            for y in range(len(board[0])):
                if board[x][y] == word[0]:
                    res = self.__DFS(board, word, x, y, path_tracking, break_signal)
                    if res is True:
                        return True
                    path_tracking[x][y] = False  # 这里也要做回朔清理
        return False

    def __DFS(self, board:List[List[str]], word:str, x:int, y:int, path_tracking: List[List[str]], signal):
        global break_signal
        break_signal = signal
        #test
        cur = board[x][y]

        if len(word) == 1 and board[x][y] == word[0]:
            break_signal = True
            return True
        if break_signal: return True

        if board[x][y] == word[0]: # 若当前位置符合标准
            path_tracking[x][y] = True  # 更改tracking

            if x-1 >= 0 and (path_tracking[x - 1][y] == False):
                self.__DFS(board,word[1:],x-1,y,path_tracking, False)
                path_tracking[x - 1][y] = False  # 回朔清理
            if break_signal: return True

            if x+1 < len(board) and (path_tracking[x + 1][y] == False):
                self.__DFS(board, word[1:], x+1, y, path_tracking, False)
                path_tracking[x + 1][y] = False
            if break_signal: return True

            if y-1 >= 0 and (path_tracking[x][y-1] == False):
                self.__DFS(board, word[1:], x, y-1, path_tracking, False)
                path_tracking[x][y - 1] = False
            if break_signal: return True

            if y+1 < len(board[0]) and path_tracking[x][y+1] == False:
                self.__DFS(board,word[1:],x,y+1,path_tracking, False)
                path_tracking[x][y + 1] = False
            if break_signal: return True

```
