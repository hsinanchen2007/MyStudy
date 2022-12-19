#### 思路
储存4个方向，首先会尝试当前方向是否满足，如果不满足，则寻找下一个方向，简单易懂。



```
class Solution {
    static int[][] res;
    static int[][] book;

    public int[][] generateMatrix(int n) {
        if (n <= 0) return null;
        res = new int[n][n];
        book = new int[n][n];
        //必须遵循顺时针的方向
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};

        book[0][0] = 1;
        res[0][0] = 1;
        generateMatrix(n, dx, dy, 0, 0, 0);
        return res;

    }

    private void generateMatrix(int n, int[] dx, int[] dy, int i, int j, int state) {

        int count = 4;
        while (count != 0) {
            int newI = i + dx[state];
            int newJ = j + dy[state];
            if (newI >= 0 && newI <= n - 1 && newJ >= 0 && newJ <= n - 1 && book[newI][newJ] == 0) {
                res[newI][newJ] = res[i][j] + 1;
                book[newI][newJ] = 1;
                generateMatrix(n, dx, dy, newI, newJ, state);
                break;
            } else {
                state = (state + 1) % 4;
                count--;
            }
        }


    }
}
```
