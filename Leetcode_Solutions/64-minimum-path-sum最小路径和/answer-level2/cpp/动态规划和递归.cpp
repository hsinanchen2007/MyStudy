## 递归-超出时间限制
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int MAX_X = grid.size();
        int MAX_Y = grid[0].size();
        //if(MAX_X==1 && MAX_Y==1) return 0; 
        int ans = MinPath(MAX_X-1, MAX_Y-1, grid);

        return ans;
    }
    int MinPath(int x, int y, vector<vector<int>>& grid){

        if(x==0 && y==0) return grid[0][0];
        if(x<0 || y<0) return 0;
        int ans = grid[x][y];
        ans = ans + FindMin(MinPath(x-1, y, grid), MinPath(x, y-1, grid));

        return ans;
    }
    
    int FindMin(int a, int b){
        int min = a;
        if(a && b){
            if(a>=b) min=b;
            else min=a;
        }
        else{
            if(a==0) min=b;
            if(b==0) min=a;
        }
        return min;
    }
};
```
## 动态规划
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> DP=grid; // 填表方向应该是从左到右 再从上至下
        int MAX_X = grid.size();
        int MAX_Y = grid[0].size();

        
        for(int i=0; i<MAX_X; i++){
            for(int j=0; j<MAX_Y; j++){
                if(i==0 && j==0) DP[0][0] = grid[0][0];
                else DP[i][j] = grid[i][j] + getCur(i, j, DP);
            }
        }
        
        return DP[MAX_X-1][MAX_Y-1];

    }
    
    int getCur(int x, int y, vector<vector<int>>& DP){
        int min=0;
        if(x-1>=0 && y-1>=0){
            min= Min_int(DP[x-1][y], DP[x][y-1]);
        }else{
            if(x-1<0) min = DP[x][y-1];
            else min = DP[x-1][y];
        }
        return min;
    }

    int Min_int(int a, int b){  // 不存在是path=0
        int min = a;
        if(a>=b) min=b;
        else min=a;
        return min;
    }
};
```
