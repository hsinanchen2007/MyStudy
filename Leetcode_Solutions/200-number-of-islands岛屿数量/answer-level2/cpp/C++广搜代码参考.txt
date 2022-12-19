```
//[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
//[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
//广搜
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)    return 0;
        queue<pair<int,int>> q;
        int step = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> help(m, vector(n, 0));
        //pair<int, int> p1(0, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !help[i][j]){
                    pair<int, int> p1(i, j);
                    q.push(p1);
                    step++;
                    //help[i][j] = 1;
                    while(!q.empty()){
                        for(int size = q.size(); size > 0; size--){
                            pair<int, int> new_p = q.front(); q.pop();
                            int new_i = new_p.first, new_j = new_p.second;
                            if(new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                                continue;
                            if(help[new_i][new_j] == 1 || grid[new_i][new_j] == '0') continue;    
                            help[new_i][new_j] = 1;
                            pair<int, int> new_p1(new_i-1, new_j), new_p2(new_i+1, new_j)
                                            , new_p3(new_i, new_j-1), new_p4(new_i, new_j+1);
                            q.push(new_p1);
                            q.push(new_p2);
                            q.push(new_p3);
                            q.push(new_p4);
                        }
                    }
                }
            }
        }
        return step;
    }
};
```
