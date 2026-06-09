1. 倒序解法确实比较巧妙不容易想出来；
2. 在O(N)的时间复杂度内即可得到结果；
3. 跟楼上的解法改进的是不用set来存储保存的砖块位置，我们直接设置设置grid的标志位即可，因此运行速度更快和占用的内存更少；
执行用时 :
240 ms
, 在所有 C++ 提交中击败了
80.00%
的用户
内存消耗 :
88.8 MB
, 在所有 C++ 提交中击败了
25.00%
的用户
```c++ []
#define REMAIN 2
#define USED 1

class Solution {
public:
    int remain(vector<vector<int>>& grid,vector<int>  hit){
        int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        queue<pair<int,int>> qu;
        
        if(grid[hit[0]][hit[1]] == USED){
            int key = grid[hit[0]][hit[1]];
            qu.push(make_pair(hit[0],hit[1]));
            while(!qu.empty()){
                pair<int,int> curr = qu.front();
                grid[curr.first][curr.second] = REMAIN;
                qu.pop();
                
                for(int i = 0;i < 4; ++i){
                    int x = curr.first + d[i][0];
                    int y = curr.second + d[i][1];
                    if(x >= 0 && x < r && y >= 0 && y < c){
                        if(grid[x][y] == USED){
                            qu.push(make_pair(x,y));
                            grid[x][y] = REMAIN;
                            ans++;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
    
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int r = grid.size();
        int c = grid[0].size();
        int n = hits.size();
        vector<int> ans(n,0);
        
        for(int i = 0;i < n; ++i){
            --grid[hits[i][0]][hits[i][1]];
        }
        
        /*we set all rest to zero*/
        for(int i = 0; i < c; ++i){
            if(grid[0][i] == USED){
                remain(grid,vector<int>({0,i}));
            }
        }
        
        /*find*/
        for(int i = n-1; i >= 0; --i){
            //debug(grid);
            int x = hits[i][0];
            int y = hits[i][1];
            grid[x][y]++;
            if(grid[x][y] == USED){
                if((x-1>= 0 && grid[x-1][y] == REMAIN)||
                   (x+1 < r && grid[x+1][y] == REMAIN)||
                   (y-1>= 0 && grid[x][y-1] == REMAIN)||
                   (y+1 < c && grid[x][y+1] == REMAIN)||
                   (x == 0)){
                    ans[i] = remain(grid,hits[i]);
                }
            }
            
        }
        
        return ans;
    }
};
```
