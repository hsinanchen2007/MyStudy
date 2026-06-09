此题比较简单，利用二维数组从左到右，从上到下依次递增的特点，从右上角开始遍历，比当前位置元素小的值都在左上区域，小的都在右下区域
``` java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null||matrix.length==0||matrix[0].length==0){
            return false;
        }
        int row=0;
        int col=matrix[0].length-1;
        while(row<=matrix.length-1&&col>=0){
            if(target==matrix[row][col]){
                return true;
            }
            else if(target<matrix[row][col]){
                col--;
            }else {
                row++;
            }
        }
        return false;
    }
}
```
