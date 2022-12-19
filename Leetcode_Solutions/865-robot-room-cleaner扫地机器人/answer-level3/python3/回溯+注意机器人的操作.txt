更多小白解题思路以及面试经验更新中 [Mereder](https://mereder.github.io/)

首先都会想到用DFS+回溯，只不过这里额外多了个机器人接口，除了进行搜索操作外，还应该及时操作机器人，对应上搜索操作。

首先看普通的dfs

```python
def __init__(self):
    self.visited = set()
    # 上 右 下 左
    self.rd = [-1,0,1,0]
    self.cd = [0,1,0,-1]
def dfs(self,robot,i=0,j=0,d=0):
  
    # 标记遍历
    self.visited.add((i,j))

    for k in range(4):
 				# 四个方向选一个继续dfs
        newr,newc = i + self.rd[k], j+self.cd[k]
        # 如果没有遍历过就进行遍历
        if (newr,newc) not in self.visited:
            # 继续进行dfs
            self.dfs(robot,newr,newc)
```

对应本题，还需要考虑机器人的情况：

- 机器人可以运动的方向有四个（上，下，左，右），不可能上一次考虑完`上`，下一次就去考虑`下`，机器人旋转需要按照顺时针（或逆时针方向）。
- 如果该遍历的地方已经进行了遍历，需要回退，在图上就简单的坐标操作就完成了回退，这里对于机器人还需要进行额外的回退操作。
- 机器人方向的一致性：即从当前点，进入到下一个点的时候，机器人的朝向应该是一致的，而返回时候方向恰好相反

```python
#class Robot:
#    def move(self):
#
#    def turnLeft(self):
#
#    def turnRight(self):
#
#    def clean(self):

class Solution:
    def __init__(self):
        self.visited = set()
        # 上 右 下 左    顺时针方向！！！
        self.rd = [-1,0,1,0]
        self.cd = [0,1,0,-1]
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        self.dfs(robot)

    def dfs(self,robot,i=0,j=0,d=0):
        self.visited.add((i,j))
        robot.clean()

        for k in range(4):
            new_d = (d+k) % 4 # 机器人方向的一致性
            newr,newc = i + self.rd[new_d], j+self.cd[new_d]
            if (newr,newc) not in self.visited and robot.move():
                # 内层 dfs 死掉 需要 回头
                self.dfs(robot,newr,newc,new_d)
                # dfs跳出表示遍历完，机器人需要进行回退操作
                self.back(robot)
            robot.turnRight() # 下一个位置  注意跟 newr,newc对应

# 专门的回退操作
    def back(self,robot):
        # 掉头
        robot.turnRight()
        robot.turnRight()
        # 回退
        robot.move()
        # 重置方向 跟之前一样
        robot.turnRight()
        robot.turnRight()
        
```