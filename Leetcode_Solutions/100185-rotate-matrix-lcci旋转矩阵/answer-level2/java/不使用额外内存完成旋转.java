### 解题思路
前提假设：假设元素位置为(x,y)
1.第一次旋转后，位置为(y,n-x+1)
2.第二次旋转后，位置为(n-x+1, n-y+1)
3.第三次旋转后，位置为(n-y+1, x)
4.第四次旋转后，位置为(x, y)
以上可知，经过4次旋转，位置重归原始位置
以[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 为例：
1、以[ 5, 1, 9] 3个元素分别为第一外层旋转起点，经过4次旋转替换后，将11,10,7,16,12,14,15,13,2元素旋转至指定位置，即第一外层处理完毕
2、以[4]为第二外层旋转起点，经过4次旋转替换后，将8,6,3元素旋转至指定位置，即第二外层处理完毕
3、矩阵一共n/2层，第i层有n-i-1个旋转起点，可以将该外层处理完毕

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length / 2; i++) {
            for (int j = i; j < matrix[i].length - i - 1; j++) {
                int nextValue = matrix[i][j];
                int nextX = j;
                int nextY = matrix.length - i - 1;
                while ((nextX != i) || (nextY != j)) {
                    int currentValue = matrix[nextX][nextY];
                    matrix[nextX][nextY] = nextValue;
                    nextValue = currentValue;
                    int y = nextY;
                    nextY = matrix.length - nextX - 1;
                    nextX = y;
                }
                matrix[nextX][nextY] = nextValue;
            }
        }
    }
}
```