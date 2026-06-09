### 解题思路
从边界标记完不能更改的'O',再更改所有未标记的'O'

### 代码

```cpp
class Solution 
{
public:
    vector<vector<bool>> vis;
    vector<vector<int>> dir;
    int M,N;

    void solve(vector<vector<char>>& m) 
    {
        if(m.empty()) return;

        M=m.size(),N=m[0].size();
        vis=vector<vector<bool>>(M,vector<bool>(N,false));
        dir={{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<M;i++)   
        {
            if(m[i][0]=='O' && !vis[i][0])  //左边界
                DFS(m,i,0);
            if(m[i][N-1]=='O' && !vis[i][N-1])  //右边界
                DFS(m,i,N-1);
        }
        for(int j=0;j<N;j++)
        {
            if(m[0][j]=='O' && !vis[0][j])  //上边界
                DFS(m,0,j);
            if(m[M-1][j]=='O' && !vis[M-1][j])  //下边界
                DFS(m,M-1,j);
        }

        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if(m[i][j]=='O' && !vis[i][j])
                    m[i][j]='X';
    }

    void DFS(vector<vector<char>>& m,int i,int j)
    {
        vis[i][j]=true;

        for(auto d:dir)
        {
            int _i=i+d[0],_j=j+d[1];

            if(can(_i,_j) && m[_i][_j]=='O' && !vis[_i][_j]) 
                DFS(m,_i,_j); 
        }
    }

    bool can(int i,int j)
    {
        return i>=0 && i<M && j>=0 && j<N;
    }
};
```