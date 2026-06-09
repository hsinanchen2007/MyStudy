### 解题思路
双层循环判断每一个元素是否w为负数（即grid[i][j]<0）,因为是非递增，所以一旦找到负数，则其后面的元素均为负数，直接跳出本次循环。
（小菜鸟分享捂脸逃emm~）

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0){
                    count+=(n-j);
                    break;
                }
            }
        }
        return count;
    }
}
```