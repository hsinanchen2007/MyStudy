### 解题思路
最开始的时候，我的思路是遍历所有的1，对于每个1，一层一层向外搜索，直至找到0，这样超时了。
看了大佬们的讲解，思路豁然开朗.
1. 首先遍历matrix，对于非零点，设置一个较大值（row+col）
2. 维护一个队列，首先将所有零点的坐标放入队列中
3. 取出队列中的元素（i，j），搜索（i，j）的四个方向，如果某方向上的值大于或等于（matrix[i][j]+1),就将该方向的坐标值更新为matrix[i][j]+1,这是局部正确的。
4. 然后将该方向的坐标加入队列
5. 重复3-4步骤，直到队列为空。

### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        //灵活应对四个方向的变化
        int[][] vector = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    // 将所有 0 元素作为 BFS 第一层
                    queue.add(new int[]{i, j});
                } else {
                    //设一个最大值
                    matrix[i][j] = row + col;
                }
            }
        }
        while (!queue.isEmpty()) {
            int[] s = queue.poll();
            // 搜索上下左右四个方向
            for (int[] v : vector) {
                int r = s[0] + v[0];
                int c = s[1] + v[1];
                if (r >= 0 && r < row && c >= 0 && c < col){
                    if (matrix[r][c] >= matrix[s[0]][s[1]] + 1){
                        matrix[r][c] = matrix[s[0]][s[1]] + 1;
                        queue.add(new int[]{r, c});
                    }
                }
            }
        }
        return matrix;
    }
}
```