```cpp
class Solution {
private:
    vector<int> res;
    const int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<bool>> visit;
    int m, n;

    bool inArea(int x, int y) {
        return x >=0 && x < m && y >=0 && y < n;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        m = matrix.size();
        if (m == 0)
            return res;        
        n = matrix[0].size();
        if (n == 0)
            return res;
        
        visit = vector<vector<bool>> (m, vector<bool>(n, false));
        int x = 0, y = 0;
        int direction = 0;  // 当前的方向
        while (res.size() < m * n) {   // 使用res当前长度做循环继续的条件
            
            if (!visit[x][y]) {
                visit[x][y] = true;
                res.push_back(matrix[x][y]);
            }    
            int newx = x + d[direction][0];
            int newy = y + d[direction][1];
            if (inArea(newx, newy) && !visit[newx][newy]) {  
                x = newx;
                y = newy;
            }
            else 
                direction = (direction + 1) % 4; // 一直沿一个方向走，直到新的点不满足要求再换方向
        } 
            
        return res;
    }
};

```