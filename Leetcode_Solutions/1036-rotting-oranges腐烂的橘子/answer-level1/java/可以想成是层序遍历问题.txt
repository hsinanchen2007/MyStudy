### 思路
广度优先搜索

一共3个步骤：
1. 遍历整个grid，找到腐烂的🍊，把它们放进队列里
2. 对队列里的🍊做如下操作
    - 把🍊从队列里拿出来
    - 看🍊的上下左右相邻的格子里有没有未腐烂的🍊，如果有，感染它，并把它放进队列里
    - 腐烂时间+1

    如此循环，直到队列里没有🍊为止
    这里有两个小技巧
    1. 用【横坐标 + 纵坐标*grid列数】构造唯一编号来表示🍊，再放入队列，取出的时候也可以通过除法【/】和取余【%】来还原🍊坐标
    2. 用dx和dy两个数组来表示相邻格子的位移，用for循环两数组可以简化冗长的代码，这里上下左右的顺序是任意的
3. 再次遍历整个grid，此时如果还有未腐烂的🍊，则立刻返回-1，此外，再判断是否最开始就没有腐烂的🍊，如果是，返回时间0，不是，返回步骤2的结果

### 代码

```
    public int orangesRotting(int[][] grid) {
        Queue<Integer> queue = new LinkedList<>();
        int m = grid.length;
        int n = grid[0].length;
        Boolean hasRotten = false;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    queue.add(i*n+j);
                    hasRotten = true;
                }
            }
        }
        
        int step = -1;
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        while(!queue.isEmpty()) {
            int len = queue.size();
            for(int i=0; i<len; i++) {
                int orange = queue.remove();
                int x = orange / n;
                int y = orange % n;
                for(int j=0; j<4; j++) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1) {
                        grid[xx][yy] = 2;
                        queue.add(xx*n+yy);
                    }
                }
            }
            step++;
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return hasRotten ? step : 0;
    }
```

