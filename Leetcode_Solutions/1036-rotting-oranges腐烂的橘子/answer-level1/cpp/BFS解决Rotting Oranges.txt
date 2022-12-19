### 解题思路
- 找到所有腐烂的橙子，加入队列
- 当队列非空，执行如下操作直到队列空
    - 当队列非空，执行如下操作直到队列空
        - 一直出队腐烂的橙子到一个数组vec中
    - 对数组中每一个元素，执行如下操作
        - 让其周围的有合法位置的橙子腐烂，并进队
- 根据以上模拟过程输出time或者-1即可

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int width=grid[0].size();
        int height=grid.size();
        queue<Location>que;
        int count=0;
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                if(grid[i][j]==2){
                    que.push(Location(i,j));
                    ++count;
                }
                else if(grid[i][j]==1){
                    ++count;
                }
            }
        }
        Location l(0,0);
        int time=0;
        while(que.empty()==false){
            vector<Location>vec;
            while(que.empty()==false){
                l=que.front();
                que.pop();
                --count;
                vec.push_back(l);
            }
            ++time;
            int vec_size=vec.size();
            for(int i=0;i<vec_size;++i){
                if(vec[i].x>0&&grid[vec[i].x-1][vec[i].y]==1){
                    grid[vec[i].x-1][vec[i].y]=2;
                    que.push(Location(vec[i].x-1,vec[i].y));
                }
                if(vec[i].y>0&&grid[vec[i].x][vec[i].y-1]==1){
                    grid[vec[i].x][vec[i].y-1]=2;
                    que.push(Location(vec[i].x,vec[i].y-1));
                }
                if(vec[i].x<height-1&&grid[vec[i].x+1][vec[i].y]==1){
                    grid[vec[i].x+1][vec[i].y]=2;
                    que.push(Location(vec[i].x+1,vec[i].y));
                }
                if(vec[i].y<width-1&&grid[vec[i].x][vec[i].y+1]==1){
                    grid[vec[i].x][vec[i].y+1]=2;
                    que.push(Location(vec[i].x,vec[i].y+1));
                }
            }
        }
        if(count==0){
            if(time==0){
                return 0;
            }
            return time-1;
        }
        return -1;
    }
private:
    struct Location{
        int x;
        int y;
        Location(int x_val, int y_val): x(x_val),y(y_val){};
    };
};
```