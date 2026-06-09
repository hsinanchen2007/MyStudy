### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[][] matrix_;
    public void rotate(int[][] matrix) {
        matrix_ = matrix;
        for (int i = 0; i < matrix_.length / 2; i++){
            oneStep(i, i, matrix_.length - i * 2);
        }
    }

    public void oneStep(int x, int y, int length){
        for (int i = 0; i < length - 1; i++){
            int temp = matrix_[x][y + i];
            matrix_[x][y + i] = matrix_[x + length - 1 - i][y];
            matrix_[x + length - 1 - i][y] = matrix_[x + length - 1][y + length - 1 - i];
            matrix_[x + length - 1][y + length - 1 - i] = matrix_[x + i][y + length - 1];
            matrix_[x + i][y + length - 1] = temp;
        }
    }
}
```