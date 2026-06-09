1.记录当前位置前后左右所能够炸死的敌人，然后相加即可。
```
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int r = grid.size();
        int ans = 0;
        if(r <= 0){
            return 0;
        }
        
        int c = grid[0].size();
        vector<vector<int>> left(r,vector<int>(c,0));
        vector<vector<int>> top(r,vector<int>(c,0));
        vector<vector<int>> right(r,vector<int>(c,0));
        vector<vector<int>> bottom(r,vector<int>(c,0));
        
        /*left&right*/
        for(int i = 0;i < r; ++i){
            for(int j = 1;j < c; ++j){
                if(grid[i][j-1] == 'E'){
                    left[i][j] = left[i][j-1] + 1;
                }else if(grid[i][j-1] == '0'){
                    left[i][j] = left[i][j-1];
                }else{
                    left[i][j] = 0;
                }
            }
            for(int j = c-2;j >= 0; --j){
                if(grid[i][j+1] == 'E'){
                    right[i][j] = right[i][j+1] + 1;
                }else if(grid[i][j+1] == '0'){
                    right[i][j] = right[i][j+1];
                }else{
                    right[i][j] = 0;
                }
            }
        }
        /*top&down*/
        for(int i = 0; i < c; ++i){
            for(int j = 1;j < r; ++j){
                if(grid[j-1][i] == 'E'){
                    top[j][i] = top[j-1][i] + 1;
                }else if(grid[j-1][i] == '0'){
                    top[j][i] = top[j-1][i];
                }else{
                    top[j][i] = 0;
                }
            }
            for(int j = r-2; j >= 0; --j){
                if(grid[j+1][i] == 'E'){
                    bottom[j][i] = bottom[j+1][i] + 1;
                }else if(grid[j+1][i] == '0'){
                    bottom[j][i] = bottom[j+1][i];
                }else{
                    bottom[j][i] = 0;
                }
            }
        }
        for(int i = 0;i < r; ++i){
            for(int j = 0;j < c; ++j){
                if(grid[i][j] == '0'){
                    ans = max(ans,left[i][j] + right[i][j] + top[i][j] + bottom[i][j]);
                }
            }
        }
        
        return ans;
    }
};
```