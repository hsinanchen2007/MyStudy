[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_52_totalNQueens.java)
```java
    //运算结果
    private int resultCount = 0;

    /**
     * 解题思路（回溯算法）：
     * 1.创建一个大小为n的数组，保存摆放皇后的位置
     * 2.从第一位开始尝试，一直取到N，每一次摆放皇后都得判断是否满足条件
     * 3.如摆放过程中发现没有满足条件的位置，则回溯上一位并寻找下一个可放置的位置
     * 4.如n个皇后都正确摆放，则结果+1，回溯上一位寻找下一个可放置的位置
     *
     * @param n
     * @return
     */
    public int totalNQueens(int n) {
        int[] positions = new int[n];
        dfs(positions, 0, n);
        return resultCount;
    }

    private void dfs(int[] positions, int index, int n) {
        if (index >= n) return;
        for (int i = 0; i < n; i++) {
            positions[index] = i;
            if (isMatch(positions, index)) {
                if (index == n - 1) {
                    resultCount++;
                } else {
                    dfs(positions, index + 1, n);
                }
            }
        }
    }

    /**
     * 是否满足N皇后的规则，横、竖、斜边不能放
     *
     * @param positions
     * @param index
     * @return
     */
    private boolean isMatch(int[] positions, int index) {
        for (int i = 0; i < index; i++) {
            //判断横向和斜向是否在一条线上即可，因为竖向用一位数组存储就避免了
            if (positions[i] == positions[index] || Math.abs(positions[i] - positions[index]) == index - i) {
                return false;
            }
        }
        return true;
    }
```