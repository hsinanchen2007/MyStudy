# $O(N^2)$

## Brute-force

```cpp
class Solution {
public:
    char findDirection (char curr_dir, int command) {
        if (curr_dir == 'N') {
            if (command == -1) {
                return 'E';
            } else if (command == -2) {
                return 'W';
            }
        } else if (curr_dir == 'E') {
            if (command == -1) {
                return 'S';
            } else if (command == -2) {
                return 'N';
            }
        } else if (curr_dir == 'S') {
            if (command == -1) {
                return 'W';
            } else if (command == -2) {
                return 'E';
            }
        } else if (curr_dir == 'W') {
            if (command == -1) {
                return 'N';
            } else if (command == -2) {
                return 'S';
            }
        }
        return -1;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char direction = 'N';
        int position[2] = {0, 0};
        long dist = 0;
        long max_dist = 0;
        
        for (int i = 0; i < commands.size(); i++) {
            if(commands[i] == -1 || commands[i] == -2) {
                direction = findDirection(direction, commands[i]);
            } else {
                if (direction == 'N') {
                    int obstacle = position[1] + commands[i] + 1; 

                    for (int j = 0; j < obstacles.size(); j++) {
                        if (obstacles[j][0] == position[0] && obstacles[j][1] > position[1] && obstacles[j][1] <= position[1] + commands[i]) {
                            obstacle = std::min(obstacle, obstacles[j][1]);
                        }
                    }

                    if (obstacle == position[1] + commands[i] + 1) {
                        position[1] += commands[i];
                    } else {
                        position[1] = obstacle - 1; 
                    }
                } else if (direction == 'S') {
                    int obstacle = position[1] - commands[i] - 1; 

                    for (int j = 0; j < obstacles.size(); j++) {
                        if (obstacles[j][0] == position[0] && obstacles[j][1] < position[1] && obstacles[j][1] >= position[1] - commands[i]) {
                            obstacle = std::max(obstacle, obstacles[j][1]);
                        }
                    }

                    if (obstacle == position[1] - commands[i] - 1) {
                        position[1] -= commands[i];
                    } else {
                        position[1] = obstacle + 1; 
                    }
                } else if (direction == 'E') {
                    int obstacle = position[0] + commands[i] + 1; 

                    for (int j = 0; j < obstacles.size(); j++) {
                        if (obstacles[j][1] == position[1] && obstacles[j][0] > position[0] && obstacles[j][0] <= position[0] + commands[i]) {
                            obstacle = std::min(obstacle, obstacles[j][0]);
                        }
                    }
                                    
                    if (obstacle == position[0] + commands[i] + 1) {
                        position[0] += commands[i];
                    } else {
                        position[0] = obstacle - 1; 
                    }
                } else if (direction == 'W') {
                    int obstacle = position[0] - commands[i] - 1; 

                    for (int j = 0; j < obstacles.size(); j++) {
                        if (obstacles[j][1] == position[1] && obstacles[j][0] < position[0] && obstacles[j][0] >= position[0] - commands[i]) {
                            obstacle = std::max(obstacle, obstacles[j][0]);
                        }
                    }

                    if (obstacle == position[0] - commands[i] - 1) {
                        position[0] -= commands[i];
                    } else {
                        position[0] = obstacle + 1; 
                    }
                }
                dist = std::pow(position[0], 2) + std::pow(position[1], 2);
                max_dist = std::max(dist, max_dist);
            }
        }
        return max_dist;
    }
};
```
### Complexity
- Time: $(N^2)$
- Space: $O(1)$

// 这大概就是，有多少“人工”， 就有多少“智能”...

# $O(N+K)$
此题关键的两步为即时改变direction和检索是否遇到obstacle。
direction的改变可以使用题解的巧用坐标模拟法，亦可以使用我的暴力枚举法。时间复杂度每一次都是O（1）， 只是我的代码长些，他的代码短小精妙些。
但对于obstacle的检索，我使用的嵌套for循环检索就会达到O（NK），而使用set只需O（N），值得注意。
(Mind: 使用unordered_set无法使用pair<int, int>， 但set可以)

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        int max_dist = 0;

        // make set
        set<pair<int, int>> obstacle_set;
        for (int k = 0; k < obstacles.size(); k++) {
            obstacle_set.insert(make_pair(obstacles[k][0], obstacles[k][1]));
        }


        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                di = (di + 3) % 4;
            } else if (commands[i] == -1) {
                di = (di + 1) % 4;
            } else {
                for (int j = 0; j < commands[i]; j++) {
                    int new_x = x + dx[di];
                    int new_y = y + dy[di];
                    if (obstacle_set.find(make_pair(new_x, new_y)) == obstacle_set.end()) {
                        x = new_x;
                        y = new_y;
                        int dist = std::pow(x, 2) + std::pow(y, 2);
                        max_dist = std::max(max_dist, dist);
                    }
                }
            }
        }
        return max_dist;
    }
};

```

### Complexity
- Time: $O(N+K)$
- Space: $O(K)$ 