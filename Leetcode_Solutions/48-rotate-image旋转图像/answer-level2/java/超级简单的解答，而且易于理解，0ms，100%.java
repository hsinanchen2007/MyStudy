这个做法的灵感来自于***中，螺旋打印矩阵的那一道题，每一次处理正方形的一圈，并以四个角的点的坐标之间的关系，抓住不变的行值或者列值，能够很快得到变换坐标之间的关系
```
 public void rotate(int[][] matrix) {
        int n=matrix.length;
        //这里如果i<n-2也是可以的，但是必须要处理一下两阶的矩阵，以为两阶的矩阵，n-2不会被旋转。而一阶的不用处理。  
        for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
    }
```
