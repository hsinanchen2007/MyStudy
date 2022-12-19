### 解题思路
![D5056490-3B3F-43F9-BD13-AC44F7F8C6D7.png](https://pic.leetcode-cn.com/a2f8f11d1b559d5def25b0700a25240abe66b1e5b5405c0a242b0b0aa49e867d-D5056490-3B3F-43F9-BD13-AC44F7F8C6D7.png)

此处撰写解题思路
首先先计算出一轮指令向右和向上的步长，后面的每一个循环完成都是移动相同的步长，用于统计障碍物和目标所在的区间。
然后循环每一个障碍物，判断是否可达。
最后判断终点是否可达
时间复杂度 O(m * n) m 为指令的长度，n为障碍物长度
空间复杂度 O(1) 只保存了步长；
### 代码

```java
class Solution {
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int up = 0;//向上的步长
        int right = 0;//向右的步长
        //计算一轮指令的向上和向右的步长
        for (int i = 0; i < command.length(); i ++) {
            if (command.charAt(i) == 'U') {
                up ++;
            } else {
                right ++;
            }
        }
        //计算每一个在范围的障碍物是否可达
        for (int i = 0; i < obstacles.length; i ++) {
            //如果障碍物超出范围，则跳过
            if (obstacles[i][0] > x || obstacles[i][1] > y) {
                continue;
            }
            //cycle为判断障碍物走过了多少次循环，取横坐标和纵坐标除以相应步长的最小值。
            int cycle =  Math.min(obstacles[i][0] / right, obstacles[i][1] / up);
            //减去走过的步长，剩下的则为此次循环应走的步长。
            int targetX = obstacles[i][0] - cycle * right;
            int targetY = obstacles[i][1] - cycle * up;
            //执行指令，判断障碍物是否可达
            for (int j = 0; j < command.length() && (targetX > 0 || targetY > 0); j ++) {
                if (command.charAt(j) == 'U') {
                    targetY --;
                } else {
                    targetX --;
                }
            }
            //如果障碍物可达，则为终点不可达，直接返回
            if (targetX == 0 && targetY == 0) {
                return false;
            }
        }
        //跟障碍物同理，判断终点是否可达
        int cycle =  Math.min(x / right, y / up);
        x = x - cycle * right;
        y = y - cycle * up;
        for (int i = 0; i < command.length() && (y > 0 || x > 0); i ++) {
            if (command.charAt(i) == 'U') {
                y --;
            } else {
                x --;
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        return false;
    }
}
```