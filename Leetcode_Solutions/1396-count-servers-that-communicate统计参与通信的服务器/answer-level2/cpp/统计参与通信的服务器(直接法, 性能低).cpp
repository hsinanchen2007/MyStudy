### 解题思路
### 代码

```cpp
class Solution 
{
public:
    int n,m,num;
    vector<vector<int>> vis;

    int countServers(vector<vector<int>>& g) 
    {
        if(g.size()==0) return 0;
        n=g.size(),m=g[0].size(),num=0;
        vis=vector<vector<int>>(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                search(i,j,g);

        return num;
    }

    void search(int i,int j,vector<vector<int>>& g)
    {
        if(!g[i][j] || vis[i][j]) return;
        vis[i][j]=1;
        bool find=false;

        for(int _i=0;_i<n;_i++)
        {
            if(_i!=i && g[_i][j])
            {
                if(!vis[_i][j])
                    vis[_i][j]=1,num++;
                find=true;
            }
        }

        for(int _j=0;_j<m;_j++)
        {
            if(_j!=j && g[i][_j])
            {
                if(!vis[i][_j])
                    vis[i][_j]=1,num++;
                find=true;
            }
        }

        if(find) num++;
    }
};
```