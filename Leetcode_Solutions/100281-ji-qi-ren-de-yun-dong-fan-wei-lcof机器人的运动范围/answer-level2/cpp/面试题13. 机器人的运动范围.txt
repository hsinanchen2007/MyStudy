```
class Solution {
public:
    int matrix[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    int count = 0;
    int movingCount(int m, int n, int k) {
        if(k == 0) return 1;
        vector<vector<bool> > visitied(m, vector<bool>(n, false));
        dfs(visitied,0,0,m,n,k);
        return count;
    }
    void dfs(vector<vector<bool>>& visitied, int cur_row, int cur_column, int m, int n, int k){
        if(cur_row < 0 || cur_row >= m || cur_column < 0 || cur_column >= n) return;
        if((cur_row%10 + cur_row/10 + cur_column%10 + cur_column/10) > k) return;
        if(visitied[cur_row][cur_column] == true) return;
        visitied[cur_row][cur_column] = true;
        count++;
        for(int i = 0; i < 4; i++){
            int next_row = cur_row + matrix[i][0];
            int next_column = cur_column + matrix[i][1];
            dfs(visitied, next_row, next_column, m, n, k);                
        }        
    }
};
```
