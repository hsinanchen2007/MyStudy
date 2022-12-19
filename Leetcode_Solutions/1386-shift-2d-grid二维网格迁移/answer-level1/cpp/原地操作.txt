`inplace` `60ms`

```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int begin = 0;
        int pre;
        int temp;
        while(count<m*n){
            pre = grid[begin/m][begin%m];
            int cur = begin;
            while(1){
                cur += k;
                cur %= n*m;
                if(cur==begin){
                    break;
                }
                int i = cur/m;
                int j = cur%m;
                temp = grid[i][j];
                grid[i][j] = pre;
                pre = temp;
                count ++;
            }
            grid[begin/m][begin%m] = pre;
            count ++;
            begin ++;
        }
        return grid;
    }
};
```
