### 解题思路
看到该题目最直接的算法是广度优先遍历
- 初始时，将所有的腐烂橘子的坐标入队，同时记录新鲜橘子的个数
- 每一轮次的循环都将上一次入队的所有腐烂橘子周围的橘子进行判断，
- 如果是好橘子则**腐烂**，同时**好橘子的个数-1**，**设置标志位**，表示有橘子腐烂便于统计时间，并将**该橘子的下标入队**

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int perfect = 0;//记录新鲜橘子的数量
        int res = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                    ++perfect;
            }
        }
        while(!q.empty()){
            int k = q.size();
            int flag = 0;
            while(k--){
                vector<int> temp;
                temp = q.front();
                q.pop();
                int i = temp[0];
                int j = temp[1];
                
                if(i - 1 >= 0 && grid[i - 1][j] == 1){
                    perfect--;
                    grid[i - 1][j]++;
                    q.push({i - 1, j});
                    flag = 1;
                }
                if(i + 1 < grid.size() && grid[i + 1][j] == 1){
                    perfect--;
                    grid[i + 1][j]++;
                    q.push({i + 1, j});
                    flag = 1;
                }
                if(j - 1 >= 0 && grid[i][j - 1] == 1){
                    perfect--;
                    grid[i][j - 1]++;
                    q.push({i, j - 1});
                    flag = 1;
                }
                if(j + 1 < grid[0].size() && grid[i][j + 1] == 1){
                    perfect--;
                    grid[i][j + 1]++;
                    q.push({i, j + 1});
                    flag = 1;
                } 
                              
            } 
            if(flag == 1)
                    ++res; 
        }
        return perfect == 0 ? res : -1;
    }
};
```