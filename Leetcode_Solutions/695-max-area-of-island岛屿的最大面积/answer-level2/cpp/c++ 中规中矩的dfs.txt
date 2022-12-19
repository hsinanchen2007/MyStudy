```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        exp=vector<vector<int>>(grid);
        visited=vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(),0));
        int max=0, t;
        for(int i=0; i<exp.size(); i++)
            for(int j=0; j<exp[0].size(); j++){
                t=dfs(i,j);
                //exp[i][j];
                //visited[i][j];
                if(t>max)
                    max=t;
            }
        return max;

    }
    int dfs(int i, int j){
        if(i<0 ||j<0 || i>=exp.size() || j>=exp[0].size()||visited[i][j] || exp[i][j]==0)
            return 0;
        visited[i][j]=1;
        int udlr[][2]={-1,0, 1,0, 0,-1, 0,1};
        int r=1;
        for(int z=0; z<4; z++)
            r+=dfs(i+udlr[z][0], j+udlr[z][1]);
        return r;
    }
private:
    vector<vector<bool>> visited;
    vector<vector<int>> exp;

};
```
