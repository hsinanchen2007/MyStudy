### 解题思路
照着官方打了一遍

### 代码

```cpp
class Solution {
private:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int n=grid.size();           //行
        const int m=grid[0].size();        //列
        int minutes[n][m];          //记录grid[i][j]上apple腐烂的分钟
        memset(minutes,0,sizeof(minutes));  //时间置零
        int count=0;                   //新鲜apple数
        int x=0,y=0;                    
        int result=0;
        queue<pair<int,int> > Q;        //存放腐烂苹果的坐标
        for(int i=0;i<n;++i)             //记录坏苹果位置，好苹果计数          
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]==2)
                    Q.push(make_pair(i,j));
                else if(grid[i][j]==1)
                    ++count;
            }
        while(!Q.empty())
        {
            for(int i=0;i<4;++i)
            {
                int x0=Q.front().first;  //location of current bad apple
                int y0=Q.front().second; //
                
                x=x0+dx[i];
                y=y0+dy[i];
                if(x<0||x>=n||y<0||y>=m||grid[x][y]!=1) continue;   //防止越界
                minutes[x][y]=minutes[x0][y0]+1;           //最妙之处
                if(grid[x][y]==1)                            //若为好苹果
                {
                    --count;                                //好苹果-1
                    grid[x][y]=2;                           //该处好苹果腐烂
                    Q.push(make_pair(x,y));                 //变腐烂，入Q
                    result=minutes[x][y];                   //最新的时间
                }
                if(count==0)break; //这里不要用return，否则当Q一开始就空的时候根本不会执行这里
                                   //苹果腐烂完要立刻退出
            }
            Q.pop();
        }
        return count?-1:result; 
    }
};
```