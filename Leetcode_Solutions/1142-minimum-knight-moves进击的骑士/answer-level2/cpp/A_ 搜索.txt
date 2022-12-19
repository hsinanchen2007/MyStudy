### 解题思路

评估函数用 两点的曼哈顿距离。

### 代码

```cpp
#define Dbg(x)  cout<<"[Debug] "<<__FUNCTION__<<"() L"<<__LINE__<<"\t"<<#x"="<<(x)<<endl

class Solution {
private:
    typedef pair<int, int> pii;
    
    string p2s(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
    
    int dir[8][2] = {
        {-1, -2},
        {-1, 2},
        {-2, -1},
        {-2, 1},
        {1, -2},
        {1, 2},
        {2, -1},
        {2, 1}
    };
public:
    int eval(int x, int y, int targetX, int targetY) {
        int diffX = abs(targetX - x);
        int diffY = abs(targetY - y);
        if(diffX > 10 || diffY > 10)
            return diffX + diffY;
        else
            return 0;
    }
    
    int minKnightMoves(int x, int y) {
        if(x == 0 && y == 0)
            return 0;
        
        queue<pii> Q;
        unordered_map<string, bool> visited;
        Q.emplace(0, 0);
        visited[p2s(0, 0)] = true;
        
        int step = 0;
        while(!Q.empty()) {
            int n = Q.size();
            step++;

            for(int i=0; i<n; i++) {
                auto cur = Q.front();
                Q.pop();
            
                int minW = INT_MAX;
                unordered_map<int, vector<pii>> dict;
                for(int i=0; i<8; i++) {
                    int nx = cur.first + dir[i][0];
                    int ny = cur.second + dir[i][1];
                    if(!visited[p2s(nx, ny)]) {
                        if(nx == x && ny == y)
                            return step;
                        int weight = step + eval(nx, ny, x, y);
                        dict[weight].push_back(make_pair(nx, ny));
                        minW = min(minW, weight);
                    }
                }
                // Dbg(minW);
                
                for(auto& p: dict[minW]) {
                    Q.emplace(p.first, p.second);
                    visited[p2s(p.first, p.second)] = true;
                }
            }
        }
        return -1;
    }
};
```