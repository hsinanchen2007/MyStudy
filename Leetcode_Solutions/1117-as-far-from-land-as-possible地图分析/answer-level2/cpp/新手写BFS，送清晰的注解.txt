### 
    将所有陆地加入队列同时开始bfs，每个陆地第一次遇到的海洋
    就是海洋到所有陆地的最短距离
    最后返回这个最大值
    提前判断地图是否全是陆地，可以节约时间
    BFS过程的处理：对于这个题目来说，每一层的BFS完成后，当然距离+1 啦， 这道题确实算很简单的BFS，BFS过程的操作就是记录步骤距离

### 代码

```cpp

// 标准的 BFS
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        rowSize = grid.size(); colSize = grid[0].size();
        // 使用pair存储 [i,j] 坐标
        queue<Pair> q;
        vector<vector<bool>> vis(rowSize, vector<bool>(colSize, false));   // visit[][] 数组    
        
        // 将1作为bfs的start，将所有的1入队
        for(int i=0;i<rowSize;i++) {
            for(int j=0;j<colSize;j++) {
                if(grid[i][j]) {
                    q.push( {i,j} );
                    vis[i][j] = true;
                }
            }
        }

        if(q.size()==0 || q.size()==rowSize*colSize)    return -1;
        
        int distance = 0;
        while(!q.empty()) {
            auto bfsSize = q.size();
            while(bfsSize--) {    // 进行当前层完整的 BFS 
                auto p = q.front();  
                q.pop();
                for(int i=0;i<4;++i) {
                    int tmpx = p.first + dir[i][0];
                    int tmpy = p.second + dir[i][1];
                    if(tmpx < 0 ||tmpx >= rowSize || tmpy < 0 || tmpy >= colSize || vis[tmpx][tmpy]) {
                        continue;    // 一定要注意此处，不是return
                    }
                    
                    q.push(Pair(tmpx, tmpy));
                    grid[tmpx][tmpy] = 1;
                    vis[tmpx][tmpy] = true;
                }                    
            }
            distance++;   // 每一层的BFS完成后，当然距离+1 啦， 这道题确实算很简单的BFS，BFS过程的操作就是记录步骤距离
        }
        return distance-1;
    }

private:
    int dir[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
    int colSize, rowSize;
    using Pair = pair<int, int>;
};
```