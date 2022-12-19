```
/**
 * // This is the robot's co***ol interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    int xx[4] = {-1, 0, 1, 0};
    int yy[4] = {0, 1, 0, -1};
    void dfs(Robot& robot, int x, int y, int direction){
        string key = to_string(x) + '#' + to_string(y);
        if(vis.find(key) != vis.end()) return;
        vis.insert(key);
        robot.clean();
        for(int i = 0; i < 4; ++i){
            int newdirection = (direction + i + 1) % 4;
            //here is the point, we need the new direction to memory the postion
            int _x = x + xx[newdirection];
            int _y = y + yy[newdirection];
            robot.turnRight();
            if(!robot.move()) continue;
            dfs(robot, _x, _y, newdirection);
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnRight();
            robot.turnRight();
            
        }
    }
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
private:
    set<string> vis;
};
```