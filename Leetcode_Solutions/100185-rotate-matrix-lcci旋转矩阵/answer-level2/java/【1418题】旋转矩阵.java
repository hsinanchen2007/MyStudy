**题意分析**
(1) 给定 N * N 的矩阵表示图像，也就是行数和列数相等。
(2) 每个像素大小为 4 字节，表示表示每个元素为 int 类型。
(3) 将矩阵顺时针旋转 90 度（转魔方的感觉）。
*** 题目进阶要求不占用额外内存空间，应该主要是指不使用额外容器辅助。

**方法一：推演结果**
思路：
(1) 最简单的想法就是定义一个临时容器推演结果，然后整体拷贝。
*** 虽然题目要求进阶，还是先把最先想到的写下来，也方便之后考虑。
(2) 按矩阵第一行思考，旋转后第一行变成了最后一列，每一行的顺序对应旋转后每一列的顺序。
*** 同理推演每一行（也就是所有位置）将当前位置对应到旋转后的位置为
temp[j][N - i - 1] = matrix[i][j]
(3) 按照对应关系推演每一个像素旋转后的位置并记录，遍历结束后将记录的位置拷贝回原数组。
```
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        int[][] temp = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[j][N - i - 1] = matrix[i][j];
            }
        }
        // 遍历将推演结果拷贝回原数组。
        for (int i = 0; i < N; i++) {
            System.arraycopy(temp[i], 0, matrix[i], 0, N);
        }
    }
}
```

**方法二：直接旋转**
思路：
(1) 因为是正方形矩阵，所以旋转一个位置一定同时牵动了其它三个位置。
(2) 根据方法一中的位置对应关系将当前位置带入，推出四个位置的变化关系。
(3) 限定遍历范围，确保每一个位置都只旋转一次并覆盖到所有发生变化的位置。 
如果是偶数边长的矩阵，可以横竖分别对折平分成四个小正方形；
如果是奇数边长，则排除中心位置（旋转后位置不变），按高比宽长一位（或者相反）的平分成四个小矩形。
(4) 遍历完成后将数组返回。
```
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 外层循环遍历到中间位置，奇数边长包含中间位置。
        for (int i = 0; i < (N + 1) / 2; i++) {
            // 内层循环遍历到中间位置，奇数边长不包含中间位置。
            for (int j = 0; j < N / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - j - 1][i];
                matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
                matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
                matrix[j][N - i - 1] = temp;
            }
        }
    }
}
```

**方法三：翻转**
思路：
这种思维可以只考虑正方形四个角，或者找一张抽纸（亲测），也是有几种不同的反转组合的。
(1) 按示例1，先以对角线 159 对称反转 使得 7 和 3 位置互换。
(2) 然后水平方向左右翻转使得 1 和 7 互换， 3 和 9 互换，1397顺时针 90 度变成 7139 。
```
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 主对角线翻转。
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // 左右翻转。
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][N - j - 1];
                matrix[i][N - j - 1] = temp;
            }
        }
    }
}
```
