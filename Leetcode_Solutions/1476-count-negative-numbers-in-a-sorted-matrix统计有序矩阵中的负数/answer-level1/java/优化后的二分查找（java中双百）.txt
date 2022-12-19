### 解题思路
充分利用题目条件：
行非增序列，故在找每行第一个负数时可用二分查找（比线性查找快）；
列也是非增序列，故遍历每行时可以以上一行的第一个负数的索引作为右边界。

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        int num=0,right=n,left=0;
        for(int i=0;i<m;i++){
            // right=left;有没有这句都行，因为上一次循环结束时这句必然成立。
            left=0;
            while(left<right){
                int middle=(left+right)/2;
                if(grid[i][middle]>=0){
                    left=middle+1;
                }else{
                    right=middle;
                }
            }
            num+=(n-left);
        }
        return num;
    }
}
```