### 解题思路
使用队列来解决BFS的问题，首先将坏橘子的位置放入队列，同时统计好橘子的数量。
然后从坏橘子的位置对四个方向进行搜索，碰到好橘子就会变坏，即赋值为2，然后将该点存入队列，同时好橘子数量减一。
最后根据好橘子的数量确定返回值

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int M=(int)grid.size(),N=(int)grid[0].size(),count=0;
        //count用来表示好橘子的数量
        queue<pair<int,int>>Q;
        //存储坏橘子位置的队列
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
                else if(grid[i][j]==2)
                {
                    Q.push(make_pair(i,j));
                }
            }
        }
        int round=0;
        //好橘子变坏经过的轮数
        while(count>0 && !Q.empty())
        {
            round++;
            int n=Q.size();
            for(int i=1;i<=n;i++)
            {
                pair<int,int>temp=Q.front();
                Q.pop();
                int x=temp.first,y=temp.second;
                //上
                if(x-1>=0 && grid[x-1][y]==1)
                {
                    grid[x-1][y]=2;
                    count--;
                    Q.push(pair(x-1,y));
                }
                //下
                if(x+1<M && grid[x+1][y]==1)
                {
                    grid[x+1][y]=2;
                    count--;
                    Q.push(pair(x+1,y));
                }
                //左
                if(y-1>=0 && grid[x][y-1]==1)
                {
                    grid[x][y-1]=2;
                    count--;
                    Q.push(pair(x,y-1));
                }
                //右
                if(y+1<N && grid[x][y+1]==1)
                {
                    grid[x][y+1]=2;
                    count--;
                    Q.push(pair(x,y+1));
                }
            }
        }
        return (count>0)?-1:round;

    }
};
```