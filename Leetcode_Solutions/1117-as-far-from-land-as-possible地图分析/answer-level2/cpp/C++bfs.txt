### 解题思路
一开始用dfs，直到看了题解

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        vector<int> ans={-1,-1};
        int dicx[4]={0,0,-1,1},dicy[4]={1,-1,0,0};
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j])q.push({i,j});
        if(q.empty())return -1;
        while(!q.empty()){
            int x=q.front()[0],y=q.front()[1];
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dicx[i];
                int ny=y+dicy[i];
                if(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())continue;
                if(!grid[nx][ny]){
                    grid[nx][ny]=grid[x][y]+1;
                    q.push({nx,ny});
                    ans={nx,ny};
                }
            }
        }
        if(ans[0]==-1)return -1;
        else return grid[ans[0]][ans[1]]-1;
    }
};
```