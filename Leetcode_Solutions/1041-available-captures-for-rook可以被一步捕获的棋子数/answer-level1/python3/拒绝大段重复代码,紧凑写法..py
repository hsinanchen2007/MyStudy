### 解题思路
遍历数组找到车的位置
从车的位置出发,向4个方向寻找
### 代码
```
class Solution:
    def numRookCaptures(self, board: [[str]]) -> int:
        ret=0 #返回倅的数目
        m=len(board)
        n=len(board[0])
        def inarea(x,y): #判断(x,y)是否在小于一圈数组的范围内
            return 0<x<m-1 and 0<y<n-1
        for i in range(m):
            for j in range(n):
                if board[i][j]=='R': #找到了车的位置
                    direction=[[-1,0],[1,0],[0,1],[0,-1]] #定义寻找的4个方向
                    for k in range(4):#4个方向
                        a = i
                        b = j
                        while inarea(a,b):
                            a=a+direction[k][0]
                            b=b+direction[k][1]
                            if board[a][b]=='B':
                                break
                            elif board[a][b]=='p':
                                ret+=1
                                break
                            continue
        return ret


```