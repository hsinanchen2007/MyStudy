### 解题思路
这一题需要变换思路。当当前数不满足的时候有两条路走是非常不好解决的。所以需要根据题目的意思来重新选择路径。
所以选择右上角作为初始位置。如果当前数小于，则往左走；如果当前数大于，则往下走；如果就是当前数，则找到了。


### 代码

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0)
            return false;
        int m = matrix.length;
        int n = matrix[0].length;
        
        for(int i = 0, j = n - 1; i < m && j >= 0; ){
            if(matrix[i][j] > target)
                j--;
            else if(matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
}
```