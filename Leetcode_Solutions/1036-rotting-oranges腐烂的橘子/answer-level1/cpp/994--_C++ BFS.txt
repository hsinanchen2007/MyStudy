### 解题思路
广度优先算法（Breadth-First-Search），简称BFS，是一种图形搜索演算法。BFS是从根节点开始，沿着树的宽度遍历树的节点，如果发现目标，则演算终止。


### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int, int>> q; //使用队列的原因是便于进行模拟：已经腐蚀的橘子下一分钟周围都会腐蚀，那么这个橘子其实也没有多大用处了，先进先出特性符合这种规律
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) fresh++;//新鲜橘子
                else if(grid[i][j] == 2) q.push({i, j});//腐烂橘子定位
        }
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//腐蚀的四个方向
        while(!q.empty()) {
            int n = q.size();//当前存在腐蚀橘子的个数
            bool rotten = false;
            for(int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                for(auto cur: dirs) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;//i和j位置计算
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;
        } 
        return fresh ? -1 : min;
    }
};
```