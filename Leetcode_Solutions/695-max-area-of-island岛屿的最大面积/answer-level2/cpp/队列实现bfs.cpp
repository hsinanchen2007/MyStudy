### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        queue<int> q;
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int maxi=0;
                if(grid[i][j]==1)
                {
                    maxi=1;
                    grid[i][j]=0;
                    q.push(i*100+j);
                    while(!q.empty())
                    {
                        int pi=q.front()/100;
                        int pj=q.front()%100;
                        q.pop();
                        if(pi>0&&grid[pi-1][pj]==1)
                        {
                            q.push((pi-1)*100+pj);
                            grid[pi-1][pj]=0;
                            maxi++;
                        }
                        if(pj<n-1&&grid[pi][pj+1]==1)
                        {
                            q.push(pi*100+pj+1);
                            grid[pi][pj+1]=0;
                            maxi++;
                        }
                        if(pi<m-1&&grid[pi+1][pj]==1)
                        {
                            q.push((pi+1)*100+pj);
                            grid[pi+1][pj]=0;
                            maxi++;
                        }
                        if(pj>0&&grid[pi][pj-1]==1)
                        {
                            q.push(pi*100+(pj-1));
                            grid[pi][pj-1]=0;
                            maxi++;
                        }
                    }
                }
                ans=max(ans,maxi);
            }
        return ans;
    }
};
```