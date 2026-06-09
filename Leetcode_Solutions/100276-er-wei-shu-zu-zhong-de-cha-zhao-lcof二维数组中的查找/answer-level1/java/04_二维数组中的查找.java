### 解题思路
题目规定，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
我们可以从二维数组右上角或者左下角进行遍历。
如果从二维数组右上角进行遍历的话，
如果该位置的元素等于target，那么就返回true；
如果该位置的元素大于target的话，那么列数减1，因为要查询的元素必在当前列的左边；
如果该位置的元素小于target的话，那么行数加1，因为要查询的元素必在当前列的下边

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int rows=matrix.length;
        if (matrix==null||rows==0) return false;
        int cols=matrix[0].length;
        if (cols==0) return false;
        int x=0;
        int y=cols-1;
        while (x<rows&&y>=0){
            if (matrix[x][y]==target){
                return true;
            }else if (matrix[x][y]>target){
                y--;
            }else {
                x++;
            }
        }
        return false;
    }
}
```