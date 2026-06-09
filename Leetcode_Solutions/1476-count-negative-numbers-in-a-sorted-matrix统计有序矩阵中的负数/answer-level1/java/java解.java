### 解题思路
两层for循环，找到索引下标，然后计算即可。

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
       int sum=0;
        int t=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]>=0) t++;
            }
            sum=sum+grid[i].length-t;
            t=0;
        }
        return sum;
}
}
```