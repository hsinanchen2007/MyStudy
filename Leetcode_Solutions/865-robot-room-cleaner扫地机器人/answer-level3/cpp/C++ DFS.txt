### 解题思路
DFS，由于不知道当前位置，可以用当前相对于起点的相对位置表示当前坐标，坐标格式为"x,y"，用集合记录用于查重

注意机器人只能连续走，到死角时要原路返回——即每一步dfs后都要恢复状态


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};//顺时针方向的改变
    void dfs(Robot& robot, unordered_set<string>& visited, int x, int y, int dir){
        robot.clean();//清扫
        for(int i = 1; i <= 4; i++){//转四次后返回进入函数的初始状态
            robot.turnRight();//右转
            int new_dir = (dir + i) % 4;//下一步的方向
            int xx = x + dirs[new_dir][0];//下一步位置x
            int yy = y + dirs[new_dir][1];//下一步位置y
            string next = to_string(xx) + ',' + to_string(yy);
            if(visited.find(next) != visited.end())
                continue;
            visited.insert(next);//记录探查过
            if(robot.move()){//是空地
                dfs(robot, visited, xx, yy, new_dir);//继续扫
                //恢复原状
                robot.turnRight();
                robot.turnRight();//向后转
                robot.move();//前进
                robot.turnRight();
                robot.turnRight();//向后转
            }
        }
    }
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        visited.insert("0,0");
        dfs(robot, visited, 0, 0, 0);
    }
};
```