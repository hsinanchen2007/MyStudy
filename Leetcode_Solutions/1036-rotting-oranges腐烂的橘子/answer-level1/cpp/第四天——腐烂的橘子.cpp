### 解题思路
- 使用一个queue结构

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;    //记录时间
        int flag = 0;
        int row = grid.size();
        int col = grid[0].size();
        int num_fresh_oranges = 0;    //新鲜橘子数量
        int num_bad_oranges = 0;      //腐烂橘子数量
        queue<pair<int, int>> bad_oranges;
        pair<int, int> index;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(int i = 0; i < row; i++){     //统计新鲜橘子和腐烂橘子数量
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1)
                    num_fresh_oranges++;
                else if(grid[i][j] == 2){
                    bad_oranges.push(make_pair(i, j));
                }
            }
        }

        while(!bad_oranges.empty()){
            int n = bad_oranges.size();
            flag = 0;
            for(int i = 0; i < n; i++){
                index = bad_oranges.front();
                bad_oranges.pop();
                for(auto cur:dirs){
                    int i = index.first + cur.first;
                    int j = index.second + cur.second;
                    if(i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1){
                        grid[i][j] = 2;
                        bad_oranges.push(make_pair(i, j));
                        num_fresh_oranges--;
                        flag = 1;
                    }
                }
            }
            if(flag) time++;
        }
        return num_fresh_oranges?-1:time;   
    }
};
```