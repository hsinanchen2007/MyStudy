### 解题思路
从右上开始比较，比target小则+1，比target大则列-1

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length<1||matrix[0].length<1||target<matrix[0][0]||target>matrix[matrix.length-1][matrix[0].length-1])return false;
        int x=0,y=matrix[0].length-1;
        while(x<matrix.length&&y>=0){
            if(matrix[x][y]==target) return true;
            if(matrix[x][y]>target)y--;
            else x++;
        }         
        return false;
    }
}
```