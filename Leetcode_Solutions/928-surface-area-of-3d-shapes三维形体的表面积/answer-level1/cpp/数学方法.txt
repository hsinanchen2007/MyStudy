### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid){
        int sum_area = 0;
        int m = grid.size();
        int n = grid[0].size();
        if(m==0||n==0)return 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                if(grid[i][j]==0)sum_area+=0;
                else
                    sum_area += 6+4*(grid[i][j]-1);
                if((i-1)>=0) sum_area -= min(grid[i][j],grid[i-1][j]);
                if((i+1)<n) sum_area -= min(grid[i][j],grid[i+1][j]);
                if((j-1)>=0) sum_area -= min(grid[i][j],grid[i][j-1]);
                if((j+1)<m) sum_area -= min(grid[i][j],grid[i][j+1]);
                }
        return sum_area;
    }
};
/*
     struct node{
         int x;
         int y;
     };
     int surfaceArea(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(m==0||n==0)return 0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        //vector<vector<int>>area(m,vector<int>(n,0));
        queue<node>q;
        node q0;
        q0.x=0,q0.y=0;
        q.push(q0);
        visited[0][0]=1;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int grid0 = grid[0][0];
        //area[0][0] = 6+4*(grid0-1);
        int sum_area = 6+4*(grid0-1);
        node cur,next;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            int x0 = cur.x, y0 =cur.y;
            //area[x0][y0] = 6+4*(grid[x0][y0]-1);
            for(int i = 0; i < 4; ++i){
                int x = x0 + dx[i];
                int y = y0 + dy[i];
                if(x<m&&x>=0&&y<n&&y>=0&&visited[x][y]==0){
                    if(grid[x0][y0]>grid[x][y])
                        //area[x0][y0] -= grid[x][y];
                        sum_area -= grid[x][y];
                    else
                        //area[x0][y0] -= grid[x0][y0];
                        sum_area -= grid[x0][y0];
                    next.x=x;
                    next.y=y;
                    q.push(next); 
                }
            }
        }
        return sum_area;
        /*
        int sum_area = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                sum_area += area[i][j];
            }
        return sum_area;
        */

```