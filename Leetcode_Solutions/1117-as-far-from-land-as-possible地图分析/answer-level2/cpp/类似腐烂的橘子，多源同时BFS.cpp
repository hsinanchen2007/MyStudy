### 解题思路
执行用时击败21.56%。
不可以用BFSTrave()的思想，即从海洋出发，这样子最后一个用例会超时。
所以类似与腐烂的橘子，从每一个陆地出发，不断BFS，知道所有的海洋都变成陆地。
步骤：
1、把所有陆地进队，判断是否全是陆地或者没有陆地；
2、从每个陆地出发，把周围的海洋变成陆地，直到全图都是陆地的时候break；
3、返回step。

### 代码

```cpp
class Solution {
public:
        vector<pair<int, int>> op;
    int maxDistance(vector<vector<int>>& grid) {
        //使用多源图的BFS，对每一个1节点进行BFS
        int n=grid.size();
        op.push_back(pair<int, int>(0, -1));//up
        op.push_back(pair<int, int>(0, 1));//down
        op.push_back(pair<int, int>(-1, 0));//right
        op.push_back(pair<int, int>(1, 0));//left
        queue<pair<int, int>> q;
        int num=0;
        for (int i=0; i<n; i++){//把所有的1入队
            for (int j=0; j<n; j++){
                if (grid[i][j]==1){
                    q.push(pair<int, int>(i,j));
                    num++;
                }
            }
        }
        if (num==0 || num==n*n) return -1;//判断是否只有陆地或者海洋
        int step=0;
        while (!q.empty()){
            if (num == n*n) break;
            step++;
            int len=q.size();
            while(len){
                pair<int, int> now=q.front();
                q.pop();
                int ii,jj;
                for (int i=0; i<4; i++){
                    ii=now.first+op[i].first;
                    jj=now.second+op[i].second;
                    if (ii>=0 && ii<n && jj>=0 && jj<n){
                        if (grid[ii][jj]==0){
                            grid[ii][jj]=1;//把海洋变成陆地，0变成1
                            q.push(pair<int, int>(ii, jj));
                            num++;
                            if (num==n*n) break;//如果全图都是陆地，BFS结束
                        }
                    }
                    else continue;
                }
                if (num==n*n) break;
                len--;  
            }
        }
        return step;

    }
    
};
```