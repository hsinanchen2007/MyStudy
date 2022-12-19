### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]||grid[n-1][n-1]) return -1;
        if(n==1) return 1;
        queue<int> qu;
        vector<vector<int>> d(n,vector<int>(n,0));
        qu.push(0);
        d[0][0]=1;
        while (!qu.empty()){
            int t=qu.front();qu.pop();
            int nx=t/n,ny=t%n;
            for(int i=0;i<8;i++){
                int x=dx[i]+nx,y=dy[i]+ny;
                if(x<0||n<=x||y<0||n<=y||d[x][y]||grid[x][y]) continue;
                d[x][y]= d[nx][ny]+1;
                if(x==n-1&&y==n-1) return d[x][y];
                qu.push(x*n+y);
            }
        }
        return -1;
    }
};
```