### 解题思路
先沿着对角线对折，然后左右对折，实现的效果和旋转 90 度一样。
```
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
```
对角线对折后变成：
```
[
  [1,4,7],
  [2,5,8],
  [3,6,9]
]
```
左右对折后变成：
```
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```
![image.png](https://pic.leetcode-cn.com/e17967b2708981c01e373294b16a5337ea87b8cedaa2dcc2b547a292ee257551-image.png)

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            int l = 0, r = matrix.length - 1;
            while (l < r) {
                int t = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = t;
                l ++;
                r --;
            }
        }
    }
}
```