### 解题思路
寻找距离陆地最近的海洋时采用BFS搜索，这样，当遇到grid=1的当前陆地就是距离当前海洋最近的陆地；BFS性质决定

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
            queue<pair<int,int> >q;
            int  dx[4]={0,1,0,-1};
            int  dy[4]={1,0,-1,0};

            bool   flag=false;
            int m=grid.size();
            int n=grid[0].size();
            int curmax=-1;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==0)
                  {
                      //cout<<"当前  ："<<i<<"   "<<j<<endl;
                    int  curmin=-1;
                   
                  bool vis[m][n];
                  memset(vis,0,sizeof vis);

                        q.push(pair<int,int>(i,j));
                        vis[i][j]=1;
                        bool flag=false;
                        while(!q.empty())
                        {
                            pair<int,int> cur=q.front();
                            int x0=cur.first;
                            int y0=cur.second;
                         // cout<<"x0: "<<x0<<" y0: "<<y0<<endl;
                            q.pop();
                            for(int k=0;k<4;k++)
                            {
                                int x1=x0+dx[k];
                                int y1=y0+dy[k];
                                
                              //  cout<<"x1:   "<<x1<<"   y1:  "<<y1<<endl;
                                if(x1>=0&&x1<m&&y1>=0&&y1<n)
                                {
                                    if(grid[x1][y1]==0)
                                    {
                                        if(!vis[x1][y1])
                                        {
                                q.push(pair<int,int>(x1,y1));
                              //  cout<<x1<<"    "<<y1<<endl;
                                vis[x1][y1]=1;
                                        }
                                    }
                                    else
                                    {
                                         curmin=abs(x1-i)+abs(y1-j);
                                         flag=true;
                              //   cout<<"curmin:   "<<curmin<<"   "<<x1<<"   "<<y1<<endl;
                                 break;
                                    }
                               

                                }
                            }
                            if(flag)
                            break;
                        }
                        while(!q.empty())
                        q.pop();
                     curmax=max(curmax,curmin); 
                    // cout<<"    max:   "<<curmax<<endl;
                  }
                }
            }
          
    return  curmax;




    }
};
```