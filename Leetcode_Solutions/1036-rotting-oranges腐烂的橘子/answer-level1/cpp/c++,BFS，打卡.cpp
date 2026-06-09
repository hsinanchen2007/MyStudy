### 解题思路
很菜的方法，直接暴力BFS，注意一点是该题BFS不是单点出发，而是多点出发。（如果有两或多个坏橘子，要从多个坏橘子一起进行BFS）

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        //int xs=[-1,1,0,0],ys=[0,0,-1,1];
        vector<pair<int, int>> s = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        queue<pair<int,int>> res;
        int fresh_c = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    ++fresh_c;
                }else if(grid[i][j] == 2){
                    res.push(make_pair(i,j));
                }
            }
        }
        int count = res.size();
        int count_c = 0;
        int time = 0;
        while(!res.empty()){
            pair<int,int> ans = res.front();
            int x = ans.first;
            int y = ans.second;
            count--;
            if(grid[x][y] == 0) continue;
            
            grid[x][y] == 0;
            res.pop();
            for(int t=0;t<s.size();t++){
                int xi = x+s[t].first;
                int yi = y+s[t].second;
                if(xi>=0 && xi<row && yi>=0 && yi<col && grid[xi][yi] == 1){
                    grid[xi][yi] = 2;
                    --fresh_c;//减1新鲜橘子
                    count_c++;
                    //cout<<xi<<","<<yi<<endl;
                    res.push(make_pair(xi,yi));
                }
            }
            if(count == 0){
                count = count_c;
                if(count_c!=0)
                    time++;
                count_c = 0;
            }
        }
        return 0 == fresh_c?time:-1;
    }
};
```