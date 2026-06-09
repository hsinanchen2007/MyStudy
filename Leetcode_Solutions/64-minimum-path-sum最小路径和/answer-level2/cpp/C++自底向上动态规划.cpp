```
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    else if (grid.size() == 1) {
      int sum = 0;
      for (size_t i = 0; i < grid[0].size(); i++)
      {
        sum += grid[0][i];
      }
      return sum;
    }
    else {
      vector<int>& last_row = grid[grid.size() - 1];
      for (int i = last_row.size() - 2; i >= 0; i--)
      {
        last_row[i] = last_row[i] + last_row[i + 1];
      }
      vector<int>& prev = last_row;
      for (int i = grid.size() - 2; i >= 0; i--)
      {
        vector<int>& cur = grid[i];
        for (int j = cur.size() - 1; j >= 0; j--)
        {
          if (j == cur.size() - 1) {
            cur[j] = cur[j] + prev[j];
          }
          else {
            cur[j] = cur[j] + min(prev[j], cur[j + 1]);
          }
        }
        prev = cur;
      }
      
      return grid[0][0];
    }
  }
};
```
