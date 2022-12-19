## 思路  
  每一个点出发进入下一个点时，可以选择当前已存在的路径(cost=0)或者其他路径(cost=1)。
这样问题就转换为了求起点到终点的最短路径的问题。

## 代码
```
class Solution {
public:
    int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//四个方向，和题目中的顺序对应
    int minCost(vector<vector<int>>& grid) {
        int cost[101][101];
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0;i < m;i ++)
            for(int j = 0;j < n;j ++)
                cost[i][j] = -1;//初始化cost图
        
        queue<pair<int,int> > que;
        que.push(make_pair<int,int>(0,0));
        cost[0][0] = 0;//起点
        
        while(!que.empty())
        {
            pair<int,int> now = que.front();
            que.pop();
            
            int x = now.first;
            int y = now.second;
            
            for(int i = 0;i < 4;i ++)
            {
                int nextx = x + step[i][0];
                int nexty = y + step[i][1];
                
                if(nextx < 0 || nextx >= m)
                    continue;
                if(nexty < 0 || nexty >= n)
                    continue;//判断前进方向是否有效
                int add = 1;
                if(grid[x][y] == i + 1)
                    add = 0;
                
                if(cost[nextx][nexty] == -1 || cost[nextx][nexty] > cost[x][y] + add)
                {
                    pair<int,int> tmp(nextx,nexty);
                    que.push(tmp);
                    cost[nextx][nexty] = cost[x][y] + add;//cost值发生变化的点才需要更新和它相关联的点的cost
                }
            }
        }
        return cost[m-1][n-1];
    }
};
```
