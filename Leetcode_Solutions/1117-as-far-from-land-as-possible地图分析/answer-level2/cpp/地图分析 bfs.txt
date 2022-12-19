### 解题思路
1. 把地图上所有陆地的坐标入队queue<pair<int,int>>q
2. 遍历队列，从队列里的每一块陆地出发访问上下左右四处的海洋，并把访问到的海洋也看作陆地入队
3. 每次访问到海洋时，把他的值改为 **“此次访问的出发点的值+1”** .这是为了**避免重复访问**和**记录距离**
4. 找最终结过的时候要-1，因为记录结果的时候的初始值是1

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};
        
        int n = grid.size();
        queue<pair<int,int>>q;
        //所有陆地入队
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1){
                    q.push(make_pair(i,j));
                }
            }
        }
        //从每个陆地开始一圈一圈遍历海洋
        bool hasOcean=false;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            //取出队列中陆地元素，把该陆地周围的海洋也看作陆地入队
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0||newx>=n || newy<0||newy>=n || grid[newx][newy] != 0)
                    continue;
                grid[newx][newy] = grid[x][y]+1;
                q.push(make_pair(newx,newy));
                hasOcean=true;          //不存在全是陆地的情况
            }
        }
        
        if(hasOcean == false)
            return -1;
        
        int res=0;
        for(int i = 0;i < n;i++){
           for(int j = 0;j < n;j++){
                res = max(res,grid[i][j]);
           }
        }
        return res-1;
    }
};
```