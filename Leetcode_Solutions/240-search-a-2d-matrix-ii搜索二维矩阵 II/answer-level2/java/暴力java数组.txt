### 解题思路
判断这个二维数组是否不满足要求
定义行，列 对每一行最后一列作比较
因为每一列都是递增，如果遇到列小于带求值的情况，
则加一行，如果列大于求值的话，则列数-1
如果没有这个值的话，返回false


### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false;
        }
        int rows=matrix.length,columns=matrix[0].length;
        int row=0,column=columns-1;
        while(row<rows&&column>=0){
            int num=matrix[row][column];
            if (num==target){
                return true;
            }else if (num>target){
                column--;
            }else {
                row++;
            }
        }
        return false;
    }
}
```