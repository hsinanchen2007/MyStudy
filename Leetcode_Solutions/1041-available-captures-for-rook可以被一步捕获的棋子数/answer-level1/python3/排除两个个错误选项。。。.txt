### 解题思路
题解用数组存放过程，我用数组存放结果。结果我代码复制粘贴了那么多次。
回想昨天的《5. 最长回文子串》。我是憨憨，鉴定完毕...

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(0,8):
            for j in range(0,8):
                if board[i][j]=="R":
                    r_x=i
                    r_y=j
                    break
        '''
        思路一：往四个方向找result1，result2，result3，result4， 会超时
        思路二：2个方向遍历，result1，result2，result3，result4
                三种状态：-1  初始状态，  0  没有p状态    1  有p状态
        '''

        results=0
        result=[-1,-1,-1,-1]
        #result[1]=result[2]=result[3]=result[4]=-1
        for i in range(0,8):                     
            if board[i][r_y]=="p":          #在i向
                if i<r_x:
                    result[0]=1                      #往上有一个
                elif result[1]==-1:                  #往下不曾出现B,下部有p
                    result[1]=1
            elif board[i][r_y]=="B":
                if result[0]==1 and i<r_x:           #往上有一个B挡着p，不作数
                    result[0]=0                   
                elif result[1]==-1 and i>r_x:        #往下时，先出现B挡着，下部没有p
                    result[1]=0
            #'''
            if board[r_x][i]=="p":          #在j向
                if i<r_y:
                    result[2]=1                      #往上有一个
                elif result[3]==-1:                  #往下不曾出现B,下部有p
                    result[3]=1

            elif board[r_x][i]=="B":
                if result[2]==1 and i<r_y:           #往上有一个B挡着p，不作数
                    result[2]=0                   
                elif result[3]==-1 and i>r_y:        #往下时，先出现B挡着，下部没有p
                    result[3]=0
            #'''

        for i in result:
            if i>0:
                results+=i
        return results



        
```