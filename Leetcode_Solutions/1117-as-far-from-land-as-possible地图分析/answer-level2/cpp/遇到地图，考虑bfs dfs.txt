### 解题思路
此处撰写解题思路

### 代码

```cpp
struct Point{
    int x;
    int y;
    Point(int i, int j){
        this->x = i;
        this->y = j;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<Point> q;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1)
                    q.push(Point(i,j));
            }
        }
        if(q.size() == grid.size() * grid[0].size() || q.size() == 0) return -1;
        int dis = 0;
        while(!q.empty()){
            dis++;
            int n = q.size();
            for(int i=0; i<n; ++i){
                Point t = q.front();
                q.pop();
                int x = t.x;
                int y = t.y;
                if(y>0 && grid[x][y-1] == 0){
                    grid[x][y-1] = 2;
                    q.push(Point(x, y-1));
                }
                if(y<grid[0].size()-1 && grid[x][y+1] == 0){
                    grid[x][y+1] = 2;
                    q.push(Point(x, y+1));
                }
                if(x>0 && grid[x-1][y] == 0){
                    grid[x-1][y] = 2;
                    q.push(Point(x-1, y));
                }
                if(x<grid.size()-1 && grid[x+1][y] == 0){
                    grid[x+1][y] = 2;
                    q.push(Point(x+1, y));
                }
            }
        }
        return dis-1;
    }
};
```