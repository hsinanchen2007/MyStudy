### 解题思路
不用思考就是弗洛伊德算法，猛着往上就行～

### 代码

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<vector<int>>> graph(n,vector<vector<int>>(n,vector<int>(1,10000)));
        for(int i=0;i<edges.size();++i)
        {
            int x,y,vel;
            x=edges[i][0];y=edges[i][1];vel=edges[i][2];
            graph[x][y][0]=vel;
            graph[y][x][0]=vel;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    double tp=graph[j][i][0]+graph[i][k][0];
                    if(tp<graph[j][k][0])
                        graph[j][k][0]=tp;
                }
            }
        }
        int max1=INT_MAX;int maxind=-1;
        for(int i=0;i<n;++i)
        {
            int count=0;
            for(int j=0;j<n;++j)
                if(graph[i][j][0]<=distanceThreshold&&i!=j)
                    ++count;
            if(count<=max1)
            {
                max1=count;
                maxind=i;
            }
        }
        return maxind;
    }
};
```