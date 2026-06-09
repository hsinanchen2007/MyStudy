### 解题思路
![(69}\[L(YJT~X9WBT`JC1NXJ.png](https://pic.leetcode-cn.com/4868647ad5d8ca659b6ab55784dc818c1649a0e82abf266c753d6f14e75c4475-\(69%7D%5BL\(YJT~X9WBT%60JC1NXJ.png)

螺旋的规律是 向右 - 向下 - 向左 - 向上 构建一个矩形

之后再继续构建内部的矩形


### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int i = 1;
        int X_Begin = 0;
        int X_End = n - 1;
        int Y_Begin = 0;
        int Y_End = n - 1;
        while (i <= n * n){
            //水平向右
            for (int j = X_Begin; j <= X_End; j++){
                res[Y_Begin][j] = i++;
            }
            Y_Begin++;

            //垂直向下
            for (int j = Y_Begin; j <= Y_End; j++){
                res[j][X_End] = i++;
            }
            X_End--;

            //水平向左
            for (int j = X_End; j >= X_Begin; j--){
                res[Y_End][j] = i++;
            }
            Y_End--;

            //水平向上
            for (int j = Y_End; j >= Y_Begin; j--){
                res[j][X_Begin] = i++;
            }
            X_Begin++;
        }

        return res;
    }
}
```