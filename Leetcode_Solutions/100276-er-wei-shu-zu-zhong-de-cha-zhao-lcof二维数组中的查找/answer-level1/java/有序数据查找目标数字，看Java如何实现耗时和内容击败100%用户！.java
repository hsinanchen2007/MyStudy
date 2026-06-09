### 解题思路
题目矩阵是从左到右递增，从上到下递增，可从矩阵右上角开始查找，直到查找到相等数字，返回true。

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0) {
            return false;
        }
        int raw = matrix.length;
        int col = matrix[0].length;
        int i = 0;
        int j = col -1;
        while(i < raw && j >= 0){
            if(matrix[i][j] > target){
                j--;
            } else if (matrix[i][j] < target){
                i++;
            } else {
                return true;
            }
        }
        return false;
    }
}
```