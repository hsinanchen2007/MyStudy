**方法一：找出所有开始是腐烂的桔子**
```
class Solution {
    /**
    * 思路：
    * 1、用HashMap记录腐烂橘子和被感染的时间，最开始就是腐烂橘子的感染时间为0。
    * 2、用队列存第一次被感染的橘子，然后依次取出去感染上下左右，分别记录时间存入HashMap。
    * 3、记录最后一个腐烂橘子被感染的时间ans，如果格子里还有没被感染的橘子返回-1，否则返回ans。
    */
	// dr,dc 配合使用得到 grid[r][c] 上左下右的元素
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};

    public int orangesRotting(int[][] grid) {
        // 获取二维数组的行数row 和 列数 column
        int R = grid.length, C = grid[0].length;

        // 所有开始被感染的腐烂橘子
        Queue<Integer> queue = new ArrayDeque<>();
        // 存储橘子变为腐烂时的时间,k为橘子的唯一标识，value为变腐烂的时间
        Map<Integer, Integer> depth = new HashMap<>();
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                if (grid[r][c] == 2) {
					// 根据位置算出唯一值区分每颗烂橘子,c < C
                    int code = r * C + c;
                    // 从头开始存腐烂橘子
                    queue.add(code);
                    depth.put(code, 0);
                }
        int ans = 0;
        while (!queue.isEmpty()) {
            int code = queue.remove();
            int r = code / C, c = code % C;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    int ncode = nr * C + nc;
                    queue.add(ncode);
                    depth.put(ncode, depth.get(code) + 1);
                    ans = depth.get(code) + 1;
                }
            }
        }
        // 所有腐烂橘子上下左右没有可以感染的新鲜橘子后，遍历格子中是否还有新鲜橘子没被感染
        for (int[] row: grid){
            for (int v: row){
                if (v == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
}
```
