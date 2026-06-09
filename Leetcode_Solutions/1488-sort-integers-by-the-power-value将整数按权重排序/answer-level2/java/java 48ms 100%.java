竞赛代码。。用了数组实现。

主要的思路是计算权值，用递归实现，保存下来。

 private int dfs(int[] a, int index) {
        if (a[index] != 0) {
            return a[index];
        }
        int r = 0;
        if (index % 2 == 0) {
            r = dfs(a, index / 2) + 1;
        } else {
            r = dfs(a, index * 3 + 1) + 1;
        }
        a[index] = r;
        return r;
    }

