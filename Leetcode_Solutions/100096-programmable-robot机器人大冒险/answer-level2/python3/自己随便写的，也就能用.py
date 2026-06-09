### 解题思路
如果一步一步走，就是从（0，0）累加。比较障碍是否在路径上，终点是否在路径上
会超时
我这里稍微换了下思路，先用一个周期总移动的格数去整除，再按指令走一个周期，比较
下障碍和终点是否在路径上，没什么技巧，就是有些点要注意下，障碍是否在终点之后。

我这里几个地方写的有点乱，不过没报错就懒得去改了。我这样写的：
1.假如x,y 相差超过一个周期，那这个点不在路径上。（因为每一步均为正值）
2. 若（x - x0)(y - y0) < 0 （x当前x，x0目标或者障碍x） 则不可能到达这个点， 我那里写了一大串，大致就是这个等式的意思。。。不过也没报错



### 代码

```python3
import numpy as np 
class Solution:
    def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
# 移除终点后的障碍
            obstacles = [i for i in obstacles if i[0]<=x and i[1] <= y]
            Move = []

            for i in command:
                if i == 'U':
                    Move.append(np.array([0,1]))
                else:
                    Move.append(np.array([1,0]))
#得到S，一个周期的移动，向量表示
            S = sum(Move)
#定义判断
            def O_J(ob,Move = Move, S = S):
#我这里把障碍点设置为A了
                    A = ob
#判断目标x，y是否差超过一个周期
                    if abs(A[0]//S[0]-A[1]//S[1]) <=1:
#n为整除后需要的周期数
                        n = min(A[0]//S[0],A[1]//S[1])
# O1 为新起点
                        O1 = n*S
                        for i in Move:
# 判断能否到达A障碍，其实我感觉这句可以删掉。。。
                            if (O1[0] <= A[0] and O1[1] > A[1]) or (O1[0] > A[0] and O1[1] <= A[1]) or (O1[0] > A[0] and O1[1] > A[1]):
                                return False 
# 判断是否到达A
                            if (O1 == np.array(A)).all():
                                return True 
                            O1 += i
                    else:
                        return False 
# 判断我们是否碰到障碍                        
            for ob in obstacles:
                if O_J(ob):
                    return False 
# 把终点设置为ob，一样的判断一下终点是否在路径上，不过输出相反
            ob = [x,y]
            if O_J(ob):
                return True  
            else:
                return False   
```