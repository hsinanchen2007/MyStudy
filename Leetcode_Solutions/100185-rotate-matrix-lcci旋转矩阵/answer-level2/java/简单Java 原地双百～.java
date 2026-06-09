// 🙋打卡


// ``` Java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        // 先以对角线（左上-右下）为轴进行翻转
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // 再对每一行以中点进行翻转
        int mid = n >> 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mid; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = tmp;
            }
        }
    }
}
// ```

// 如下图，先由对角线 `[1, 5, 9]` 为轴进行翻转：
// ![image.png](https://pic.leetcode-cn.com/7c85f9932eeae5a454cd0e825106c972c719ed4401f7ab62bc4092c7239ff41b-image.png)

// 于是数组变成了:
// ```
[1,4,7]
[2,5,8]
[3,6,9]
// ```

// 再对每一行以中点进行翻转，就得到了

// ```
[7,4,1]
[8,5,2]
[9,6,3]
// ```


// ❤️ 欢迎大佬们随手关注下我的公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】❤️