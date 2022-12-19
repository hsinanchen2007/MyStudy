### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int map[n][m];
        memset(map, 0, sizeof(map));
        
        int ans = 0;
        while(1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(map[i][j] != 100){
                        map[i][j] = 0;
                    }
                }
            }
            bool flag = false;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(map[i][j] == 0 && grid[i][j] == 2){
                        //i-1 j
                        //i+1 j
                        //i j+1
                        //i j-1
                        map[i][j] = 100;
                        if(grid[max(0, i - 1)][j] == 1){
                            grid[max(0, i - 1)][j] = 2;
                            map[max(0, i - 1)][j] = -1;
                            flag = true;
                        }
                        if(grid[min(n - 1, i + 1)][j] == 1){
                            grid[min(n - 1, i + 1)][j] = 2;
                            map[min(n - 1, i + 1)][j] = -1;
                            flag = true;
                        }
                        if(grid[i][max(0, j - 1)] == 1){
                            grid[i][max(0, j - 1)] = 2;
                            map[i][max(0, j - 1)] = -1;
                            flag = true;
                        }
                        if(grid[i][min(m - 1, j + 1)] == 1){
                            grid[i][min(m - 1, j + 1)] = 2;
                            map[i][min(m - 1, j + 1)] = -1;
                            flag = true;
                        }
                        

                        // for(int ii = 0; ii < n; ii++){
                        //     for(int jj = 0; jj < m; jj++){
                        //         cout<<map[ii][jj]<<' ';
                        //     }
                        //     cout<<endl;
                        // }
                        // cout<<"******"<<endl;
                    }
            }
        }
            if(flag == false){
                break;
            } else {
                ans++;
            }
        }
        
        for(int ii = 0; ii < n; ii++){
            for(int jj = 0; jj < m; jj++){
                if(grid[ii][jj] == 1){
                    return -1;
                }
            }
        }

        
        return ans;
        
    }
};
```