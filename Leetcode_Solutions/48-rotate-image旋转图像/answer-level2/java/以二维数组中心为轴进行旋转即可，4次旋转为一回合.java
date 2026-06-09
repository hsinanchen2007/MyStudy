因为是90°顺时针旋转，所以旋转前后的数组下标有如下关系：
[x,y] ==> [y, matrix.length - 1 - x],至于数学证明可以百度上找
```
class Solution {
    public void rotate(int[][] matrix) {       
        int length = matrix.length;

        // i代表行数，因为是旋转，所以只需要遍历一半的行数
        for(int i = 0; i < length / 2; i ++) {
            // j代表列，同样只需要遍历一半，长度为奇数时需要向上取整
            for(int j = 0; j < (length + 1) / 2; j ++) {
                int x = j;
                int y = length - 1 - i;
                int tmp = matrix[x][y];
                matrix[x][y] = matrix[i][j];

                do {
                    int swap = x;
                    x = y;
                    y = length - 1 - swap;

                    int temp = matrix[x][y];
                    matrix[x][y] = tmp;
                    tmp = temp;
                } while(x != i || y != j);   
            }
        }   
    }
}
```
