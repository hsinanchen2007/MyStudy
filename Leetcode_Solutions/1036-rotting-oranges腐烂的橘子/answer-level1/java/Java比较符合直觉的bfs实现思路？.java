> 吐槽,话说这道题和 [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 非常类似，后者难度`Medium`，这道题则是`easy`？实在搞不懂难度是如何划分的。

思路如下：

* 1.一次循环找到所有腐烂的橘子，并加入队列；
* 2.判断特殊情况，数组中没有健康的橘子，直接返回0；
* 3.进行bfs，每一轮结束后，将队列中将要进行下一轮搜索 “健康的橘子” 设置为 “腐烂”；
* 4.当队列中没有橘子元素后：
    ** 4.1 此时已经没有健康的橘子，返回step；
    ** 4.2 此时还有健康的橘子，返回-1；

缺点，思路比较直，因为是严格按照`BFS`模版思路走的，因此评分比较低，详见底部截图。

> 因为是严格按照`BFS`模版思路走的, 因此还有优化空间，比如不使用`HashSet`存储，而是直接将对应位置的值设置为2（腐烂的），这样就跳过了额外空间上和时间上的消耗，不过我做题时候 **直觉上** 是优先按照模版来，所以代码写成如下：

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        // 题目已经声明 row 和 col 不为0，因此跳过判断
//        if (row == 0) return 0;
//        if (col == 0) return 0;
        int row = grid.length;
        int col = grid[0].length;

        // 是否全部都是腐烂的橘子
        boolean allOrangesRotting = true;

        final Queue<Node> queue = new LinkedList<>();
        final HashSet<Integer> seen = new HashSet<>();
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == 2) {
                    // 如果是腐烂的橘子，添加到队列
                    queue.offer(new Node(r, c));
                } else if (grid[r][c] == 1 && allOrangesRotting) {
                    // 如果遇到正常的橘子，将标记置为false
                    allOrangesRotting = false;
                }
            }
        }

        // 如果本身内部全是腐烂的橘子，直接返回0
        if (allOrangesRotting) {
            return 0;
        }
        int step = 0;
        // 添加null标记每一轮bfs的结束；
        queue.add(null);

        // 开始bfs
        while (!queue.isEmpty()) {
            Node removed = queue.remove();

            if (removed == null) {
                // 一轮bfs的结束
                if (queue.peek() == null) {
                    // 如果还是null，意味着bfs结束
                    // 检查是否全部都是腐烂的橘子，如果是返回步数，否则返回-1
                    return checkAllOrangesRotting(grid) ? step : -1;
                } else {
                    // 后面还有等待腐烂的橘子，开启新一轮搜索，为队列尾部添加一个null
                    step++;
                    queue.offer(null);
                    // 这轮的橘子全部腐败了
                    for (int position : seen) {
                        int targetRow = position / col;
                        int targetCol = position % col;
                        grid[targetRow][targetCol] = 2;
                    }
                    seen.clear();
                    continue;
                }
            }

            final Node left = removed.left();
            final Node right = removed.right();
            final Node top = removed.top();
            final Node bottom = removed.bottom();
            if (checkOrangeCanRottingNext(grid, seen, left)) {
                seen.add(left.row * col + left.col);
                queue.offer(left);
            }
            if (checkOrangeCanRottingNext(grid, seen, right)) {
                seen.add(right.row * col + right.col);
                queue.offer(right);
            }
            if (checkOrangeCanRottingNext(grid, seen, top)) {
                seen.add(top.row * col + top.col);
                queue.offer(top);
            }
            if (checkOrangeCanRottingNext(grid, seen, bottom)) {
                seen.add(bottom.row * col + bottom.col);
                queue.offer(bottom);
            }
        }
        return step;
    }

    private boolean checkAllOrangesRotting(int[][] grid) {
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1)
                    return false;
            }
        }
        return true;
    }

    private boolean checkOrangeCanRottingNext(int[][] grid, HashSet<Integer> seen, Node node) {
        final int row = grid.length;
        final int col = grid[0].length;
        final int r = node.row;
        final int c = node.col;
        // 边界检查
        if (r < 0 || r >= row || c < 0 || c >= col)
            return false;
        // 如果已经要被感染腐烂，返回false
        if (seen.contains(node.row * col + node.col))
            return false;
        // 指定节点是不是一个新鲜的橘子
        return grid[r][c] == 1;
    }

    class Node {

        int row;
        int col;

        Node(int row, int col) {
            this.row = row;
            this.col = col;
        }

        Node left() {
            return new Node(row, col - 1);
        }

        Node right() {
            return new Node(row, col + 1);
        }

        Node top() {
            return new Node(row - 1, col);
        }

        Node bottom() {
            return new Node(row + 1, col);
        }
    }
}
```

![image.png](https://pic.leetcode-cn.com/7d8f23b1d9afa9324c79b9ac1c99663d430a70002e2f697cddf46d3a037149fd-image.png)
