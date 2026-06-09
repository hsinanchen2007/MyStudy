### 解题思路
相对比较简单 思路也很明确 

### 代码

```cpp
class Solution {
public:


    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, int& sum){
      visited[i][j] = 1;
      sum++;
      if(i+1 < grid.size() && grid[i+1][j] == 1 && visited[i+1][j] == 0)
        DFS(grid, i+1, j, visited, sum);
      if(j+1 < grid[0].size() && grid[i][j+1] == 1 && visited[i][j+1] == 0)
        DFS(grid, i, j+1, visited, sum);
      if(j-1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == 0)
        DFS(grid, i, j-1, visited, sum);
      if(i-1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0)
        DFS(grid, i-1, j, visited, sum);
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      if(grid.size() == 0) return 0;
      int result = 0;
      vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(visited[i][j] == 0 && grid[i][j] == 1){
            int sum = 0;
            DFS(grid, i, j, visited, sum);
            result = max(sum, result);
          }
        }
      }
      
      return result;
    }
};
```