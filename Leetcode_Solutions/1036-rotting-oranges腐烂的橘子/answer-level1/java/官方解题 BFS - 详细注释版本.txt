### 解题思路
首先，此代码是官方解题代码且没有任何删改
我对官方解题代码 做了一遍详细注释 
一是为了加深自己理解，二是帮助那些不太明白的力友理解
(p.s 这题属于比较简单的题，相信不注释也会看的懂)

### 代码

```java
class Solution {
    
    //row 行 向左向右
    int[] dr = new int[]{-1, 0, 1, 0};
    
    //col 列 向上向下
    int[] dc = new int[]{0, -1, 0, 1};

    public int orangesRotting(int[][] grid) {
        //广度优先遍历 BFS 队列
        
        //行数
        int R = grid.length;
        
        //列数
        int C = grid[0].length;

        //BFS使用的队列
        Queue<Integer> queue = new ArrayDeque();

        //Hash映射 key为腐烂的橘子的位置(总索引号) value 代表第几分钟腐烂的
        Map<Integer, Integer> depth = new HashMap();
        
        //按行按列开始遍历
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                //如果当前遍历到的节点是腐烂的橘子 2
                if (grid[r][c] == 2) {
                    //遍历到二维数组的第几个值
                    int code = r * C + c;
                    //把这个值入队列
                    queue.add(code);
                    //对此路径做标记
                    depth.put(code, 0);
                }

        //最后的分钟数
        int ans = 0;
        //如果二维列表中有腐烂的橘子
        while (!queue.isEmpty()) {
            //第一个腐烂的橘子出队列
            int code = queue.remove();
            //找到腐烂的橘子对应的行号和列号
            int r = code / C, c = code % C;
            
            //四个方向上 即将腐烂的橘子
            for (int k = 0; k < 4; ++k) {
                //获取行号
                int nr = r + dr[k];
                //获取列号
                int nc = c + dc[k];
                if (0 <= nr && nr < R //行大于等于0 且行小于R
                      && 0 <= nc  && nc < C //列大于等于0 且行小于C
                      && grid[nr][nc] == 1) {//即将腐烂的橘子是新鲜橘子
                    //腐烂此橘子
                    grid[nr][nc] = 2;
                    //记录这个橘子的位置
                    int ncode = nr * C + nc;
                    //入队列
                    queue.add(ncode);
                    //对这个位置的橘子做映射 值+1 
                    depth.put(ncode, depth.get(code) + 1);
                    //返回最新的分钟数
                    ans = depth.get(ncode);
                }
            }
        }

        //二次遍历数组 寻找是否有新鲜橘子 有返回-1
        for (int[] row: grid)
            for (int v: row)
                if (v == 1)
                    return -1;

        //没有腐烂的橘子，返回最大的分钟数 (因为有一个腐烂 四个方向全方位腐烂 因此这也是最小的分钟数)            
        return ans;
    }
}
```