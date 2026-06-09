### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean flag[][] = new boolean[matrix.length][matrix[0].length];
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    int tmpI = 0, tmpJ = 0;
                    while(tmpI < matrix.length){
                        flag[tmpI][j] = true;
                        tmpI++;
                    }
                    while(tmpJ < matrix[0].length){
                        flag[i][tmpJ] = true;
                        tmpJ++;
                    }
                }
            }
        }
        for(int i = 0;i<matrix.length;i++){
            for(int j = 0;j<matrix[0].length;j++){
                if(flag[i][j] == true){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
```