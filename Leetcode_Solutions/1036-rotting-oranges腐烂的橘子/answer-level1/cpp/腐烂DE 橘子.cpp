```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;//队列用来保存腐烂的橘子
        int row=grid.size();//行
        int lie=grid[0].size();//列
        int count=0;//新鲜橘子的个数
        int time=0;//腐烂的持续时间

        //搜索所有腐烂的橘子并把它们压入队列
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<lie;j++)
            {
                if(grid[i][j]==2)//这颗橘子是腐烂的
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }

        //队列中的橘子开始向四周腐烂
        int d_x[4]={1,0,0,-1};//辅助定位烂橘子上下左右四个橘子的横坐标
        int d_y[4]={0,1,-1,0};//辅助定位烂橘子上下左右四个橘子的纵坐标

        while(!q.empty())
        {
           int size=q.size();//这一批要处理的烂橘子的数量
           for(int n=0;n<size;n++)
           {
               pair<int,int> pos=q.front();
               q.pop();
               for(int i=0;i<4;i++)
               {               
                   int x=pos.first+d_x[i];
                   int y=pos.second+d_y[i];
                   if(x>=0&&x<row&&y>=0&&y<lie&&grid[x][y]==1)//有效而新鲜的橘子；
                   {
                       grid[x][y]=2;//巴拉啦能量，烂橘子，变
                       count--;
                       q.push({x,y});//把新的烂橘子压入队列
                   }
               }
           }
           if(!q.empty())//处理完一批不为空，才说明有新的烂橘子产生
              time++;
        }
        if(count==0)
           return time;
        else
           return -1;
    }
};
```
