> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```
public class _48 {
    public void rotate(int[][] matrix) {
        int start = 0, end = matrix.length - 1;
        while (start < end) {
            int[] temp = matrix[start];
            matrix[start] = matrix[end];
            matrix[end] = temp;
            start++;
            end--;
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i + 1; j < matrix[i].length; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}
```
