```
class Solution {
public:
    int visited[25][25] = {0};
    int startx,starty,endx,endy,m,n;
    int DIRS[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    int num = 0; //用来记录需要走过多少个0
    int dfs(int x,int y){
        if(x >= m || y >= n || x < 0 || y < 0 || visited[x][y] == 1) return 0;
        if(x == startx && y == starty){
            if(num == 1) return 1;
            else return 0;
        }
        visited[x][y] = 1;
        num--;
        int ans = 0;
        for(int i = 0 ; i < 4 ; i++){
            int nowx = x + DIRS[i][0];
            int nowy = y + DIRS[i][1];
            ans += dfs(nowx,nowy);
        }
        visited[x][y] = 0;
        num++;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        num = m*n;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == -1)visited[i][j] = 1,num--;
                else if(grid[i][j] == 1) startx = i,starty = j;
                else if(grid[i][j] == 2) endx = i,endy = j; 
            }
        visited[endx][endy] = 1;
        num--;
        int ans = 0;
        for(int i = 0 ; i < 4 ; i++){
            int nowx = endx + DIRS[i][0];
            int nowy = endy + DIRS[i][1];
            ans += dfs(nowx,nowy);
        }
        return ans;
        
    }
};
```
