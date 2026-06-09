### 解题思路
1. 用两个队列，一个队列`work`记录当前值为`2`的**下标**，另一个队列`record`记录当前格子是经过几分钟走到的。
2. 初始时将所有值为`2`的的**下标**加入`work`队，`record`队列中对应的值都为`0`（可以理解为经过0分钟该下标的橘子是腐烂的橘子）
3. 依次弹出`work`队列的队首元素`ele`和`record`队列的队首元素`tmp`。看下标为`ele`的位置是否有相邻的新鲜格子。若有，将该相邻位置下标加入到`work`队列，同时将值`tmp+1`加入到`record`队列。
4. 一直执行步骤`3.`，直到队列空。
5. 判断是否还有新鲜橘子，有返回`-1`，没有返回代码中所求的最小分钟数`ans`
### 代码

```cpp
class Solution {
public:
    using PII = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<PII> work;
        queue<int> record;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    work.push({i, j});
                    record.push(0);
                }
            }
        }
        int ans = 0;
        vector<vector<int>> dxy = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        while(!work.empty()){
            auto ele = work.front(); work.pop();
            int tmp = record.front(); record.pop();
            ans = max(ans, tmp);
            for(auto xy: dxy){
                int x = ele.first + xy[0];
                int y = ele.second + xy[1];
                if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1) continue;
                else{
                    grid[x][y] = 2;
                    work.push({x,y});
                    record.push(tmp+1);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
```