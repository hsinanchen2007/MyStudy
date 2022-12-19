### 解题思路
没说明好说的，整体就是官方解法的复读版，详细的思路都写在注释上了

### 代码

```java
class Solution {
    // dr,dc 配合使用得到 grid[r][c] 上grid[r-1][c]左grid[r][c-1]下grid[r+1][c]右grid[r][c+1]的元素
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};
    public int orangesRotting(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        /*初始化空队列和map*/
        Queue<Integer> queue = new ArrayDeque();
        Map<Integer, Integer> depth = new HashMap();
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                if (grid[r][c] == 2) {
                    /*code相当于从左到右数出这个元素的位置是第几位*/
                    int code = r * C + c;
                    queue.add(code);
                    /*记录下起源传播点的坐标，并设定起始传播数为0*/
                    depth.put(code, 0);
                }

        int ans = 0;
        while (!queue.isEmpty()) {
            /*出队,将传播源结点坐标换成出队结点的坐标*/
            int code = queue.remove();
            /*解析拿到的下标信息*/
            int r = code / C, c = code % C;
            /*这里的k=4其实就是4个方位dr,dc意思是derictory row ,derictory colunm*/
            /*nr和nc就是near row 和near colum的意思,每循环一次获得一个腐烂橘子的附近坐标*/
            /*这里附近点的循环顺序是上，左，下，右*/
            for (int k = 0; k < 4; ++k) {
                /*这里用了一个骚操作将附近点用for循环表示出来了*/
                int nr = r + dr[k];
                int nc = c + dc[k];
                /*判别附近点是否越界，且值是否为1*/
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                    /*当值为1时，腐化这个点*/
                    grid[nr][nc] = 2;
                    /*保留被腐化附近结点的下标信息*/
                    int ncode = nr * C + nc;
                    /*将此已腐化结点的下标入队*/
                    queue.add(ncode);
                    /*这个map记录了每个被腐化点的传播次数，使用的方法也不高明，就是通过传播源坐标拿到上次的传播次数，再+1*/
                    depth.put(ncode, depth.get(code) + 1);
                    /*ans记录了最后一个点被腐化时的传播次数*/
                    ans = depth.get(ncode);
                }
            }
        }
        /*当广度遍历结束时，检查gird中是否还有1，如果有，返回1*/
        for (int[] row: grid)
            for (int v: row)
                if (v == 1)
                    return -1;
        return ans;
    }
}
```