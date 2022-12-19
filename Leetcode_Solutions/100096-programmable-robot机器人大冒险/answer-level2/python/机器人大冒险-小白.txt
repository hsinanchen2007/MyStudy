![robot.PNG](https://pic.leetcode-cn.com/6f33e900a71ee6d488ae50410ed71fe5ec4982afd89816ef025e9b364ace328e-robot.PNG)

1、障碍物处理，剔除范围外的
2、由于走的步数固定，成倍数，对障碍进行最小公倍数缩放，缩小距离
3、对终点进行缩放
4、生成范围内路程步数矩阵
5、判断是否碰到障碍或者无法到达终点，返回False
6、到达终点，返回True



class Solution(object):

    def through_out(self,obstacles,x,y):
        __in__=[]
        for i in range(len(obstacles)):
            if obstacles[i][0]<=x and obstacles[i][1]<=y:
                __in__.append(obstacles[i])
        return __in__

    def scla(self,obstacles,x,y):
        __sc__=[]
        for i in range(len(obstacles)):
            min_x=obstacles[i][0]//x
            min_y=obstacles[i][1]//y
            if min_x<min_y:
                obstacles[i][0]-=(min_x*x)
                obstacles[i][1]-=(min_x*y)
            else:
                obstacles[i][0]-=(min_y*x)
                obstacles[i][1]-=(min_y*y)
            __sc__.append(obstacles[i])
        return __sc__

    def through_pass(self,command):
        __throgh__=[]
        xr,yr=0,0
        for i in command:
            if i=='R':
                xr+=1
            else:
                yr+=1
            __throgh__.append([xr,yr])
        return __throgh__

    def robot(self, command, obstacles, x, y):

        '''delete the axis out the pass'''
        obstacles= self.through_out(self,obstacles, x, y)

        count_commend_x=command.count('R')
        count_commend_y=command.count('U')

        obstacles=self.scla(self,obstacles,count_commend_x,count_commend_y)
        end_point=self.scla(self,[[x,y]],count_commend_x,count_commend_y)

        through=self.through_pass(self,command)

        '''judge whether the obs in the way'''
        for i in range(len(through)):
            for j in range(len(obstacles)):
                if obstacles[j]==through[i] or obstacles[j]==[0,0]:
                    return False
        '''judge whether arrived the end point'''
        for i in range(len(through)):
            if [through[i]]==end_point or end_point==[[0,0]]:
                return True
        return False
