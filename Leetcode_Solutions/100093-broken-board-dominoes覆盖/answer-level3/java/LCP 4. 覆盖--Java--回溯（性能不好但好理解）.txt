[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/LCP/_4_domino.java)

```java
    int ret = 0; //摆放计数
    int max = 0; //最大值计数

    /**
     * 解题思路：
     * 1、构建棋盘，将棋盘上正常的为0，坏了的位置为2，摆放了骨牌的为1
     * 2、对于一个位置和骨牌有三种组合：横着放、竖着放、不放，如需计算正确的值需要所有的情况都计算到，所以回溯实现
     * <p>
     * 执行耗时不是很好，但是自己写出来的好理解
     * 执行用时 :1297 ms, 在所有 java 提交中击败了12.90%的用户
     * 内存消耗 :35.6 MB, 在所有 java 提交中击败了100.00%的用户
     *
     * @param n
     * @param m
     * @param broken
     * @return
     */
    public int domino(int n, int m, int[][] broken) {
        ret = 0;
        max = 0;
        //构造棋盘
        int[][] map = new int[n][m];
        for (int i = 0; i < broken.length; i++) {
            int[] item = broken[i];
            map[item[0]][item[1]] = 2;
        }
        dfs(map, 0, 0);

        return max;
    }

    /**
     * 循环的过程是横向一行行逐格摆放，如到一行的末尾无法摆放则换行，如超过行数则计算摆放的最大个数
     *
     * @param map
     * @param row
     * @param col
     */
    private void dfs(int[][] map, int row, int col) {
        if (row >= map.length) { //如超过行数则计算摆放的最大个数
            max = Math.max(max, ret);
            return;
        }
        if (col >= map[row].length) {//如到一行的末尾无法摆放则换行
            dfs(map, row + 1, 0);
            return;
        }
        if (map[row][col] > 0) {//遇坏格子则跳过
            dfs(map, row, col + 1);
            return;
        }
        //试着横着放
        boolean h = false;
        if (col < map[row].length - 1 && map[row][col + 1] == 0) {
            h = true;
            map[row][col]++;
            map[row][col + 1]++;
            ret++;
            dfs(map, row, col + 2);
            //横向状态重置
            ret--;
            map[row][col]--;
            map[row][col + 1]--;
        }
        //试着竖着放
        boolean v = false;
        if (row < map.length - 1 && map[row + 1][col] == 0) {
            v = true;
            map[row][col]++;
            map[row + 1][col]++;
            ret++;
            dfs(map, row, col + 1);
            //竖向状态重置
            ret--;
            map[row][col]--;
            map[row + 1][col]--;
        }
        //如横着和竖着都不行，试着不放，跳2格
        if (!h && !v) {
            dfs(map, row, col + 2);
        }
    }
```