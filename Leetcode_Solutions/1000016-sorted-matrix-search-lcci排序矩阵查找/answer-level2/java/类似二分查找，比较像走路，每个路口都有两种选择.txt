```
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int x = matrix.length-1;
        int y = 0;
        while(x>=0 && x<=matrix.length-1 && y>=0 && y<=matrix[0].length-1){
            if(target > matrix[x][y]){
                y++;
                continue;
            }
            if(target < matrix[x][y]){
                x--;
                continue;
            }
            if(target == matrix[x][y]){
                return true;
            }
        }
        return false;
    }
}
```
由题得到，从左下角或者右上角，对角线上的数都是中位数，所以我们可以从左下角或者右上角走
我以左下角为例，matrix[x][y]
如果大于target，就y++；
如果小于target，就x--;
如果等于返回true;
以上方法在循环中执行，而边界就是，如果找不到target，你最终一定会走出矩阵的边界，那么这个条件就是循环判断的边界
注：y++和x--之后都要跟continue来避免后面不必要执行的代码影响结果
