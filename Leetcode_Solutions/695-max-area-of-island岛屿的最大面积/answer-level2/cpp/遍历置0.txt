### 解题思路
典型的dfs题，最直接的思路就是挨个遍历，然后计算结果，当周围是0或者出了矩阵范围时就终止此次遍历。
这里面上下左右是满足要求的下一步，所以存在重复遍历问题，因此，我们需要把遍历过的点置0，这样在下一个点回到此位置时，不会重复计算此位置。
思路很简单，如下。

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        if(rows==0||cols==0)
            return 0;
        int res=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                res=max(res,sidewithside(grid,i,j,rows,cols));
            }
        }
        return res;
    }
    int sidewithside(vector<vector<int>>& grid,int row,int col,int rows,int cols)
    {
        if(row<0||row==rows||col<0||col==cols||grid[row][col]==0)
            return 0;
        grid[row][col]=0;//遍历过，置0
        int dx[4]={1,0,-1,0};//定义四个方向
        int dy[4]={0,1,0,-1};
        int ans=1;//此位置加入面积
        for(int k=0;k<4;k++)
        {
            int next_r=row+dx[k];//换方向
            int next_c=col+dy[k];
            ans+=sidewithside(grid,next_r,next_c,rows,cols);//遍历完所有的一片后将返回，而且由于置0操作，不会重复遍历
        }
        return ans;
    }
};
```