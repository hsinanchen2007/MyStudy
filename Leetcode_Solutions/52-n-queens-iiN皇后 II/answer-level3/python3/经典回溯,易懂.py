
# 1.回溯法
![image.png](https://pic.leetcode-cn.com/457e7638032c8bcfd4baa46a38b7af83ea3ef05c0d0464d205a07902547c21cf-image.png)

```py
class Solution:
    def totalNQueens(self, n: int) -> int:
        chessboard=[0]*(n+1) #建立棋盘,index代表列,值代表行数
        counts=[0]    #在递归中,一般用全局变量计数
        self.backtrace(1,n,chessboard,counts) 
        return counts[0]
    def check(self,chessboard,layer): #检查
        for prev_layer in range(1,layer): #检查该列与前面的每一列是否冲突
            if(chessboard[prev_layer]==chessboard[layer] or \
               abs(chessboard[prev_layer]-chessboard[layer])==layer-prev_layer):
                return False
        return True
    def backtrace(self,layer,n,chessboard,counts):
        #用layer记录进入的层数
        if(layer>n): #layer达到最后一层,记录下改可能性
            counts[0]+=1
        else:
            for i in range(n): #遍历每一种可能性
                chessboard[layer]=i
                if (self.check(chessboard,layer)): #如果满足条件,那么进入下一层
                    self.backtrace(layer+1,n,chessboard,counts)
```
# 2.改进的回溯法
采用集合`used_layers`储存使用过的行数,从而减少`check`函数判断的时间
![image.png](https://pic.leetcode-cn.com/bf497154e526662679b8b18841f4484fbb8f7f3c62ff138e7cdd9d05f64d655c-image.png)
```py
class Solution:
    def __init__(self):
        #回溯中使用全局变量记录结果
        self.res=0
    def totalNQueens(self, n: int) -> int:
        chessboard=[0]*n #初始化棋盘,index代表列,value代表行
        used_layers=set() #使用集合放置使用过的行数

        #判断新加入的棋子与之前的棋子是否在对角线冲突
        def check(chessboard,layer):
            for pre_layer in range(layer):
                if abs(chessboard[layer]-chessboard[pre_layer])==layer-pre_layer:
                    return False
            return True
        def backtrace(chessboard,n,layer,used_layers):
            if layer==n:
                self.res+=1
            else:
                #按列放置皇后,因此列不会冲突
                for i in range(n):
                    #遍历每一个可能放置的行,同时判断与其它行是否冲突
                    if i not in used_layers:
                        #行不冲突就暂时加入棋盘
                        chessboard[layer]=i
                        #判断新加入的棋子与之前的棋子是否对角线冲突
                        if check(chessboard,layer):
                            used_layers.add(i) #加入使用过的层的集合
                            backtrace(chessboard,n,layer+1,used_layers) #递归
                            used_layers-={i} #回溯
        backtrace(chessboard,n,0,used_layers)
        return self.res
                
```
