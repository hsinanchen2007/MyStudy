### 执行结果
执行用时 :9 ms, 在所有 Java 提交中击败了92.73%的用户
内存消耗 :55.3 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路
动态规划思想：从数组的 matrix[1][1] 开始从左往右，从上到下开始遍历，如果当前元素的左、左上、上三个方向相邻的元素都不为 0 时，(1) 三个元素相等，matrix[i][i] = matrix[i-1][i-1] + 1; (2) 三个元素不相等，matrix[i][i] 等于其中最小的元素 + 1。
时间复杂度：O(n^2);
空间复杂度：O(1);


### 代码

```java
class Solution {
    public int countSquares(int[][] matrix) {

        int sum = 0;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){

                if((i > 0) && (j > 0)){
                    if((matrix[i][j] != 0) && (matrix[i-1][j] != 0) && (matrix[i][j-1] != 0))
                    {
                        if((matrix[i-1][j-1] == matrix[i-1][j]) && (matrix[i-1][j-1] == matrix[i][j-1]))
                            matrix[i][j] = matrix[i-1][j-1] + 1;
                        else
                            matrix[i][j] = Math.min(matrix[i-1][j-1], Math.min(matrix[i-1][j], matrix[i][j-1])) + 1;
                    }
                }
                sum += matrix[i][j];
            }
        }
        return sum;
    }
}
```