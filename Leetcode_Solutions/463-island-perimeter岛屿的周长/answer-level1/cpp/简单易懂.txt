### 解题思路
一个格子的岛屿的四个方向的长度是1，周长为4。当格子岛左右上下有n（0<=n<=4）个相邻格子岛，那么这个格子岛的周长就减少n个。我们只需遍历所有各自，找到所有格子岛，并判断该格子岛周围有没有相邻格子岛，计算出该格子岛周长，将计算结果累积起来即可。

### 代码

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int sum=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=4;
                    if(i-1>=0 && grid[i-1][j]==1)
                    {
                        temp--;
                    }
                    if(j-1>=0 && grid[i][j-1]==1)
                    {
                        temp--;
                    }
                    if(i+1<grid.size() && grid[i+1][j]==1)
                    {
                        temp--;
                    }
                    if(j+1<grid[i].size() && grid[i][j+1]==1)
                    {
                        temp--;
                    }
                    sum+=temp;
                }
            }
        }
        
        return sum;

    }
};
```