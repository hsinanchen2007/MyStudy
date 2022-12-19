### 思路
使用bfs模拟6种倒水的操作
1. 将水壶1的水倒满；
2. 将水壶1的水清空；
3. 将水壶2的水倒满；
4. 将水壶2的水清空；
5. 将水壶1的水倒入水壶2中，知道水壶2满了或者水壶1没水了就停止倒；
6. 将水壶2的水倒入水壶1中，知道水壶1满了或者水壶2没水了就停止倒；

而且，不同的操作，中间过程会有很多重复的状态。因此可以用一个HashSet来记录已经访问过的状态(x,y)

```java
 private LinkedList<int[]> queue;
    private Set<Long> visited;
    private int capY;

    private void handle(int x, int y) {
        long key = x * (capY + 1L) + y;
        if (!visited.contains(key)) {
            queue.offer(new int[]{x, y});
            visited.add(key);
        }
    }

    private boolean bfs(int capX, int capY, int z) {
        this.capY = capY;
        queue = new LinkedList<>();
        queue.add(new int[]{0, 0});
        visited = new HashSet<>();
        visited.add(0L);

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] node = queue.poll();
                int curX = node[0];
                int curY = node[1];

                if (curX + curY == z || curX == z || curY == z) {
                    return true;
                }

                // 水壶1装满
                handle(capX, curY);
                // 水壶1清空
                handle(0, curY);
                // 水壶2装满
                handle(curX, capY);
                // 水壶2清空
                handle(curX, 0);
                // 水壶1往水壶2倒
                int diff1 = Integer.min(curX, capY - curY);
                handle(curX - diff1, curY + diff1);
                // 水壶2往水壶1倒
                int diff2 = Integer.min(curY, capX - curX);
                handle(curX + diff2, curY - diff2);
            }
        }

        return false;
    }

    public boolean canMeasureWater(int x, int y, int z) {
        if (z == x || z == y || z == 0) {
            return true;
        }

        if (x + y < z || x == y && x + y != z) {
            return false;
        }

        return bfs(x, y, z);
    }
```