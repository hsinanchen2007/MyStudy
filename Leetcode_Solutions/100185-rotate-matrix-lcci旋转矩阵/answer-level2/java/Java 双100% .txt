### 解题思路
* 先翻转矩阵，此时旋转了45°
* 即:
* [1,4,7]
* [2,5,8]
* [3,6,9]
* 在将矩阵左右倒置
* 即:
* [7,4,1]
* [8,5,2]
* [9,6,3]

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int x = 1;
        if (n%2==1){
            x = n/2-1;
        }else{
            x = n/2-2;
        }
        for (int i = 0; i <= n/2+x; i++) {
            for (int j = i; j < n; j++) {
                int tem;
                tem = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tem;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int tem;
                tem = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tem;

            }
        }

    }


}
```