### 解题思路
烂橘子腐烂问题---BFS广度优先搜索法

### 代码

```cpp
class Solution 
{
public:
     int orangesRotting(vector<vector<int>>& grid) 
     {
         int n = grid.size();
         int m = grid[0].size();
         int orangeNum = 0;
         queue<pair<int,int>>Q;
        //首先把所有的烂橘子拿出来，并以pair的形式保存的网格坐标
         for(int i = 0;i<n;i++)      
             for(int j= 0;j<m;j++) 
                 if(grid[i][j] ==2)
                      Q.push(make_pair(i,j));
        //对应四个腐蚀的方向---X+1，X-1，Y+1，Y-1
        vector<int>xDir={0,0,1,-1};
        vector<int>yDir={1,-1,0,0};
    
        while(!Q.empty())
        {
            //首先将原始的烂橘子腐蚀，腐蚀后的好橘子（1变2）放入到queue容器
            int num = Q.size(); //烂橘子数量
            for(int i = 0; i < num; i++)
            {
                pair<int,int>temp =Q.front();
                Q.pop();
                for(int j=0;j< 4;j++)
                {
                    int x1=temp.first + xDir[j];
                    int y1=temp.second+ yDir[j];
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1)
                    {
                        grid[x1][y1] = 2;
                        Q.push(make_pair(x1,y1));
                    }
                }
            }
            //若腐蚀一次，容器即为空：表示腐蚀不到好橘子，或者已经无好橘子，所以不需要进行腐蚀
            //若腐蚀后，容器仍不为空：表示腐蚀到了好橘子，+1
            if(!Q.empty())
                 orangeNum++;
        }

        //全部腐蚀后判断是否存在好橘子
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
              if(grid[i][j] ==1)
                return -1;
        return orangeNum;
     }


};
```