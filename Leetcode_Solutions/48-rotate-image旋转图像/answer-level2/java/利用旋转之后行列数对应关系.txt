对应关系为 matrix[i][j]->matrix[j][length-1-j]

```java []
class Solution {
    public void rotate(int[][] matrix) {
        int height = matrix.length;
        int width = matrix[0].length;
        for(int i=0;i<(height/2);i++){
            for(int j=i;j<width-i-1;j++){//关键点，这里列数必须限制，否则会重复。
                int temp1 = matrix[i][j];
                matrix[i][j] = matrix[height-1-j][i];
                matrix[height-1-j][i] = matrix[height-1-i][width-1-j];
                matrix[height-1-i][width-1-j] = matrix[j][width-1-i];
                matrix[j][width-1-i] = temp1; 
            }
        }
    }
}
```



