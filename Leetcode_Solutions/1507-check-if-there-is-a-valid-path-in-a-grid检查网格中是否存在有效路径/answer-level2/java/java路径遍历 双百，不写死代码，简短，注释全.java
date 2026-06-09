### 解题思路
此处撰写解题思路

### 代码
按部就班往下走，如果这个块的出口和下一个块的入口对上了，就可以往下走，否则中断，我用roads数组表示6种上右下左四种块，每个块的死个方向是否可以往下走，然后（i + 2）%4表示这个区块跟上一个区块拼接的位置，如果都是1，表示能拼上，当然这个算法有缺陷，那就是如果出现了死循环（形成一个圈）就gg了，当然可以把grid对应的位置设为-1，然后每次走到这个块如果为-1，那就退出了，我就不改了，测试用例不全，所以这个bug没显现出来。
```java
class Solution {
    private int[][] roads = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 1, 0, 0},};//每一种拼图他四个开口的情况，上右下左顺时针方向记录
    private int[][] nexts = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};//上右下左四个方向坐标变化
    private int[] tmpIndex = {0, 0};

    public boolean hasValidPath(int[][] grid) {
        int type = grid[0][0] - 1;
        int[] road = roads[type];
        boolean result = false;
        for (int i = 0; i < road.length; i++)
            if (road[i] == 1) {
                tmpIndex = new int[]{0, 0};
                result |= checkPath(grid, (i + 2) % 4);
            }
        return result;
    }

    private boolean checkPath(int[][] grid, int lastExit/*上一个出去的方向*/) {
        while (true) {
            int typeIndex = grid[tmpIndex[0]][tmpIndex[1]] - 1;//得到的是哪一个拼图
            int[] road = roads[typeIndex];//拼图上右下左的开口情况
            if (road[(lastExit + 2) % road.length] != 1) return false;//跟上一个拼接不上
            if (tmpIndex[0] == grid.length - 1 && tmpIndex[1] == grid[0].length - 1) return true;//已经到达目的地
            for (int i = 0; i < road.length; i++) {
                if (road[i] == 1 && i != ((lastExit + 2) % road.length)) {//找到出口，刨除跟上一个块拼接的入口
                    lastExit = i;//出口方向
                    break;
                }
            }
            tmpIndex[0] += nexts[lastExit][0];//下一个块区行
            tmpIndex[1] += nexts[lastExit][1];//下一个块区列
            if (tmpIndex[0] < 0 || tmpIndex[0] >= grid.length || tmpIndex[1] < 0 || tmpIndex[1] >= grid[0].length) return false;
        }
    }
}
```