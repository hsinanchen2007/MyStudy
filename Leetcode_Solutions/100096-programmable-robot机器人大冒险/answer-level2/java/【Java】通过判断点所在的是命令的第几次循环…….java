![截屏2019-11-06上午12.47.08.png](https://pic.leetcode-cn.com/40a1cc5ac74a533aafeb7830cfafd9af30d6c8e8e42d92fc637d4d683c96b7fa-%E6%88%AA%E5%B1%8F2019-11-06%E4%B8%8A%E5%8D%8812.47.08.png)


    主要是判断点是否在路线上花了点功夫，通过分析命令的u和r的次数，确定一个简单的函数。通过判断给定坐标是在命令的第几次循环，给定坐标是否在同一个循环中，如果不在一个循环中则肯定不在路线上；如果在一个循环，则判断当前点到上一次循环结束的点的x距离加上y距离的值，然后循环值的次数，按顺序取命令，看命令中的u和r是否能够等于x和y的差值，如果相等则在路线上，如果不等则不在。

    至于答题思路：先判断终点在不在路线上，如果在路线上则判断路障是否在路线上即可。
```
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        // judge whether the target is on the route
        if (!onRoute(command, x, y)) {
            return false;
        }
        // judge whether is there any obstacle on the route before the target coordinate
        for (int[] coordinate : obstacles) {
            int obstacleX = coordinate[0];
            int obstacleY = coordinate[1];
            if (obstacleX > x) {
                continue;
            }
            if (onRoute(command, obstacleX, obstacleY)) {
                return false;
            }
        }
        return true;
    }

    private boolean onRoute(String command, int x, int y) {
        char[] steps = command.toCharArray();
        int rCount = 0;
        int uCount = 0;
        for (char step : steps) {
            switch (step) {
                case 'U':
                    uCount++;
                    break;
                case 'R':
                    rCount++;
                    break;
            }
        }
        if (Math.abs(((double) x / rCount) - ((double) y / uCount)) > 1) {
            return false;
        }
        int rounds = x / rCount;
        int distanceX = x - rounds * rCount;
        int distanceY = y - rounds * uCount;
        int commandsCount = distanceX + distanceY;
        for (int i = 0; i < commandsCount; i++) {
            switch (steps[i]) {
                case 'U':
                    distanceY--;
                    break;
                case 'R':
                    distanceX--;
                    break;
            }
        }
        return distanceX == 0 && distanceY == 0;
    }
}
```
