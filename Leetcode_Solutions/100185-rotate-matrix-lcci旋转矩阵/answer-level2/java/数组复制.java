### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int[][] arr = new int[matrix.length][matrix[0].length];
        for(int i=0;i<matrix.length;i++){
            for(int j=matrix[i].length-1;j>=0;j--){
                int k = Math.abs(arr.length-1-j);
                arr[i][k] = matrix[j][i];
            }
        }
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                matrix[i][j] = arr[i][j];
            }
        }
    }
}
```