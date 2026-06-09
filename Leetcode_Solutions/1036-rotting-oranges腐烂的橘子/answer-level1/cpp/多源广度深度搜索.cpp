### 解题思路


### 代码

```cpp
class Solution {
public:   

    int orangesRotting(vector<vector<int>>& grid) {
    int ROW = grid.size();
    int COL = grid[0].size();
    int cnt = 0;  //fresh orange number
    int ans=0;
    vector<vector<int>> goneBadTime(ROW, vector<int>(COL));
    queue<pair<int,int>> Q;
    for(int i = 0; i< ROW; i++)
    {
        for(int j = 0; j< COL; j++)
        {
            if(grid[i][j] == 2) //bad orange
            {
                goneBadTime[i][j] = 0;
                Q.push(make_pair(i,j));
            }              
            else
                goneBadTime[i][j] = -1;
            if(grid[i][j] == 1)  //fresh orange
                cnt++;
        }
    }
    int x[4] = {0,-1, 0, 1}; //four direction
    int y[4] = {-1,0, 1, 0};
    while(!Q.empty()) //if queue is not empty
    {
        int dx = Q.front().first;
        int dy = Q.front().second;
        Q.pop();
        for(int k = 0; k<4; k++)
        {
            int tx = dx + x[k];
            int ty = dy + y[k];
            if(tx<0||tx>=ROW||ty<0||ty>=COL||goneBadTime[tx][ty]!=-1||grid[tx][ty]==0) continue;
            Q.push(make_pair(tx,ty));
            goneBadTime[tx][ty] = goneBadTime[dx][dy] + 1;
            //last "if" condition has already filtered the situation of grid[tx][ty]!=1.
            //if(grid[tx][ty] == 1) 
            //{
                ans = goneBadTime[tx][ty];
                cnt--;
                if(cnt == 0) break;
           // }
            
        }

    }
    return cnt?-1:ans;
    }
};
```