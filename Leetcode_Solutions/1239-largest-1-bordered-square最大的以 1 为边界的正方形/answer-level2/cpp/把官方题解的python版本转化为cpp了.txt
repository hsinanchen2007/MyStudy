### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
      if(grid.size()==0 || grid.back().size()==0)
    return 0;
int maxlen=0;
int m=grid.size(),n=grid[0].size();
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(grid[i][j]==1)
        {
            bool flag1=true;
            int currlen=maxlen;
            while(i+currlen<m && j+currlen<n)
            {
                bool flag2=true;
                for(int a=i;a<i+currlen+1;a++)
                {
                    if(grid[a][j] !=1)
                    {
                        flag1= false;
                        break;
                    }

                }
                if(!flag1)
                    break;
                for(int b=j;b<j+currlen+1;b++)
                {
                    if(grid[i][b] !=1)
                    {
                        flag1= false;
                        break;
                    }

                }
                if(!flag1)
                    break;
                for(int a=i;a<i+currlen+1;a++)
                {
                    if(grid[a][j+currlen] !=1)
                    {
                        currlen+=1;
                        flag2=false;
                        break;
                    }

                }
                if(!flag2)
                    continue;
                for(int b=j;b<j+currlen+1;b++)
                {
                    if(grid[i+currlen][b] !=1)
                    {
                        currlen+=1;
                        flag2=false;
                        break;
                    }

                }
                if(!flag2)
                    continue;
                currlen+=1;
                maxlen=currlen;
            }
        }
    }

}
    return maxlen*maxlen;
    }
};
```