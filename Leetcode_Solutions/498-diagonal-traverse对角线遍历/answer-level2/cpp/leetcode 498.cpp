### 解题思路
单行单列单独处理，其他分析规律，最好加一些判断语句防止越界。移动的先后顺序判断也有点麻烦

### 代码

```cpp
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
        {
            return {};
        }
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>res;
        int flag=0;
        if(m==1)
        {
            for(int i=0;i<n;i++)
                res.push_back(matrix[0][i]);
            return res;
        }
        else if(n==1)
        {
            for(int i=0;i<m;i++)
            {
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        //0右1左下2下3右上
        int sum=m*n;
        int x=0,y=0;
        //res.push_back(matrix[0][0]);
        while(sum>0)
        {
            if(x>=0&&x<m&&y>=0&&y<n)
                res.push_back(matrix[x][y]);
            if(flag==0)//向右走
            {
                y++;
                if(x==0)//如果第一行就向左下方走
                    flag=1;
                else if(x==m-1)//如果最后一行就向右上方走
                    flag=3;
            }
            else if(flag==1)//向左下方走
            {
                x++;
                y--;
                if(y==0&&x!=m-1)//是第一列就向下走
                {
                    flag=2;
                }
                else if(x==m-1)//最后一行的话就往右走
                    flag=0;
                else 
                    flag=1;
            }
            else if(flag==2)//向下走
            {
                x++;
                if(y==0)
                    flag=3;
                else if(y==n-1)
                    flag=1;
            }
            else //向右上方走
            {
                x--;
                y++;
                if(y==n-1)
                {
                    flag=2;
                }
                else if(x!=0)
                {
                    flag=3;
                }
                else
                    flag=0;
            }
            sum--;
        }
        return res;
    }
};
```