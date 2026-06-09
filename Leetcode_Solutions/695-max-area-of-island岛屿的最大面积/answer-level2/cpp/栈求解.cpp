### 解题思路
当遇到一个grid[i][j]=1,的时候把它的相邻位置为1的坐标放入栈中，并都做一下标记，以防重复入站，然后，取出栈顶元素将它的相邻位置为1的放进占中，直到为空为止。遍历数组的每一个位置，都做此相同的操作。

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
       stack<pair<int,int>>s;
       int max=0;
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               int temp=0;
              if(grid[i][j]==1&&dp[i][j]==0)
              {
                 s.push(make_pair(i,j));
                 cout<<i<<","<<j<<endl;
                 dp[i][j]=1;
                 temp++;
                 int x,y;
                 while(!s.empty())
                 {
                    x=s.top().first;
                    y=s.top().second;
                    s.pop();
                    if(x-1>=0&&grid[x-1][y]&&dp[x-1][y]==0)
                    {
                        s.push(make_pair(x-1,y));
                        dp[x-1][y]=1;
                      temp++;
                       cout<<x-1<<","<<y<<endl;
                    }
                    if(x+1<grid.size()&&grid[x+1][y]&&dp[x+1][y]==0)
                    {
                        s.push(make_pair(x+1,y));
                       temp++;
                       dp[x+1][y]=1;
                       cout<<x+1<<","<<y<<endl;
                    }
                    if(y-1>=0&&grid[x][y-1]&&dp[x][y-1]==0)
                    {
                        s.push(make_pair(x,y-1));
                       temp++;
                       dp[x][y-1]=1;
                       cout<<x<<","<<y-1<<endl;
                    }
                    if(y+1<grid[0].size()&&grid[x][y+1]&&dp[x][y+1]==0)
                    {
                        s.push(make_pair(x,y+1));
                        temp++;
                        dp[x][y+1]=1;
                        cout<<x<<","<<y+1<<endl;
                    }
                 }
              }
              max=max>temp?max:temp;
           }
       }
       return max;
    }
};
```