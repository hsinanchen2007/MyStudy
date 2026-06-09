# 思路
这里的顺序其实就是BFS的遍历过程。每次从队列中取出数据距离就会加1。具体代码如下

```java

    public int[][] allCellsDistOrder(int rowCount, int colCount, int r0, int c0) {
        LinkedList<int[]> queue = new LinkedList<>();
        queue.add(new int[] {r0, c0});
        boolean[][] visited = new boolean[rowCount][colCount];
        visited[r0][c0] = true;

        int[][] ansArr = new int[rowCount*colCount][2];
        int num = 0;

        while (!queue.isEmpty()) {
            List<int[]> nodeList = new ArrayList<>();
            while (!queue.isEmpty()) {
                int[] node = queue.removeFirst();
                ansArr[num++] = node;
                nodeList.add(node);
            }

            for (int[] node : nodeList) {
                int row = node[0];
                int col = node[1];

                // 上
                if (row > 0 && !visited[row - 1][col]) {
                    queue.add(new int[]{row-1, col});
                    visited[row - 1][col] = true;
                }

                // 下
                if (row < rowCount - 1 && !visited[row + 1][col]) {
                    queue.add(new int[]{row+1, col});
                    visited[row + 1][col] = true;
                }

                // 左
                if (col > 0 && !visited[row][col-1]) {
                    queue.add(new int[]{row, col-1});
                    visited[row][col-1] = true;
                }

                // 右
                if (col < colCount - 1 && !visited[row][col+1]) {
                    queue.add(new int[]{row, col+1});
                    visited[row][col+1] = true;
                }
            }
        }

        return ansArr;

    }

```
