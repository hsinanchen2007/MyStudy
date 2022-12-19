### 解题思路
找1的连通分量，最后每个岛屿都会成为一个连通分量，计数加1。
执行用时 :12 ms, 在所有 C++ 提交中击败了88.15%的用户
内存消耗 :10 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int count=0;//记录岛屿数量
        //循环，遇1找连通分量。
        for(int x=0;x<m;x++)
        {
            for(int y=0;y<n;y++)
            {
                if(grid[x][y]=='1')
                {
                    count++;
                    search(grid,x,y,m,n);
                }
            }
        }
        return count;
    }
    //四周循坏找1的连通分量，改为2.
    void search(vector<vector<char>>& grid,int x, int y, int m, int n)
    {
        grid[x][y]=2;
        int x1=x-1;
        if(x1>=0&&x1<m&&grid[x1][y]=='1') search(grid,x1,y,m,n);
        int x2=x+1;
        if(x2>=0&&x2<m&&grid[x2][y]=='1') search(grid,x2,y,m,n);
        int y1=y-1;
        if(y1>=0&&y1<n&&grid[x][y1]=='1') search(grid,x,y1,m,n);
        int y2=y+1;
        if(y2>=0&&y2<n&&grid[x][y2]=='1') search(grid,x,y2,m,n);
    }
};
```