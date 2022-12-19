![QQ截图20200407115125.png](https://pic.leetcode-cn.com/3a9d26e926cb02a95c59d1c116d4720ceb3b5520877bae5b80c06c776ba0664f-QQ%E6%88%AA%E5%9B%BE20200407115125.png)

# 思路

 翻转90°的结果是：matrix[i][j] = matrix[j][N-i-1]
 上下翻转的结果是：matrix[i][j] = matrix[N-i-1][j] 
 再沿主对角线翻转的结果是：matrix[N-i-1][j] = matrix[j][N-i-1] 
 结果一致
# 代码
```
public void rotate(int[][] matrix) {
        int N = matrix.length;
        //先上下翻转
        for(int i=0;i<N/2;i++){
            for(int j=0;j<N;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N-i-1][j];
                matrix[N-i-1][j] = tmp;
            }
        }
        //再沿主对角线翻转
        for(int i=0;i<N;i++){
            for(int j=0;j<=i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
```
