### 解题思路
自己没有想到能够直接改变原数组的方法。因为存在一个问题，如果在遍历过程中，就顺便改变原数组的话，那么遍历后序的数组元素的时候，将会产生歧义。

所以我主要是用了一个同等大小的Boolean数组，用于保存所有应该被置为0的位置。最后再次进行遍历，将Boolean数组中被标记的部分，在原数组中也进行转换。

用boolean数组的话，我觉得占用的空间应该会更少一点吧！

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        if(matrix == null || matrix.length == 0){
            return;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] flag = new boolean[m][n];
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j ++){
                if (matrix[i][j] == 0){
                    int row = 0;
                    int col = 0;
                    while(row < m ){
                        if (!flag[row][j]){
                            flag[row][j] = true;
                        }
                        row++;
                    }
                    while(col < n ){
                        if (!flag[i][col]){
                            flag[i][col] = true;
                        }
                        col++;
                    }
                }
            }
        }
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                matrix[i][j] = flag[i][j] ? 0:matrix[i][j];
            }
        }
    }
}
```