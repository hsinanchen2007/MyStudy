```cpp
class Solution {
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
        map<int, set<int>> obstaclesMap;
        for (auto obstacle : obstacles) {
            if (obstacle[0] <= x && obstacle[1] <= y) {
                map<int, set<int >>::iterator it = obstaclesMap.find(obstacle[0]);
                if (it == obstaclesMap.end()) {
                    obstaclesMap.insert(pair<int, set<int>>(obstacle[0], set<int>({obstacle[1]})));
                } else {
                    it->second.insert(obstacle[1]);
                }
            }
        }
        vector<pair<int, int>> moves;
        pair<int, int> last = pair<int, int>(0, 0);
        for (auto ch : command) {
            pair<int, int> p = last;
            if (ch == 'U') {
                p.second += 1;
            } else {
                p.first += 1;
            }
            moves.push_back(p);
            last = p;
        }
        int times = min(x / last.first, y / last.second);
        last.second *= times;
        last.first *= times;
        int tempX = 0, tempY = 0;
        if(last.second != y || last.first != x) {
            for (auto move : moves) {
                tempX = last.first + move.first;
                tempY = last.second + move.second;
                if (tempX == x && tempY == y) {
                    break;
                }
                if (tempX > x || tempY > y) {
                    return false;
                }
            }
        }
        int moveIndex = 0;
        last.first = 0;
        last.second = 0;
        while (tempX <= x && tempY <= y) {
            tempX = moves[moveIndex].first + last.first;
            tempY = moves[moveIndex].second + last.second;
            map<int, set<int >>::iterator it = obstaclesMap.find(tempX);
            if (it != obstaclesMap.end() && it->second.find(tempY) != it->second.end()) {
                return false;
            }

            moveIndex++;
            if (moveIndex == command.length()){
                last.first = tempX;
                last.second = tempY;
                moveIndex = 0;
            }
        }
        return true;
    }
};
```

```cpp
class Solution {
private:
    vector<pair<int, int>> moves;
public:
    bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {

        moves.clear();
        pair<int, int> last = pair<int, int>(0, 0);
        for (auto ch : command) {
            pair<int, int> p = last;
            if (ch == 'U') {
                p.second += 1;
            } else {
                p.first += 1;
            }
            moves.push_back(p);
            last = p;
        }
        if (!canReachPosition(x,y)) {
            return false;
        }
        for (auto obstacle: obstacles) {
            
            if (obstacle[0] <= x && obstacle[1] <= y && canReachPosition(obstacle[0],obstacle[1])) {
                return false;
            }
        }
        return true;
    }

private:
    bool canReachPosition(int x, int y) {
        pair<int, int> last = moves.at(moves.size() - 1);
        int times = min(x / last.first, y / last.second);
        last.second *= times;
        last.first *= times;
        int tempX = 0, tempY = 0;
        if (last.second != y || last.first != x) {
            for (auto move : moves) {
                tempX = last.first + move.first;
                tempY = last.second + move.second;
                if (tempX == x && tempY == y) {
                    break;
                }
                if (tempX > x || tempY > y) {
                    return false;
                }
            }
        }
        return true;
    }
};


```
