### 解题思路
这一题在leetcode中做过。取右端点为起始点就是解题关键。

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0)
            return false;
        
        int m = matrix.length;
        int n = matrix[0].length;
        int i = 0, j = n - 1;
        
        while(i >= 0 && j >= 0 && i < m && j < n){
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