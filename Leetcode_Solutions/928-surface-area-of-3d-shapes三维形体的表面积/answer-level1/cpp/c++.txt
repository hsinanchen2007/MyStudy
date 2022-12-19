### 解题思路
此处撰写解题思路
执行用时 :
20 ms
, 在所有 C++ 提交中击败了
5.83%
的用户
内存消耗 :
8.7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
和另一个老哥思路一样，不知道为啥我看他写的时间很短内存很多，我是内存少一点时间很慢。里面可以优化一下，不用我写那么多变量。
思路就是上下重叠向上找，左右的统一向右，前后向前，有接触多少个就减去数量*2，减法的思路

### 代码


```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int size_row = grid.size(); //获取行数
      int size_col = grid[0].size(); //获取列数
      int sum=0,top=0,right=0,front=0,n=0,m=0;
      for(int i=0;i<size_row;i++)
      {
          for(int j=0;j<size_col;j++)
          {
             sum+=grid[i][j]*6;
             if(grid[i][j]!=0)
             {
               top+=(grid[i][j]-1)*2;

             }
            
             if(j+1<size_col)
             {
                 n=(grid[i][j]<=grid[i][j+1])?grid[i][j]:grid[i][j+1];
                 right+=n*2;
                
             }
             if(i+1<size_row)
             {
                 m=(grid[i][j]<=grid[i+1][j])?grid[i][j]:grid[i+1][j];
                 front+=m*2;
             }
          }
      }
        return sum-top-right-front;



    }
};
```