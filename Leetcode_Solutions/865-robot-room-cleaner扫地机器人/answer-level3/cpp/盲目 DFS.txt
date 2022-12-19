### 解题思路

Visited 用哈希保存，假设初始坐标为 (0, 0)，后面都是相对初始位置的坐标。

### 代码

```cpp
class Solution {
private:
    int moveDir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int robotDir[4] = { 0, 1, 2, 3 };
    unordered_set<string> visited;
public:
    void cleanRoom(Robot& robot) {
        auto pos = make_pair(0, 0);
        dfs(robot, pos, 1);
    }
    
    void dfs(Robot& robot, pair<int, int>& pos, int dir) {
        visited.insert(pair2Str(pos));
        // cout << pos.first << "," << pos.second << endl;
        robot.clean();
        for(int i=0; i<4; i++) {
            int next_dir = (dir + i) % 4;
            auto next_pos = make_pair(pos.first + moveDir[next_dir][0], pos.second + moveDir[next_dir][1]);
            if(visited.count(pair2Str(next_pos)) == 0 && robot.move()) {
                dfs(robot, next_pos, next_dir);
                backtrack(robot);
            }
            robot.turnRight();
        }
    }
    
    void backtrack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();           // 掉头走一步
        robot.turnRight();
        robot.turnRight();      // 方向调正
    }
    
    string pair2Str(pair<int, int>& p) {
        return to_string(p.first) + "_" + to_string(p.second);
    }
};
```