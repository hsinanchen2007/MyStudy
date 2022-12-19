**很多题解已经讲了思路，我这里只说下如何确定旋转后的坐标：** 

![image.png](https://pic.leetcode-cn.com/066cc311a8857f6bfa0eccd0e3fcd0c11e6a98353c2f973ed7447c31bf7570a5-image.png)

a 点坐标`[i][j]`，可以看做从左上角`[0][0]`向下走`i`，再向右走`j`；  
旋转后到 b 点，可以看做右上角`[0][N-1]`向左走`i`，再向下走`j`，即`[j][N-1-i]`；  
再旋转后到 c 点，可以看做右下角`[N-1][N-1]`向上走`i`，再向左走`j`，即`[N-1-i][N-1-j]`；  
再旋转后到 d 点，可以看做左下角`[N-1][0]`向右走`i`，再向上走`j`，即`[N-1-j][i]`；  
确定坐标后，把这四个坐标的数交换一下就行了。 

我刚开始的做法是旋转四个角正方形；然后判断N是不是奇数，若是奇数则还要处理中间边。中间边也类似，从中点m`[N/2][N/2]`分别向上走`i`、向右走`i`、向下走`i`、向左走`i`，就是要旋转的四个位置。附上辣鸡代码：

```java []
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 换角
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i]; // 左下角对应的位置
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]; // 右下角对应的位置
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]; // 右上角对应的位置
                matrix[j][N - 1 - i] = temp;
            }
        }
        // 如果N是奇数，还要换中心边，中心点不用换
        if (N % 2 == 1) {
            int m = N / 2;
            for (int i = 1; i <= m; i++) {
                int temp = matrix[m - i][m];
                matrix[m - i][m] = matrix[m][m - i];
                matrix[m][m - i] = matrix[m + i][m];
                matrix[m + i][m] = matrix[m][m + i];
                matrix[m][m + i] = temp;
            }
        }
    }
}
```

当然，完全可以把一个角正方形添加一条中间边变成角矩形，然后旋转四个角矩形，坐标变换方式是一样的：
![image.png](https://pic.leetcode-cn.com/0ce127907739de3b389c03fef5704d4d0af2366e4962dd50076eb4755ba8dd19-image.png)


```java []
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 角矩形长宽
        int height = N / 2;
        // int width = N % 2 == 0 ? N / 2 : N / 2 + 1;
        int width = (N + 1) / 2;
        // 换角
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - 1 - j][i]; // 左下角对应的位置
                matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j]; // 右下角对应的位置
                matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i]; // 右上角对应的位置
                matrix[j][N - 1 - i] = temp;
            }
        }
    }
}
```