### 解题思路
最主要是在本本画出来，更直观
排除法:把大于0的数记录下来，最后总数减去大于0的数，从左下角开始
如果grid[m][n] >=0  说明这列中从这个数往上都是>=0的，positive += n+1;然后排除掉这一列->n++;
如果grid[m][n] <0, 说明这一行从这个数往右都是小于0的，直接排除掉这一行右边的数->m--;
最后 负数的个数=总数-positive
### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        if(grid.length==0) return 0;
        int positive = 0;
        int m = grid.length-1;
        int n = 0;
        while(true){
            if(m<0||n<0||m>=grid.length||n>=grid[0].length) break;
            if(grid[m][n]>=0){
                positive += m+1;
                n++;
            }else{
                m--;
            }
        }
        int res = grid.length*grid[0].length-positive;
        return res;
    }
}
```