从位置(0,0)开始，上下左右扩张机器人的有效移动范围。
```
    private boolean[][] lowerThanK;//可到达的位置为true
    private int ans;

    public int movingCount(int m, int n, int k) {
        lowerThanK = new boolean[m][n];
        ans = 0;
        tryExpand(0, 0, m, n, k);//从起始位置开始拓展活动区域
        return ans;
    }

    /**
    * @param i 当前位置行数
    * @param j 当前位置列数
    * @param m 总行数
    * @param n 总列数
    * @param k 边界条件
    */
    private void tryExpand(int i, int j, int m, int n, int k) {
        if (sum(i, j, k) && !lowerThanK[i][j]) {
            lowerThanK[i][j] = true;
            ans++;
            //上
            if (i - 1 >= 0) tryExpand(i - 1, j, m, n, k);
            //下
            if (i + 1 < m) tryExpand(i + 1, j, m, n, k);
            //左
            if (j - 1 >= 0) tryExpand(i, j - 1, m, n, k);
            //右
            if (j + 1 < n) tryExpand(i, j + 1, m, n, k);
        }
    }

    /**
    * @return 数位之和是否不超过k
    */
    private boolean sum(int i, int j, int k) {
        int ans = 0;
        while (i != 0 || j != 0) {
            ans += i % 10 + j % 10;
            i = i / 10;
            j = j / 10;
        }
        return ans <= k;
    }
```
