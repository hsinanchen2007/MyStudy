![WX20191202-234531@2x.png](https://pic.leetcode-cn.com/2870b65167e8d0a63c3fd22cd1c6c6c75dec5191ac032c44752f365351e8d9e7-WX20191202-234531@2x.png)

```
public static void rotate(int[][] matrix) {
    /*矩阵宽*/
    int x = matrix.length;
    /*复制一个矩阵*/
    int[][] copy=copy(matrix);
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        /*旋转90度，按照规律可得如下赋值*/
        matrix[j][x-1-i]=copy[i][j];
      }
    }
  }

  public static int[][] copy(int[][] matrix){
    int x=matrix.length;
    int[][] copy=new int[x][x];
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        copy[i][j]=matrix[i][j];
      }
    }
    return copy;
  }
```
