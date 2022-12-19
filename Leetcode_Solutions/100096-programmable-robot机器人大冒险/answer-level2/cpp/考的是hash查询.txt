### 解题思路
x，y会达到10^9量级，按照command一步一步加1会超时。
终点和障碍点都可以转化为机器人能否达到的问题，首先判断需要多少次command循环，用数学计算跳过前面的完整循环。最后再用hash查询是否经过。

### 代码

```cpp
class Solution {
public:
    struct pair_hash{
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const{
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };

    int x1, y1;
    unordered_map<pair<int, int>, bool, pair_hash> path;

    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        x1 = y1 = 0;
        path[make_pair(0, 0)] = true;
        for(char c:command){
            if(c=='U') y1++;
            else x1++;
            path[make_pair(x1, y1)] = true;
        }
        if(!passBy(x, y)) return false;
        int temp = obstacles.size();
        for(int k=0; k<temp; k++){
            if(obstacles[k][0]<=x && obstacles[k][1]<=y){
                if(passBy(obstacles[k][0], obstacles[k][1])) return false;
            }
        }
        return true;
    }

    bool passBy(int x, int y){
        int repeat = x / x1;
        x -= x1 * repeat;
        y -= y1 * repeat;
        if(x>x1 || y>y1) return false;
        if(path[make_pair(x, y)]) return true;
        else return false;
    }
};
```