1.我们可以根据command推算出机器人的路径，比如command='URR',我们可以推算出如下坐标
(0,1),(1,1),(2,1)
(2,2),(3,2),(4,2)
(4,3),(5,3),(6,3)...以此类推
我们可以发现，比如(5,3)，(5,3)-(1,1)=(4,2)（就是横坐标-横坐标，纵坐标-纵坐标），(4,2)可以看做是(2,1)的倍数。同样(4,3)-(0,1)=(4,2)，结果也是(2,1)的倍数。所以这个问题其实可以看成是一个y=kx+b的一次函数的问题。
至于为什么要用(2,1)做比较，因为(2,1)是完整执行完一次command后的坐标

2.本题中，机器人能完好到达终点的条件是：(1)终点坐标在行动轨迹上。(2)**在到达终点之前**没有障碍在行动轨迹上
3.首先遍历一次command，求出所有初始坐标
4.判断某个点p（以列表或元组形式表示）是否在行动轨迹的条件就是：（题目之所以至少一个U，至少一个R就是保证除数为不0）
(p[0]==po[0] and p[1]==po[1]) or (p[1]!=po[1] and (p[0]-po[0])/(p[1]-po[1])==divpo[0]/divpo[1])
其中po是所有初始坐标(就是一个列表)中的某个坐标，divpo这个初始坐标列表的最后一个元素(其实就是完整执行完一次command后的坐标),可看代码

```python []
def robot(self, command: str, obstacles: List[List[int]], x: int, y: int) -> bool:
        if x==0 and y==0:return True
        
        ori,oripos=[0,0],[]
        for c in command:
            if c=='U':
               ori[1]+=1
            else:
               ori[0]+=1
            oripos.append(ori[:])
        # print(oripos[-10:])
        divpo=oripos[-1]
        for po in oripos: #首先检测终点坐标是否在轨迹上
            if (x==po[0] and y==po[1]) or (y!=po[1] and (x-po[0])/(y-po[1])==divpo[0]/divpo[1]): #说明坐标(x,y)在行走轨迹上
                break
        else:return False #顺利遍历完毕，说明终点坐标不在轨迹上，返回false
        
        for ob in obstacles:
            if ob[0]<=x and ob[1]<=y:#先保证障碍物位置在行走路径范围内，否则机器人在走到障碍物之前就先到了终点
                for po in oripos:
                    if (ob[0]==po[0] and ob[1]==po[1]) or (ob[1]!=po[1] and (ob[0]-po[0])/(ob[1]-po[1])==divpo[0]/divpo[1]):#说明此障碍物在行走轨迹上，返回true
                        return False
        else:return True #顺利遍历完毕，说明到达终点前没有障碍物在轨迹上，返回true
```
