解题思路：模拟法，通过模拟机器人每一步行走，得到最大欧式距离平方
关键点：将障碍物坐标编码为hashcode存在hashSet中，以空间换时间
      可以大大减少行走过程判断是否有障碍物的时间。
       如果有障碍物，机器人不再行走等待下一次转向指令。

```
    public int robotSim(int[] commands, int[][] obstacles) {
        //  初始方向为北，以顺时针方向依次定义： 北 0，东 1，南 2，西 3
        int direction = 0;
        // 定义数组，x轴或者y轴在每个方向前进一步走的距离，四个值分别对应北、东、南、西
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        // 初始坐标
        int x = 0;
        int y = 0;
        // 最大欧式距离平方
        int max = 0;

        // 将障碍物坐标编码为hashcode存在hashSet中
        Set<Long> obstacleSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            long ox = (long) obstacle[0] + 30000L;
            long oy = (long) obstacle[1] + 30000L;
            obstacleSet.add((ox << 16) + oy);
        }

        for (int cmd : commands){
            // 遍历每个指令
            if (cmd == -2) {
                // 向左转，以顺时针方向加3取余
                direction = (direction + 3) % 4;
            } else if (cmd == -1) {
                // 向右转，以顺时针方向加1取余
                direction = (direction + 1) % 4;
            } else {
                // 行进
                for (int i = 0; i < cmd; i++) {
                    int xx = x + dx[direction];
                    int yy = y + dy[direction];
                    long hashCode = (((long) xx + 30000L) << 16) + ((long) yy + 30000L);
                    if (!obstacleSet.contains(hashCode)) {
                        // 如果没有障碍，x轴/y轴走一步
                        x = xx;
                        y = yy;
                        max = Math.max(max, x * x + y * y);
                    }
                }
            }
        }
        return max;
    }

```
