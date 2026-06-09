### 解题思路
把矩阵由外而内分割成一个一个小正方形，
例如
1 2 3
4 5 6
7 8 9
分割成
1 2 3
4 空 6
7 8 9
以及5（更大地矩阵更形象）
可以分割（n/2）- 1次，n为大矩阵边长
对每个小正方形进行旋转，旋转（边长 - 1）次

设小正方形边上元素元素在矩阵中坐标[i][j]
一轮旋转对应的位置为(其余三个)：
[n-j-1][i]
[n-i-1][n-j-1]
[j][n-i-1]
依次旋转即可
### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int m = n - 1;
        for(int i = 0; i < n / 2; i++, m--){
            for(int j = i; j < m; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp;
            }
        } 
    }
}
```