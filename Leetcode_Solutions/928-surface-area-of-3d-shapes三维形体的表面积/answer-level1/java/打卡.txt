### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
int sum =0;
if(grid.length==1)
{
return areaPer(grid[0][0]);
}
for(int i = 0;i < grid.length;i++)
{
   
for(int j = 0;j < grid[0].length;j++)
{
  sum += areaPer(grid[i][j]);
  if(i+1 < grid.length)
  {
    sum -= 2* Math.min(grid[i][j],grid[i+1][j]);
  }
   if(j+1 < grid[0].length)
  {
    sum -= 2* Math.min(grid[i][j],grid[i][j+1]);
  }
}
}
return sum;
    }


    private int areaPer(int n)
    {
        if(n == 0){return 0;}
return 6 * n - 2*(n-1);
    }
}
```