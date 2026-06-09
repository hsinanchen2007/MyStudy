可以观察到，原来第row行的，都转移到同一列了，所以可以看出来针对行，有相同的转换公式，经过观察那就是
```
        newCol=n-1-row
```
其中，n为矩阵的阶数。同理，原来第col列的，都转移到同一行了，经过观察可得：
```
        newRow=col
```
所以，顺时针旋转90°的转移方程是：
```
        matrix[i][j] -> matrix[j][n-1-i]
``` 
赋值四次可以循环：
```
        matrix[i][j]         -> matrix[j][n-1-i]
        matrix[j][n-1-i]     -> matrix[n-1-i][n-1-j]
        matrix[n-1-i][n-1-j] -> matrix[n-1-j][i]
        matrix[n-1-j][i]     -> matrix[i][j]
```

本来直接新建一个矩阵，根据上面的公式赋值就可以了。但由于需要在原地旋转，所以参考两元素交换，实现四元素的交换（这里将上一个位置的值赋到[i][j]的位置）：
```
        int t=matrix[i][j];
        matrix[i][j]=matrix[n-1-j][i];
        matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
        matrix[j][n-1-i]=t;
```
然后最坏的办法就是两层for循环，for(i=0;i<n;i++)和for(j=0;j<n;j++)嵌套。但考虑到这样写的话，好多元素都重复交换了，因此只需要循环左上角即可。最终代码：
```
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int t;
        for(int i=0;i<(n+1)/2;i++){
            for(int j=0;j<n/2;j++){
                t=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=t;
            }
        }
    }
```
最终提交结果：（不知道这个内存是在干啥)
Accepted
21/21 cases passed (0 ms)
Your runtime beats 100 % of java submissions
Your memory usage beats 5.28 % of java submissions (37.9 MB)