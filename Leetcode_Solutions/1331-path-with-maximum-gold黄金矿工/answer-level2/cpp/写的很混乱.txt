### 解题思路
此处撰写解题思路
没想到第一次就成功了
我做的是很笨的方法用book 记录已经走过的路 类似于走方格 记录走过的值 然后返回最大值
### 代码

```cpp
class Solution {
public:
    int row;
    int line;
    int getMaximumGold(vector<vector<int>>& grid) {
        row=grid.size();
        line=grid[0].size();
        int max=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<line;j++)
            {
                if(grid[i][j]!=0)
                {
                    vector<vector<int>> book(row,vector<int>(line,0));
                    int temp=fun(i,j,book,grid);
                    if(temp>max)
                    max=temp;

                }
            }
        }
        return max;

    }
    int fun(int i,int j,vector<vector<int>> &book,vector<vector<int>>& grid)
    {
        if(i<0||i>=row||j<0||j>=line||grid[i][j]==0||book[i][j]==1)
        return 0;
        int max=0;
        book[i][j]=1;
        int temp;
        for(int k=0;k<4;k++)
        {     
            if(k==0)
            {
               temp =grid[i][j]+fun(i-1,j,book,grid);
            }else if(k==1)
            {
                 temp =grid[i][j]+fun(i,j+1,book,grid);
            }else if(k==2)
            {
                 temp =grid[i][j]+fun(i+1,j,book,grid);
            }else 
            {
                 temp =grid[i][j]+fun(i,j-1,book,grid);
            }
            if(temp>max)
            max=temp;
        }
        book[i][j]=0;
        return max;

    }
};
```