### 解题思路
此处撰写解题思路
1：Java 递归方法，每个方格只有两个对外接口，一进一出
2：运行结果
执行用时 :30 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :65.9 MB, 在所有 Java 提交中击败了100.00%的用户
### 代码

```java
class Solution {
    private static final String left = "left";

    private static final String right = "right";

    private static final String top = "top";

    private static final String botom = "botom";

    public static boolean hasValidPath(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return false;
        }
        int n = grid[0].length;
        int m = grid.length;
        if (m == 1 & n == 1) {
            return true;
        }
        String need_dir = left;

        return funcation(0, 0, need_dir, m, n, grid);
    }

    /**
     *
     * */
    private static boolean funcation(int i, int j, String need_dir, int m, int n, int[][] grid) {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1) {
            return false;
        }

        Road road = Road.getRoad(grid[i][j]);

        if (i == 0 && j == 0) {
            boolean result = false;

            if (road.left) {
                result =(result|| funcation(i, j - 1, Solution.right, m, n, grid));
            }
            if (road.right) {
                result = (result|| funcation(i, j + 1, Solution.left, m, n, grid));
            }

            if (road.top) {
                result = (result|| funcation(i - 1, j, Solution.botom, m, n, grid));
            }
            if (road.botom) {
                result = (result|| funcation(i + 1, j, Solution.top, m, n, grid));
            }
            return result;
        }

        if (road.isContain(need_dir)) {

            if ((i == m - 1) && (j == n - 1)) {
                return true;
            } else {
                String remian_dir = road.getRemain(need_dir);

                if (remian_dir == "") {
                    return false;
                }

                if (remian_dir.equalsIgnoreCase(Solution.left)) {
                    return funcation(i, j - 1, Solution.right, m, n, grid);
                }
                if (remian_dir.equalsIgnoreCase(Solution.right)) {
                    return funcation(i, j + 1, Solution.left, m, n, grid);
                }

                if (remian_dir.equalsIgnoreCase(Solution.top)) {
                    return funcation(i - 1, j, Solution.botom, m, n, grid);
                }
                if (remian_dir.equalsIgnoreCase(Solution.botom)) {
                    return funcation(i + 1, j, Solution.top, m, n, grid);
                }
                return false;
            }
        }
        return false;
    }
// --------------------- Change Logs----------------------
// <p>@author Initial Created at 2020-03-22<p>
//  创建object，初始化
// -------------------------------------------------------
    private static class Road {
        private int value;

        private boolean left;

        private boolean right;

        private boolean top;

        private boolean botom;

        public Road(int value, boolean left, boolean right, boolean top, boolean botom) {
            this.value = value;
            this.left = left;
            this.right = right;
            this.top = top;
            this.botom = botom;
        }

        public static Road getRoad1() {
            return new Road(1, true, true, false, false);
        }

        public static Road getRoad2() {
            return new Road(2, false, false, true, true);
        }

        public static Road getRoad3() {
            return new Road(3, true, false, false, true);
        }

        public static Road getRoad4() {
            return new Road(4, false, true, false, true);
        }

        public static Road getRoad5() {
            return new Road(5, true, false, true, false);
        }

        public static Road getRoad6() {
            return new Road(6, false, true, true, false);
        }

        public boolean isContain(String name) {
            if (name == Solution.left) {
                return this.left;
            }
            if (name == Solution.right) {
                return this.right;
            }
            if (name == Solution.top) {
                return this.top;
            }
            if (name == Solution.botom) {
                return this.botom;
            }
            return false;
        }

        public String getRemain(String need_dir) {
            if (this.left && !Solution.left.equalsIgnoreCase(need_dir)) {
                return Solution.left;
            }
            if (this.right && !Solution.right.equalsIgnoreCase(need_dir)) {
                return Solution.right;
            }
            if (this.top && !Solution.top.equalsIgnoreCase(need_dir)) {
                return Solution.top;
            }
            if (this.botom && !Solution.botom.equalsIgnoreCase(need_dir)) {
                return Solution.botom;
            }
            return "";
        }

        public static Road getRoad(int input) {
            if (input == 1) {
                return getRoad1();
            }

            if (input == 2) {
                return getRoad2();
            }

            if (input == 3) {
                return getRoad3();
            }

            if (input == 4) {
                return getRoad4();
            }

            if (input == 5) {
                return getRoad5();
            }

            if (input == 6) {
                return getRoad6();
            }
            return null;
        }
    }
}
```