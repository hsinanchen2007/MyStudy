根据当前题求的是从左上角到右下角的最小代价的有效路径，可以联想到通过全局搜索来进行实现，而本题又是求的是最小代价，根据队列的性质，只要每一次变化产生的新的位置可以添加到队列中，**率先到达右下角的可以认为是最小代价**。
1. 用bfs做，使用Java中的队列来存储，先将左上角加入队列
2. 队列的头元素弹出，进行处理
     - 首先判断是否与已搜索过的位置相冲突，避免嵌套，当代价大于等于之前的代价时，可以跳过当前位置
     - 然后在当前位置发生转向，转向不能等于将要前进的方向和不能与来时的方向相反，然后将剩下的可能加一次代价后进行添加到队列中
     - 最后按照原本的方向进行前进，到达终点返回，超过边界结束当前路径
3. 当前路径结束循环后，重复2操作，逐一弹出代价相同的位置，直到到达终点

```
class Solution {
    private static int[][] dirs = new int[][]{{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(Integer.MIN_VALUE, 0, 0, 0));  // 将左上角位置压入队列
        int[][] status = new int[m][n];
        for (int[] s : status) {
            Arrays.fill(s, Integer.MAX_VALUE);
        }

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            int i = node.i;
            int j = node.j;
            int count = node.count;
            if (i == m - 1 && j == n - 1) {  // 到达目标位置
                return count;
            } 
            
            int k = 0;
            int pre = node.pre;
            while (i >= 0 && i < m && j >= 0 && j < n) {
                if (status[i][j] <= count) break;
                status[i][j] = count;
                k = grid[i][j];   //获取当前位置的下一步方向
                for (int i1 = 1; i1 <= 4; i1++) {
                    // 不变向到箭头所指或来的方向，左+右=3 下+上==7
                    if (i1 == k || i1 + pre == 3 || i1 + pre == 7) continue;
                    int r = i + dirs[i1][0];
                    int c = j + dirs[i1][1];

                    if (r >= 0 && r < m && c >= 0 && c < n) { // 不越边界的其它方向的变化前进入队
                        queue.offer(new Node(i1, count + 1, r, c));
                    }
                }
                i = i + dirs[k][0];
                j = j + dirs[k][1];
                if (i == m - 1 && j == n - 1) {
                    return count;
                } else if (k + pre == 3 || k + pre == 7) {  // 去往来的方向，直接终止
                    break;
                }
                pre = k;
            }
            

        }
        return 0;
    }

    class Node {
        int pre;  // 先前来的方向
        int count; // 已经花费的代价
        int i;
        int j;
        
        public Node (int pre, int count, int i, int j) {
            this.pre = pre;
            this.count = count;
            this.i = i;
            this.j = j;
        }
    }
}
```
