### 解题思路
对T贪心，对每个T进行松弛。直到找到终点。
如果T特别大（题目数据里面的T不是很大）代码应该可以改成二分，但是改动难度很大。

### 代码

```cpp
class Solution {
public:
    struct point{int x;int y;};
    int swimInWater(vector<vector<int>>& grid) {
        int size=grid.size();
        int xstep[4]={1,-1,0,0};
        int ystep[4]={0,0,1,-1};
        queue<point> preVisited;
        queue<point> curVisited;
        vector<vector<bool>> vis(size,vector<bool>(size,false));
        preVisited.push({0,0});
        vis[0][0]=true;
        for(int t=0;;++t) {
            while(!preVisited.empty()){
                point curPoint=preVisited.front();
                preVisited.pop();
                if(grid[curPoint.x][curPoint.y]>t){
                    curVisited.push(curPoint);
                }else{
                    if(curPoint.x==size-1&&curPoint.y==size-1){
                        return t;
                    }
                    for(int i=0;i<4;++i){
                        int nextx=curPoint.x+xstep[i];
                        int nexty=curPoint.y+ystep[i];
                        if(nextx>=0&&nextx<size&&nexty>=0&&nexty<size&&!vis[nextx][nexty]){
                            preVisited.push({nextx,nexty});
                            vis[nextx][nexty]=true;
                        }
                    }
                }
            }
            preVisited=curVisited;
            curVisited=queue<point>();
        }
    }
};
```