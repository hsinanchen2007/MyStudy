### 解题思路
当我们以顺时针螺旋行走网格时，是有规律可循的。我们定义向左，向下，向右，向上行走为一个循环。
在第1个循环中，我们可以理解为从(r0,c0)向右走了1步，向下走了1步，向左走了2步，向上走了2步。
在第2个循环中，我们可以理解为从(r0,c0)向右走了3步，向下走了3步，向左走了4步，向上走了4步。
...
由此我们可以发现规律，每一次循环中，向右和向下走的步数相同，向左和向上走的步数相同比向右多走1步。
我们访问完网格中的每一个位置时，是走了n个这样的循环。
定义变量step为每次循环需要走的步数。在一次循环中，向右和向下走了step，向左和向上走了++step；每一次循环结束，step++;
什么时候能够访问完网格中的位置呢？我们定义一个计数器count，每次访问一个新位置(rr,cc)的时候,如果0<=rr<R && 0<=cc<C，这个位置就是合法的count++；
当count==R*C-1时，说明网格中的所有位置都被访问到了，循环至此结束。

### 代码

```java
class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        boolean[][] flag = new boolean[R][C];
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int[][] ans = new int[R * C][2];
        int count = 0, step = 0, rr = r0, cc = c0;
        while (count != R * C) {
            step++;
            for (int i = 0; i < 4; i++) {
                if (0 <= rr && rr < R && 0 <= cc && cc < C && !flag[rr][cc]) {
                    ans[count++] = new int[]{rr, cc};
                    flag[rr][cc] = true;
                }
                if(i!=3) step += i / 2;
                for (int s = step; s > 0; s--) {
                    rr+=dr[i];
                    cc+=dc[i];
                    if (0 <= rr && rr < R && 0 <= cc && cc < C && !flag[rr][cc]) {
                        ans[count++] = new int[]{rr, cc};
                        flag[rr][cc] = true;
                    }
                }
            }

        }
        return ans;
    }
    //下面这个只有10%
    public int[][] spiralMatrixIII2(int R, int C, int r0, int c0) {
        int[] dr = {0, 1, 0, -1};
        int[] dc = {1, 0, -1, 0};
        int[][] ans = new int[R * C][2];
        int count = 1, step = 0, rr = r0, cc = c0;
        ans[0] = new int[]{r0,c0};
        while (count != R * C) {
            step++;
            for (int i = 0; i < 4; i++) {
                if(i!=3) step += i / 2;
                for (int s = step; s > 0; s--) {
                    rr+=dr[i];
                    cc+=dc[i];
                    if (0 <= rr && rr < R && 0 <= cc && cc < C ) {
                        ans[count++] = new int[]{rr, cc};
                    }
                }
            }

        }
        return ans;
    }

}
```