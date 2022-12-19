首先是优化版，修改了原始数组，将横坐标和纵坐标简化成一个整数，节省了空间和时间。在访问海洋的同时，记录起始海岛的距离。
```
int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 || n==0)
            return -1;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(make_pair(i*n+j,i*n+j));
                }      
            }
        }
        if(q.size()==0 || q.size()==m*n)
            return -1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        pair<int,int> cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=cur.first/n+dx[i],y=cur.first%n+dy[i];
                if(x<0 || x>=m || y<0 || y>=n)
                    continue;
                if(grid[x][y]==1)
                    continue;
                grid[x][y]=1;
                q.push(make_pair(x*n+y,cur.second));
            }
        }
        return abs(cur.first/n-cur.second/n)+abs(cur.first%n-cur.second%n);
    }
```
然后是原始版，未修改数组的，最初版本。

```
int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0 || n==0)
            return -1;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push(make_pair(i,j));
            }
        }
        if(q.size()==0 || q.size()==m*n)
            return -1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        vector<vector<int>> flag(m,vector<int>(n,0));
        pair<int,int> cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=cur.first+dx[i],y=cur.second+dy[i];
                if(x<0 || x>=m || y<0 || y>=n)
                    continue;
                if(flag[x][y]==1 || grid[x][y]==1)
                    continue;
                flag[x][y]=1;
                q.push(make_pair(x,y));
            }
        }
        int dist=INT_MAX;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && (abs(i-cur.first)+abs(j-cur.second))<dist)
                    dist=(abs(i-cur.first)+abs(j-cur.second));
            }
        return dist;
    }
```
