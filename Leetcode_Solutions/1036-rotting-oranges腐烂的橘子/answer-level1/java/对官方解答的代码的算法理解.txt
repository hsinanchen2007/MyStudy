### 解题思路
菜鸟使用官方的解答，只是重新过一遍算法。对算法进行了注释。
日后要努力，要加油。

### 代码

```java
class Solution {
    //用于配合向四个方向感染
    //如 dr[0] 与 dc[0] 组合表示的是该元素的上方元素
    //如 dr[1] 与 dc[1] 组合表示的是该元素的左方元素
    int[] dr = new int[] {-1,0,1,0};
    int[] dc = new int[] {0,-1,0,1};

    public int orangesRotting(int[][] grid) {
        //获取二维数组的行数row,列数column
        int Row = grid.length;
        int Column = grid[0].length;

        //申请队列存放被感染的橘子
        Queue<Integer> queue = new ArrayDeque();
        //申请一个hashmap进行 key存放橘子的一维坐标，value存放腐烂的时间
        Map<Integer,Integer> depth = new HashMap();

        //将橘子坐标转换为一维数组坐标，并初始化depth
        for(int r = 0; r < Row; ++r) {
            for(int c = 0; c < Column; ++c) {
                if(grid[r][c] == 2) {
                    int code = r*Column + c; //code为橘子的一维数组坐标
                    queue.add(code);//存储腐烂橘子
                    depth.put(code,0);//存储橘子的坐标与变腐烂的总时间
                }
            }
        }

        int total = 0; //total代表最后的时间
        while(!queue.isEmpty()) {
            int code = queue.remove();  //取出队列里的橘子
            int r = code/Column, c = code%Column;//获取橘子的二维坐标
            for(int k = 0; k < 4; ++k) {
                //找到即将被感染的位置
                int nr = r + dr[k];
                int nc = c + dc[k];
                //判断该位置是否越界，是否已经被感染
                if(nr >= 0 && nr < Row && nc >= 0 && nc < Column && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; //感染该橘子
                    int ncode = nr*Column + nc; //类比初始化队列
                    queue.add(ncode);
                    depth.put(ncode,depth.get(code) + 1);
                    total = depth.get(ncode); //记录最新的最长感染时间
                }
            }
        }

        //检查grid,能被感染的橘子都被感染
        for(int[] test : grid) {
            for(int v: test) {
                if(v == 1) {
                    return -1; //存在未被感染的橘子，返回-1
                }
            }
        }

        return total; //返回最长的感染时间
    }
}
```