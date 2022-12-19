### 解题思路
将矩阵顺时针旋转90°分解为两个步骤：
第一步：将矩阵以j=N/2为轴中心对称交换
第二步：将矩阵以i=j为轴中心对称交换

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // step1：矩阵以j=N/2轴镜像交换
        for (int j=0; j<N/2; j++) {
            for (int i=0; i<N; i++) {
                swap(matrix, i, j, i, (N-1-j));
            }
        }
        // step2: 矩阵以i=j轴镜像交换
        for (int i=0; i<N; i++) {
            for (int j=0; j<N-1-i; j++) {
                swap(matrix, i, j, (N-1-j), (N-1-i));
            }
        }
    }
    
    public void swap(int[][] matrix, int i1, int j1, int i2, int j2) {
        if (i1==i2 && j1==j2) return;
        matrix[i1][j1] = matrix[i1][j1] + matrix[i2][j2];
        matrix[i2][j2] = matrix[i1][j1] - matrix[i2][j2];
        matrix[i1][j1] = matrix[i1][j1] - matrix[i2][j2];
    }
}
```