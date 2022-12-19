### 解题思路
如果一开始不是一个简洁的实现，15分钟内内赶紧换思路吧，又是一个抄袭。
方案一、
* 已经多次利用相对方向移动进行结果判断了
* 利用是否已经查看过，轻松实现螺旋矩阵
* 测试用例第一想到了4*4，建议螺旋形状用纸画一下感受一下。
方案二、
* 参考题解中C++提示不需要seen数据结构改写

### 代码
```java []
// 方案一、比较容易理解人类语言
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if (matrix.length == 0) {
            return ans;
        }

        int rowLen = matrix.length;
        int colLen = matrix[0].length;
        boolean[][] seen = new boolean[rowLen][colLen];
        // 行移动方向 0：不动，1前进，-1 后退
        int[] dr = {0, 1, 0, -1};
        // 列移动方向
        int[] dc = {1, 0, -1, 0};
        int row = 0;
        int col = 0;
        int direction = 0;
        for (int i = 0; i < rowLen * colLen; i++) {
            ans.add(matrix[row][col]);
            seen[row][col] = true;
            // 行方向不变 row + dr[0] = row;
            int changedRow = row + dr[direction];
            // 列方向第一个元素移动1位
            int changedCol = col + dc[direction];

            if (0 <= changedRow && changedRow < rowLen && 0 <= changedCol && changedCol < colLen && !seen[changedRow][changedCol]) {
                row = changedRow;
                col = changedCol;
            } else {
                direction = (direction + 1) % 4;
                row += dr[direction];
                col += dc[direction];
            }
        }
        return ans;
    }
}
```

```java []
// 方案二、参考C++题解改写 
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return answer; //若数组为空，直接返回答案
        }
        int up = 0; //赋值上下左右边界
        int down = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;
        while (true) {
            for (int i = left; i <= right; ++i) {
                //向右移动直到最右
                answer.add(matrix[up][i]);
            }
            if (++up > down) {
                //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
                break;
            }
            for (int i = up; i <= down; ++i) {
                //向下
                answer.add(matrix[i][right]);
            }
            if (--right < left) {
                //重新设定有边界
                break;
            }
            for (int i = right; i >= left; --i) {
                //向左
                answer.add(matrix[down][i]);
            }
            if (--down < up) {
                //重新设定下边界
                break;
            }
            for (int i = down; i >= up; --i) {
                //向上
                answer.add(matrix[i][left]);
            }
            if (++left > right) {
                //重新设定左边界
                break;
            }
        }
        return answer;
    }
}

```