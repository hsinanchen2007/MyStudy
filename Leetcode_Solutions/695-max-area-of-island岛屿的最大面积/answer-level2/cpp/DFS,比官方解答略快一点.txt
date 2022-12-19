

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); ++j) {
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                if(grid[i][j]==1){
                queuei.push(i);
                queuej.push(j);
                grid[i][j]=0;
                }
                while (!queuei.empty()) {
                    int cur_i = queuei.front(), cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();
                    ++cur;
                    int di[4] = {0, 1,0,-1};
                    int dj[4] = {1, 0,-1,0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        if(next_i<grid.size()&&next_i>=0&&next_j<grid[0].size()&&next_j>=0&&grid[next_i][next_j]==1)        {
                            queuei.push(next_i);
                            queuej.push(next_j);
                            grid[next_i][next_j]=0;
                            }
                    }
                }
                ans = max(ans, cur);
            }
        return ans;
    }
};


```