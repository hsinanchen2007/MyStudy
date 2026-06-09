暴力解答，根据提示->检查每个值是否等于其右下邻居的值。
![image.png](https://pic.leetcode-cn.com/a3ca0b36405f2e5061e3059f8f384101fdf680d1f6191ef93ad8c8c11ead86be-image.png)
```
public  boolean isToeplitzMatrix(int[][] matrix) {
          for (int i = 0; i < matrix.length ; i++) {
            for (int j = 0; j <matrix[i].length ; j++) {
                if (i != matrix.length - 1 &&  j != matrix[i].length - 1 ) {
                    if (matrix[i][j] == matrix[i+1][j+1]){
                        continue;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
```
