### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        // 1、暴力寻找
        // 2、先找对角线，找到比自己大的点，从该点分别向上，向左比较到顶端。
        // 如果横向大于竖向，n>m，则对角线到底还没找到大的点时，往右找。
        // 同理，m<n时，对角线结束后往下找。 O(logn+n)
        // 3、官解线性查找：从右上角往下找。O(logn)
        if( matrix.length==0 || matrix[0].length==0) return false;
        int row = 0;
        int col = matrix[0].length-1;
        while( row <  matrix.length && col >= 0){
            if(matrix[row][col]==target){
                return true;
            }
            if( matrix[row][col] > target ) col--;
            else row++;
        }
        return false;
    }
}
```