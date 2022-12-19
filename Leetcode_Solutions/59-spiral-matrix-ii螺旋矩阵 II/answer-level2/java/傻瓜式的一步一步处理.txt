```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ret = new int[n][n];
        int x = 0;
        int y = 0;
        String direction = ">";
        int rightBorder = n;
        int bottomBorder = n;
        int leftBorder = 0;
        int topBorder = 1;
        for(int i = 1; i <= n*n; i++) {
            // 写入当前值
            ret[y][x] = i;
            // 计算接下来的方向
            if (x + 1 == rightBorder && direction.equals(">")) {   // 到达了右边界，转头向下，边界也在不断变化，每次到达之后都需要修改
                rightBorder--;
                y++;
                direction = "v";
            } else if (y + 1 == bottomBorder && direction.equals("v")) {    // 到达了下边界
                bottomBorder--;
                x--;
                direction = "<";
            } else if (x == leftBorder && direction.equals("<")) {
                leftBorder++;
                y--;
                direction = "^";
            } else if (y == topBorder && direction.equals("^")) {
                topBorder++;
                x++;
                direction = ">";
            } else {    // 没有到达任何边界，继续
                // 计算接下来的坐标值
                switch (direction) {
                    case ">":
                        x++;
                        break;
                    case "v":
                        y++;
                        break;
                    case "<":
                        x--;
                        break;
                    case "^":
                        y--;
                        break;
                    default:
                        break;
                }
            }

        }
        return ret;
    }
}
```
