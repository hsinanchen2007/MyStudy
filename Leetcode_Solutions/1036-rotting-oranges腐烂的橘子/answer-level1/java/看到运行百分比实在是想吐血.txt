**第一版本：**
先将腐烂的橘子放入队列，出队遍历队列，将四周的新鲜橘子污染成腐烂橘子，如果有将新鲜的橘子置为腐烂的橘子，加一分钟，继续下一轮。否则跳出遍历。最后查看是否还有新鲜橘子，如有则返回-1。
```
public int orangesRotting(int[][] grid) {
        int count = 0;
        int x = grid.length;
        if (x <= 0) {
            return count;
        }
        int y = grid[0].length;
        while (true) {
            // 如果有将新鲜的橘子置为腐烂的橘子，则为true
            boolean flag = false;
            // 将腐烂的橘子入队
            Queue<Map<Integer, Integer>> queue = new ArrayDeque<>();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (grid[i][j] == 2) {
                        Map<Integer, Integer> map = new HashMap<>(1);
                        map.put(i, j);
                        queue.add(map);
                    }
                }
            }
            // 遍历队列，将四周的新鲜橘子变成腐烂的橘子
            int queueLen = queue.size();
            for (int i = 0; i < queueLen; i++) {
                Map<Integer, Integer> temp = queue.remove();
                int a = 0, b = 0;
                for (Map.Entry<Integer, Integer> entry : temp.entrySet()) {
                    a = entry.getKey();
                    b = entry.getValue();
                    break;
                }
                // 左
                if ((b - 1 >= 0) && grid[a][b - 1] == 1) {
                    grid[a][b - 1] = 2;
                    flag = true;
                }
                // 上
                if ((a - 1 >= 0) && grid[a - 1][b] == 1) {
                    grid[a - 1][b] = 2;
                    flag = true;
                }
                // 右
                if ((b + 1 <= y - 1) && grid[a][b + 1] == 1) {
                    grid[a][b + 1] = 2;
                    flag = true;
                }
                // 下
                if ((a + 1 <= x - 1) && grid[a + 1][b] == 1) {
                    grid[a + 1][b] = 2;
                    flag = true;
                }
            }
            // 如果有将新鲜的橘子置为腐烂的橘子，加一分钟，否则跳出遍历。
            if (flag) {
                count++;
            } else {
                break;
            }
        }
        // 查看是否还有新鲜的橘子
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1) {
                    count = -1;
                    break;
                }
            }
        }
        return count;
    }
```
**第二版本**
在第一版本的基础上，当之前已经腐烂的橘子入队之后，则将腐烂的橘子置为状态3，避免以后再次无效遍历。
```
public int orangesRotting(int[][] grid) {
        int count = 0;
        int x = grid.length;
        if (x <= 0) {
            return count;
        }
        int y = grid[0].length;
        while (true) {
            // 如果有将新鲜的橘子置为腐烂的橘子，则为true
            boolean flag = false;
            // 将腐烂的橘子入队
            Queue<Map<Integer, Integer>> queue = new ArrayDeque<>();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (grid[i][j] == 2) {
                        Map<Integer, Integer> map = new HashMap<>(1);
                        map.put(i, j);
                        queue.add(map);
                        // 避免以后再次访问该橘子
                        grid[i][j] = 3;
                    }
                }
            }
            // 遍历队列，将四周的新鲜橘子变成腐烂的橘子
            int queueLen = queue.size();
            for (int i = 0; i < queueLen; i++) {
                Map<Integer, Integer> temp = queue.remove();
                int a = 0, b = 0;
                for (Map.Entry<Integer, Integer> entry : temp.entrySet()) {
                    a = entry.getKey();
                    b = entry.getValue();
                    break;
                }
                // 左
                if ((b - 1 >= 0) && grid[a][b - 1] == 1) {
                    grid[a][b - 1] = 2;
                    flag = true;
                }
                // 上
                if ((a - 1 >= 0) && grid[a - 1][b] == 1) {
                    grid[a - 1][b] = 2;
                    flag = true;
                }
                // 右
                if ((b + 1 <= y - 1) && grid[a][b + 1] == 1) {
                    grid[a][b + 1] = 2;
                    flag = true;
                }
                // 下
                if ((a + 1 <= x - 1) && grid[a + 1][b] == 1) {
                    grid[a + 1][b] = 2;
                    flag = true;
                }
            }
            // 如果有将新鲜的橘子置为腐烂的橘子，加一分钟，否则跳出遍历。
            if (flag) {
                count++;
            } else {
                break;
            }
        }
        // 查看是否还有新鲜的橘子
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1) {
                    count = -1;
                    break;
                }
            }
        }
        return count;
    }
```
**第三版本**
将队列改成了ArrayList。
```
public int orangesRotting(int[][] grid) {
        int count = 0;
        int x = grid.length;
        if (x <= 0) {
            return count;
        }
        int y = grid[0].length;
        while (true) {
            // 如果有将新鲜的橘子置为腐烂的橘子，则为true
            boolean flag = false;
            // 将腐烂的橘子入队
            List<Map<Integer, Integer>> list = new ArrayList<>();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (grid[i][j] == 2) {
                        Map<Integer, Integer> map = new HashMap<>(1);
                        map.put(i, j);
                        list.add(map);
                        // 避免以后再次访问该橘子
                        grid[i][j] = 3;
                    }
                }
            }
            // 遍历队列，将四周的新鲜橘子变成腐烂的橘子
            int listLen = list.size();
            for (int i = 0; i < listLen; i++) {
                Map<Integer, Integer> temp = list.get(i);
                int a = 0, b = 0;
                for (Map.Entry<Integer, Integer> entry : temp.entrySet()) {
                    a = entry.getKey();
                    b = entry.getValue();
                    break;
                }
                // 左
                if ((b - 1 >= 0) && grid[a][b - 1] == 1) {
                    grid[a][b - 1] = 2;
                    flag = true;
                }
                // 上
                if ((a - 1 >= 0) && grid[a - 1][b] == 1) {
                    grid[a - 1][b] = 2;
                    flag = true;
                }
                // 右
                if ((b + 1 <= y - 1) && grid[a][b + 1] == 1) {
                    grid[a][b + 1] = 2;
                    flag = true;
                }
                // 下
                if ((a + 1 <= x - 1) && grid[a + 1][b] == 1) {
                    grid[a + 1][b] = 2;
                    flag = true;
                }
            }
            // 如果有将新鲜的橘子置为腐烂的橘子，加一分钟，否则跳出遍历。
            if (flag) {
                count++;
            } else {
                break;
            }
        }
        // 查看是否还有新鲜的橘子
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1) {
                    count = -1;
                    break;
                }
            }
        }
        return count;
    }
```
