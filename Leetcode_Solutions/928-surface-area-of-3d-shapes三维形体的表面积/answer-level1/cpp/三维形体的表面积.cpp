### 解题思路
利用遍历，在计算共有多少块正方形的同时，计算出重叠部分，重叠有三种情况：上下（高度-1）x2，左右（同行最低点）x2，前后（同列最低点）x2。要注意左右和前后要从第二行第二列开始算起，否则会出现重复删减的问题。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int s=0,sum=0,a=0,b=0,c=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]>1) b+=grid[i][j]-1;                //上下
                if(j>0) a+=min(grid[i][j],grid[i][j-1]);            //左右
                if(i>0) c+=min(grid[i][j],grid[i-1][j]);          //前后
                sum+=grid[i][j];
            }
        }
        s=sum*6-(a+b+c)*2;
        return s;
    }
};
```