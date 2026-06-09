### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    private:
    vector<vector<int>> flag;//用于标记已走格子
    int sum;
    int path;
    int m;
    int n;
    int max(int a,int b)
    {
        if(a>b)
        return a;
        else
        return b;
    }
    int judge(vector<vector<int>>& grid,int rol,int col)//判断格子的状态（是否可以采集）
    {
        if(rol>=m||rol<0||col>=n||col<0)
        {
            return 0;
        }
        if(grid[rol][col]==0)
        {
            return 0;
        }
        if(flag[rol][col]==1)
        {
            return 0;
        }
        return 1;
    }
   void backtrack (vector<vector<int>>& grid,int rol,int col)
    {
       
     if(judge(grid,rol-1,col)==0&&judge(grid,rol+1,col)==0&&judge(grid,rol,col-1)==0&&judge(grid,rol,col+1)==0)//结束条件
        {
            sum=max(sum,path);
        }
     if(judge(grid,rol-1,col)==1)
     {
         path+=grid[rol-1][col];
         flag[rol-1][col]=1;
         backtrack(grid,rol-1,col);
         path-=grid[rol-1][col];
         flag[rol-1][col]=0;
     }
     if(judge(grid,rol+1,col)==1)
     {
         path+=grid[rol+1][col];
         flag[rol+1][col]=1;
         backtrack(grid,rol+1,col);
         path-=grid[rol+1][col];
         flag[rol+1][col]=0;
     }
     if(judge(grid,rol,col-1)==1)
     {
         
         path+=grid[rol][col-1];
         flag[rol][col-1]=1;
         backtrack(grid,rol,col-1);
         path-=grid[rol][col-1];
         flag[rol][col-1]=0;
     }
     if(judge(grid,rol,col+1)==1)
     {
         path+=grid[rol][col+1];
         flag[rol][col+1]=1;
         backtrack(grid,rol,col+1);
         path-=grid[rol][col+1];
         flag[rol][col+1]=0;
     }
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=0;
        m=grid.size();
        if(grid.size()==0)
        {
            return 0;
        }
        n=grid[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int k=0;k<n;k++)
            {
                if(grid[i][k]==0)
                {
                    continue;
                }
                else    
                {
                    flag=temp;
                    sum=0;
                    path=grid[i][k];
                    flag[i][k]=1;
                    backtrack(grid,i,k);
                    res=max(res,sum);
                    flag[i][k]=0;
                }
            }
        }
        return res;

    } 
};
```