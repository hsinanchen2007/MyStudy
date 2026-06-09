[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/LCP/_3_robot.java)

```java
    /**
     * 解题思路：
     * 简单直接能出结果，但是提交超时，主要耗时在障碍物的循环判断上，当障碍物太多了就比较耗时了
     * 比如这个case：https://leetcode-cn.com/submissions/detail/32424313/testcase/
     * <p>
     * 优化求解：{@link _3_robot#robot2(String, int[][], int, int)}
     *
     * @param command
     * @param obstacles
     * @param x
     * @param y
     * @return
     */
    public boolean robot(String command, int[][] obstacles, int x, int y) {
        int index = 0;
        int length = command.length();
        int SX = 0, SY = 0;
        while (true) {
            char c = command.charAt(index % length);
            if (c == 'U') {
                SY++;
            } else if (c == 'R') {
                SX++;
            } else {
                break;
            }
            if (SX == x && SY == y) {
                return true;
            }
            //不考虑内存的话，可以考虑用map保存障碍物位置，本题提交不过x,y太大
            if (isInObstacles(SX, SY, obstacles) || SX > x || SY > y) {
                break;
            }
            index++;
        }

        return false;
    }

    private boolean isInObstacles(int x, int y, int[][] obstacles) {
        if (obstacles.length == 0) return false;
        for (int i = 0; i < obstacles.length; i++) {
            if (x == obstacles[i][0] && y == obstacles[i][1]) {
                return true;
            }
        }
        return false;
    }

    /**
     * 解题思路：
     * 1、鉴于指令是不断走循环的，先算出一个循环内横向走的坐标xx和纵向走的坐标yy，后续的可以通过规则落到第一圈的坐标上
     * 2、利用map将一个循环走的坐标保存下来==>xx+"_"+yy,true
     * 3、计算走到目标坐标需要的循环次数，映射到第一圈中是否包含该坐标
     * 4、同理，循环障碍物，看映射到第一圈中是否包含该坐标
     *
     * 映射规则：x ==> x - circle * xx
     * <p>
     * 执行用时 : 3 ms, 在所有 Java 提交中击败了69.76%的用户
     * 内存消耗 :36 MB, 在所有 Java 提交中击败了100.00%的用户
     *
     * @param command
     * @param obstacles
     * @param x
     * @param y
     * @return
     */
    public boolean robot2(String command, int[][] obstacles, int x, int y) {
        int xx = 0, yy = 0;
        Map<String, Boolean> set = new HashMap<>();
        set.put(xx + "_" + yy, true);
        //1
        for (char c : command.toCharArray()) {
            switch (c) {
                case 'U':
                    yy++;
                    break;
                case 'R':
                    xx++;
                    break;
            }
            //2
            set.put(xx + "_" + yy, true);
        }
        //3
        int circle = Math.min(x / xx, y / yy);
        if (!set.getOrDefault((x - circle * xx) + "_" + (y - circle * yy), false)) return false;

        //4
        for (int[] item : obstacles) {
            if (item.length < 2) continue;
            if (item[0] > x || item[1] > y) continue;
            circle = Math.min(item[0] / xx, item[1] / yy);
            if (set.getOrDefault((item[0] - circle * xx) + "_" + (item[1] - circle * yy), false)) return false;
        }

        return true;
    }
```