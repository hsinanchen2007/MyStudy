双指针可以将N^2的搜索空间降低为N; 本题可以从左下角开始寻找target, 也可以从右上角开始寻找target
当前元素不等于target时, 此时要么舍弃一行, 要么舍弃一列
```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        //input check
        if(matrix==null || matrix.length==0 || matrix[0]==null || matrix[0].length==0)
            return false;
        //
        int rows = matrix.length, cols = matrix[0].length;
        //从左下角开始找
        int i=rows-1, j=0;
        while(i>=0 && j<cols){
            int cur = matrix[i][j];
            if(cur > target)
                i--;
            else if(cur<target)
                j++;
            else
                return true;
        }
        return false;  
    }
}
```