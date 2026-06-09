### 解题思路
这道题我采用bfs，从r0,c0开始，向外扩散；
思路我是根据做[烂橘子](https://leetcode-cn.com/problems/rotting-oranges/)思路来做的。
bfs思路很简单，但代码有时候会显得特别麻烦。
可以通过code来存储每个点的位置，比用数组存储会好很多。
还有dr，dc的设置都可以让代码显得简洁。省去了if-if-if-if的麻烦。
时间复杂度O(R\*C)，空间复杂度O(R\*C);

### code
code的原理是映射，每个坐标对应唯一的code。我这里是通过r\*C+c来作为code。相应的也可以用r+c\*R来实现。

### 代码

```java
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[] dr = new int[]{1, 0, -1, 0};
        int[] dc = new int[]{0, 1, 0, -1};
        boolean[][] used = new boolean[R][C]; //存储访问过的坐标。
        Queue<Integer> que = new ArrayDeque<Integer>();
        int[][] res = new int[R * C][2];
        que.add(r0 * C + c0);
        used[r0][c0] = true;
        int index = 0;
        while(!que.isEmpty()) {
            int code = que.remove();
            int r = code / C, c = code % C;
            res[index] = new int[]{r, c};
            ++index;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && used[nr][nc] == false) {
                    used[nr][nc] = true;
                    que.add(nr * C + nc);
                }
            }
        }
        return res;
    }
}
```