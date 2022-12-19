### 解题思路
这题之前做过。就是外圈遍历一次之后重新设置起点，设置矩阵大小。重新遍历，知道所有元素遍历完成。

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0)
            return new int[0];

        int m = matrix.length - 1; 
        int n = matrix[0].length - 1;
        int[] arr = new int[(m+1)*(n+1)];

        int x = 0, y = 0;
        int index = 0;
        while(x <= m && y <= n){
            for(int j = y; j <= n; j++, index++)
                arr[index] = matrix[x][j];
            for(int i = x + 1; i <= m; i++, index++)
                arr[index] = matrix[i][n];
            
            if(x < m && y < n){
                for(int j = n - 1; j > y; j--, index++)
                    arr[index] = matrix[m][j];
                for(int i = m; i > x; i--, index++)
                    arr[index] = matrix[i][y];
            }
            x++;
            m--;
            y++;
            n--;
        }
        return arr;
    }
}
```