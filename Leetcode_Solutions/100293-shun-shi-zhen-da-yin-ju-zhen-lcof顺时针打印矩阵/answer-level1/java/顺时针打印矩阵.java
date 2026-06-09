### 解题思路
定义上下左右边界，然后根据顺时针来获取数据。
![xxxx.jpg](https://pic.leetcode-cn.com/5d988131219e33667124519a1c8de80ecef0ce48ea386136edbc615cfa45d840-xxxx.jpg)


### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new int[0];
        }
        // 存储结果
        int[] res = new int[matrix.length * matrix[0].length];
        int counter = 0;
        // 定义上下左右边界
        int left = 0, right = matrix[0].length - 1, up = 0, down = matrix.length - 1;
        // 遍历
        while (left <= right && up <= down) {
            // 第一个：从左到右遍历
            for (int i = left; i <= right; i++) {
                res[counter++] = matrix[up][i];
            }
            // 第二个：从上到下遍历
            for (int i = up + 1; i <= down; i++) {
                res[counter++] = matrix[i][right];
            }
            // 第三个：从右到左遍历
            if (up != down) {
                for (int i = right - 1; i >= left; i--) {
                    res[counter++] = matrix[down][i];
                }
            }
            // 第四个：从下到上遍历
            if (left != right) {
                for (int i = down - 1; i > up; i--) {
                    res[counter++] = matrix[i][left];
                }
            }
            left++;
            right--;
            down--;
            up++;
        }
        return res;
    }
}
```