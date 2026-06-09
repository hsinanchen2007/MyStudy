## 幻方
条件：
1. 中间数字是5
2. 每个数字只属于1~9，且只出现一次
3. 第一三行和为15，且第一三列和为15
```cpp
class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j){
        int count[10]={0};
        for(int ii=-1; ii<=1; ii++){
            for(int jj=-1; jj<=1; jj++){
                int cur = grid[i+ii][j+jj];
                if(cur>9 || cur<1) return false;
                count[cur]++;
            }
        }
        for(int ii=1; ii<=9; ii++){
            if(count[ii]!=1) return false;
        }
        if(grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1] != 15 
            || grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1] != 15
            || grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1] != 15
            || grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1] != 15)
            return false;
        else
            return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r0 = grid.size(), c0 = grid[0].size(), ans=0;;
        if(r0<3 || c0<3 ) return 0;
        for(int i=1; i<r0-1; i++){
            for(int j=1; j<c0-1; j++){
                if(grid[i][j]!=5) continue;
                else if(isMagic(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};
```