

```
'''
dfs 模拟即可
'''

class Solution:

    def rollback(self, robot):
        robot.turnLeft()
        robot.turnLeft()
        robot.move()
        robot.turnLeft()
        robot.turnLeft()

    def dfs(self, i, j, visited, robot, direc):
        if (i, j) in visited:
            return

        # 不论进来的方向是什么，统一调整成向上，这样可以保持坐标变化的一致性
        if direc == 1:
            robot.turnRight()
        elif direc == 2:
            robot.turnLeft()
            robot.turnLeft()
        elif direc == 3:
            robot.turnLeft()

        visited.add((i, j))
        robot.clean()

        # up
        if robot.move():
            self.dfs(i-1, j, visited, robot, 0)
            self.rollback(robot)

        # down
        robot.turnLeft()
        robot.turnLeft()
        if robot.move():
            self.dfs(i+1, j, visited, robot, 2)
            self.rollback(robot)
        robot.turnLeft()
        robot.turnLeft()

        # left
        robot.turnLeft()
        if robot.move():
            self.dfs(i, j-1, visited, robot, 1)
            self.rollback(robot)
        robot.turnRight()

        # right
        robot.turnRight()
        if robot.move():
            self.dfs(i, j+1, visited, robot, 3)
            self.rollback(robot)
        robot.turnLeft()

        # 恢复一开始做的方向校正
        if direc == 1:
            robot.turnLeft()
        elif direc == 2:
            robot.turnLeft()
            robot.turnLeft()
        elif direc == 3:
            robot.turnRight()


    def cleanRoom(self, robot):
        self.dfs(1, 3, set(), robot, 0)
```
