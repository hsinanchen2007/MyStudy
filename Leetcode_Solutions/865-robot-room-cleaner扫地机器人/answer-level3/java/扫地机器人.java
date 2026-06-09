#### 方法一：回溯

我们可以使用深度优先搜索来模拟机器人的扫地过程，即顺着当前机器人的朝向一直清扫下去，如果遇到障碍（清扫过的格子也算障碍），那么向右转向，直到找到一个没有障碍的朝向（继续进行搜索）或所有的朝向都有障碍（回溯）。

下图给出了机器人的扫地过程中某一步的状态，在此过程中，所有清扫过的格子都被视作障碍，不会重复经过。

![bla](https://pic.leetcode-cn.com/Figures/489/489_constraints.png){:width=500}

下图给出了机器人的回溯过程，在到达 `(1, -3)` 后，由于四个方向都是障碍，因此只能进行回溯，推到 `(0, -3)`。

![bla](https://pic.leetcode-cn.com/Figures/489/489_backtrack.png){:width=500}

下面给出了整个算法的框架：

- 我们从起始位置开始，记录当前的位置为 `cell = (0, 0)`，以及机器人的朝向 `direction = 0`；

- 将起始位置进行清扫，并进行标记（即清扫过的格子也算作障碍）；

- 依次选择四个朝向 `up`，`right`，`down` 和 `left` 进行深度优先搜索，相邻的两个朝向仅差一次向右旋转的操作；
    
    - 对于选择的朝向，检查下一个格子是否有障碍，如果没有，则向对应朝向移动一格，并开始新的搜索；

    - 如果有，则向右旋转。
  
- 如果四个朝向都搜索完毕，则回溯到上一次搜索。

下图给出了根据此算法，机器人移动的过程。

![bla](https://pic.leetcode-cn.com/Figures/489/489_implementation.png){:width=500}


```Python [sol1]
class Solution(object):       
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        def go_back():
            robot.turnRight()
            robot.turnRight()
            robot.move()
            robot.turnRight()
            robot.turnRight()
            
        def backtrack(cell = (0, 0), d = 0):
            visited.add(cell)
            robot.clean()
            # going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
            for i in range(4):
                new_d = (d + i) % 4
                new_cell = (cell[0] + directions[new_d][0], \
                            cell[1] + directions[new_d][1])
                
                if not new_cell in visited and robot.move():
                    backtrack(new_cell, new_d)
                    go_back()
                # turn the robot following chosen direction : clockwise
                robot.turnRight()
    
        # going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        visited = set()
        backtrack()
```

```Java [sol1]
public class Pair<F, S> {
    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        Pair<F, S> p = (Pair<F, S>) o;
        return Objects.equals(p.first, first) && Objects.equals(p.second, second);
    }

    @Override
    public int hashCode() {
        return first.hashCode() ^ second.hashCode();
    }
}

class Solution {
    // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
    int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Set<Pair<Integer, Integer>> visited = new HashSet();
    Robot robot;

    public void goBack() {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    public void backtrack(int row, int col, int d) {
        visited.add(new Pair(row, col));
        robot.clean();
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];

            if (!visited.contains(new Pair(newRow, newCol)) && robot.move()) {
                backtrack(newRow, newCol, newD);
                goBack();
            }
            // turn the robot following chosen direction : clockwise
            robot.turnRight();
        }
    }

    public void cleanRoom(Robot robot) {
        this.robot = robot;
        backtrack(0, 0, 0);
    }
}
```

**复杂度分析**

* 时间复杂度：$O(4^{N - M})$，其中 $N$ 是房间的大小，$M$ 是障碍物的数量。

* 空间复杂度：$O(N - M)$。