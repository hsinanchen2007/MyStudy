### 解题思路
使用**BFS** 一层一层去感染
先将腐烂的橘子放到**队列**中（用结构体，队列中存放的是**腐烂橘子的坐标x，y**），作为第一层
用这一层去感染它的上下左右的好橘子 （注意边界），依此弹出队列
然后将这些被感染的好橘子再放入队列，继续感染
每一层都是res++(相当于是一次)

为了考虑那些不会被感染到的橘子
**统计好橘子的数**，被感染后，更新好橘子数（good--）
最后 如果good为0 那么返回res
如果不为0，说明不会被感染，返回-1

### 代码

```cpp
class Solution {
private:
    struct point{
        int x;
        int y;
    };

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<point> q;//用队列存储腐烂的橘子的坐标
        int m=grid.size();
        int n=grid[0].size();
        int good=0; //新鲜橘子
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    good++;
                if(grid[i][j]==2)
                    q.push(point{i,j});
            }
        }
        
        int res=0;
        while(good>0 && !q.empty()){
            res++;
            int k=q.size();//k是腐烂橘子的个数
            for(int i=0;i<k;i++){//依此取出来腐烂橘子 然后感染周围
                point temp=q.front();
                q.pop();
                int row = temp.x;
                int col = temp.y;
                
                //依此判断并感染四周
                //上
                if(row>0 && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    good--;
                    q.push(point{row-1,col});
                }
                //下
                if(row<m-1 && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    good--;
                    q.push(point{row+1,col});
                }
                //左
                if(col>0 && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    good--;
                    q.push(point{row,col-1});
                }
                //右
                if(col<n-1 && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    good--;
                    q.push(point{row,col+1}); 
                }
            }
        }
        
    if(good==0)
       return res;
    else
       return -1;
                    
 }
};
```