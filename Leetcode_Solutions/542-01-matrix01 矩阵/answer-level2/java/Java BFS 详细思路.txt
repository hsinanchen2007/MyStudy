### 解题思路
前面做了岛屿的相关问题, 这题上来就对值为 1 的进行 DFS 搜索, 出现了 StackOverFlow 错误; 在网上看了其他的思路, 对值为 1 进行搜索的话, 每次处理的就是一个 1, 但是如果对 0 进行处理的话, 就会简单一些, 思路如下 :
1. 遍历一遍矩阵, 将所有的 1 赋值为一个不可能为结果的大值, 比如 Integer.MAX_VALUE, 我这里取的 10000;
2. 将所有的 0 的位置都放到一个队列中
3. 队列中的元素依次出队, 然后与该元素上下左右四个位置的值进行比较, 如果它的邻居结点大于本结点的值 + 1, 那么说明从本结点出发距离更近, 就更新. 同时将更新的位置也添加到队列中
4. 举个例子如下 : 如果理解得不是很明白, 可以去看看这篇博文的图解 [https://segmentfault.com/a/1190000020413729]()

### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int r = matrix.length;
        // 这个需要吗?
        //if (r == 0) return new int[0][0];
        int c = matrix[0].length;
        // 四个方向
        int[][] neighbors = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        LinkedList<int[]> queue = new LinkedList<>();
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) {
                    queue.add(new int[]{i, j});
                } else {
                    matrix[i][j] = 10000;
                }
            }
        }
        while(queue.size() > 0) {
            int[] temp = queue.poll();
            for(int i = 0; i < 4; i++) {
                int x = temp[0] + neighbors[i][0];
                int y = temp[1] + neighbors[i][1];
                if (x >= 0 && y >= 0 && x < r && y < c && (matrix[temp[0]][temp[1]] + 1) < matrix[x][y]) {
                    // 当前位置的值 + 1 < 它的邻居, 那么它的邻居需要被更新
                    matrix[x][y] = matrix[temp[0]][temp[1]] + 1;
                    queue.add(new int[]{x, y});
                }
            }
        }
        return matrix;
    }
}
```