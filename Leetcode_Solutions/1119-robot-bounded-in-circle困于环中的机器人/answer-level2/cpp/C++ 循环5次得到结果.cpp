***尝试不同解法----------YYM***

```
class Solution {
public:
    bool isRobotBounded(string instructions) {
        set<pair<int,int>> steps;
        steps.insert(pair<int,int>(0,0));
        /*
        * 排除全方向序列 
        */
        if (instructions.find('G') == string::npos) {
            return true;
        }

        int x = 0, y = 0, j = 0;
        int dir = 0;
        int sets[][2] = {{0, 1},{-1, 0},{0, -1},{1, 0}};
        /*
        * 将前4次的结果保存在set中，第五次运行时，将结果与之比较
        * 如果都在set里，则返回true，否则返回false
        */
        for (int i = 0; i < 5; i++) {
            j = 0;
            while (j < instructions.size()) {
                if (instructions[j] == 'G') {
                    x += sets[dir % 4][0];
                    y += sets[dir % 4][1];
                    if (i < 4) {
                        steps.insert(pair<int,int>(x, y));
                    }
                    else {
                        if (steps.find(pair<int,int>(x, y)) != steps.end()) {
                            j++;
                            continue;
                        } else {
                            return false;
                        }
                    }
                } else if (instructions[j] == 'L') {
                    dir++;
                } else if (instructions[j] == 'R') {
                    dir += 3;
                }
                j++;
            }
        }

        return true;
    }
};
```
