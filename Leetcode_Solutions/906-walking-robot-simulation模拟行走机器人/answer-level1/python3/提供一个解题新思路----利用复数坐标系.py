新人，代码可能会比较复杂，但是提供一个处理类似问题的新思路
可以用复数坐标系来处理机器人在空间上的位置，仅需一个变量 b
用复数的实数部分表示x轴，虚数部分表示y轴
我们可以设置一个变量 a 表示方向
因为机器人一开始朝向北，a = 1j
如果向左转，a = a*1j
如果向右转，a = a*-1j
但是开头要先将obstales列表中的值转为复数，并存入字典（后面查找更快）
最后的距离就是  b.real ** 2 + b.imag ** 2
代码如下：

from collections import defaultdict
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        a=1j
        b=0
        c=[]
        if obstacles:
            obstacles_map = defaultdict(int)
            #将列表转为复数形式，并存入字典
            for i in range(len(obstacles)):
                obstacles_map[obstacles[i][0]+obstacles[i][1]*1j]=1
        for i in range(0,len(commands)):
            #以此判断改变的方向，并通过改变 a 变量的值改变方向
            if commands[i]==-1:
                a*=-1j
            elif commands[i]==-2:
                a*=1j
            else:
                if obstacles != []:
                    #这一步是为了判断向这个方向移动一单位是否遇到障碍物，
                    #如果有，就中止循环
                    for j in range(commands[i]):
                        #判断移动到下一位置的值是否于障碍物相等
                        if obstacles_map[b+a] == 0:
                            b+=a
                            c += [b.real ** 2 + b.imag ** 2]
                        else:
                            break
                else:
                    b+=a*commands[i]
                    #建立一个新的列表储存机器人到原点的每一次位置距离的平方
                    c += [b.real ** 2 + b.imag ** 2]
        if c!=[]:
            #找出最远点
            d=max(c)
        else:
            d=0
        return int(d)