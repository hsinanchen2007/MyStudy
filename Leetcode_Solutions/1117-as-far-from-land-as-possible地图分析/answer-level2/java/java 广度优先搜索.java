![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/ec4b9154fce60e356860c45643ef5dcecea87d8b6aed0d96e5ee56cc48330c5a-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        // 获取行数和列数
        int row = grid.length;
        int col = grid[0].length;
        // 建立一个队列
        Queue<int[]> queue = new LinkedList<>();
        // 将陆地都放到队列中去
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    queue.add(new int[]{i, j});
                }
            }
        }
        if (queue.size() == row * col) return -1;
        // 循环将陆地四周变成陆地。
        int res = -1;//结果，循环的轮次
        int len;//记录队列的长度
        int[][] move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//创建一个行动的二维数组
        while (!queue.isEmpty()) {
            len = queue.size();
            for (int i = 0; i < len; i++) {
                //如果四周有海洋的话，变成陆地，放到队列尾部
                int[] tmp = queue.remove();//弹出来
                for (int k = 0; k < 4; k++) {
                    int x = tmp[0] + move[k][0];
                    int y = tmp[1] + move[k][1];
                    if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 0) {
                        queue.add(new int[]{x, y});
                        grid[x][y] = 1;
                    }
                }
            }
            res++;
        }
        return res;
    }
}
```