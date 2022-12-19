### 解题思路
![image.png](https://pic.leetcode-cn.com/72c2dd033908edb8f751343f1a126d4bdac5131e9bacd06c5d357f53ec20678a-image.png)
visit用数组怎么做？怎么在函数参数列表定义？是 int visit[][]?? int visit[]?? int visit??

### 代码

```cpp
class Solution {
public:
    const int X[4] = {-1,1,0,0};
    const int Y[4] = {0,0,-1,1};
    int res = 0;
    int helper(int x)
    {
        int sum = 0;
        while((x/10)!=0)
        {
            sum+=x%10;
            x=x/10;
        }
        sum+=x;
        return sum;
    }
    void bfs(int m,int n,int k,int x,int y,vector<vector<bool> > &visit)
    {
        for(int i=0; i<4; ++i)
        {
            if(x+X[i]>=0&&y+Y[i]>=0&&x+X[i]<m&&y+Y[i]<n&&(helper(x+X[i])+helper(y+Y[i]))<=k&&visit[x+X[i]][y+Y[i]]==false)
            {
                visit[x+X[i]][y+Y[i]] = 1;
                ++res;
                bfs(m,n,k,x+X[i],y+Y[i],visit);
            }
        }
    }
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool> > visit(m,vector<bool>(n,false));
        visit[0][0] = 1;
        bfs(m,n,k,0,0,visit);
        return (res+1);
    }
};
```