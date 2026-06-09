### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int count=0;
    int i=grid.length-1,j=grid[0].length-1;
       while(grid[i][j]<0&&i>=0){
           for(int k=j;k>=0;k--){
               if(grid[i][k]<0)count++;
               else break;
           }
           if(i>=0)
           i--;
           if(i==-1)break;
       }
       return count;
    }
}
```