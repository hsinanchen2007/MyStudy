### 解题思路
纯BFS解题，详细见代码前序注释

660ms 68.7M
--- wangtao HW-2020/2/29
### 代码

```cpp
class Solution {
public:
    /*
    思路：纯BFS阶梯
    1、涉及到最短指令，最短路径其实都可以往BFS上考虑考虑
    2、一般情况下的最短路径操作，会给定四个方向，而该题不涉及四个方向路径，但分析下可以看出是在两个方向上的移动
    3、可以假设车在任意一个位置都有两种选择，那最终结束条件也就是到达目标，而BFS总是能找到最短路径（最少指令）的
    4、为了避免回头路，我们这选择当前位置和速度来做识别，不能单独选择位置这一个条件，因为在相同的位置会有不同的速度，也可能会有最小值的情况
    */
    int racecar(int target) {
        // pos & speed
        int ans = 0;
        map<pair<int, int>, int> visited;
        queue<pair<pair<int, int>, int>> qu;

        qu.push(make_pair(make_pair(0, 1), 0));
        visited[make_pair(0, 1)] = 1;
        while(!qu.empty()) {
            pair<pair<int, int>, int> data = qu.front();
            int pos = data.first.first;
            int spd = data.first.second;
            int step = data.second;
            qu.pop();
            if (pos == target) {
                ans = step;
                break;
            }
            for (int i = 0; i < 2; i++) {
                int newpos = 0;
                int newspd = 0;
                // 0 - 'A', 1 - 'R'
                if (i == 0) {
                    newpos = pos + spd;
                    newspd = spd * 2;  
                    // cout << newpos << endl;
                } else {
                    newpos = pos;
                    newspd = spd > 0 ? -1 : 1;
                }
                if (visited.count(make_pair(newpos, newspd)) == 0 && newpos > 0 && newpos < 2 * target) {
                    visited[make_pair(newpos, newspd)] = 1;
                    qu.push(make_pair(make_pair(newpos, newspd), step + 1));
                }
            }
        }
        return ans;
    }
};
```