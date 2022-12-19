```
class Solution {
private:
    int n,m;
    const int dir[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}}; 
    struct Cell {
        int x,y;
        int step;
        Cell(int xx, int yy): x(xx), y(yy), step(0) {};
    };

    vector<vector<int>> grid; 
    vector<vector<int>> dist;
    vector<vector<int>> reach;
    vector<vector<int>> used;
    
    bool check_cell(const int& x, const int& y) {
        if(x < 0 || x >= n) return false;
        if(y < 0 || y >= m) return false;
        if(grid[x][y] != 0) return false;
        return true;
    }
    void bfs(const Cell& building) {
        queue<Cell>Q;
        used.assign(n, vector<int>(m, false));
        Q.push(building);
        used[building.x][building.y] = true; 
        while(!Q.empty()) {
            Cell front = Q.front();
            dist[front.x][front.y] += front.step;
            reach[front.x][front.y] += 1;
           for(int i = 0; i< 4;i ++) {
               int x = front.x + dir[i][0];
               int y= front.y + dir[i][1]; 
               if(check_cell(x, y) && !used[x][y]) {
                   used[x][y] = true;
                   Cell next(x, y);
                   next.step = front.step + 1;
                   Q.push(next); 
               }
           }
           Q.pop();    
        }
    }
public:
    int shortestDistance(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        reach.assign(n, vector<int>(m, 0));
        dist.assign(n, vector<int>(m, 0));
        int k = 0;
        for(int i = 0; i<grid.size(); i++) {
            auto row = grid[i];
            for(int j = 0; j< row.size(); j++) {
                int type = row[j];
                if(type == 1){
                    bfs(Cell(i, j));
                    k++;
                } 
            }
        }
        int res = -1;
        if(k == 0) return -1;
        for(int i = 0; i<n;i++) {
            for(int j = 0; j<m;j++) {
                if(grid[i][j] != 0) continue;
                if(reach[i][j] < k) continue;
                int cur = dist[i][j];
                if(res == -1 || res > cur) {
                    res = cur;
                }
            }
        } 
        return res;
    }
};
```
