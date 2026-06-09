### 解题思路
思路就是BFS，和之前🍊那道差不多

一共3个步骤：
1. 遍历整个`grid`，找到陆地（腐烂的juzi），把它们放进队列里
    - 如果队列为空或队列大小与格子数相等，返回`-1`

2. 对队列里的陆地（juzi）做如下操作

    - 把陆地（juzi）从队列里拿出来
    - 看陆地（juzi）的上下左右相邻的格子里有没有海洋（未腐烂的juzi），如果有，把它变成更高的陆地（感染它），并把它放进队列里
    - 海拔`d`（腐烂时间）`+1`

    如此循环，直到队列里没有陆地（juzi）为止
    这里有两个小技巧
    - 用`横坐标 + 纵坐标 * grid列数`构造唯一编号来表示陆地（juzi），再放入队列，取出的时候也可以通过除法`/`和取余`%`来还原陆地（juzi）坐标
    - 用`dx`和`dy`两个数组来表示相邻格子的位移，用`for`循环两数组可以简化冗长的代码，这里上下左右的顺序是任意的
3. 返回`d - 2`（`d`是下一步填海陆地的高度，但此时已经没有海洋可填，因此实际地图上最后一块海洋的高度是`d - 1`，它距离初始的陆地`1`的距离就是海拔差`（d - 1） - 1`）

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        int N = grid.length;
        Queue<Integer> queue = new LinkedList<>();

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 1) {
                    queue.add(i*N + j);
                }
            }
        }

        if(queue.isEmpty() || queue.size() == N * N) {
            return -1;
        }

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        int d = 1;
        while(!queue.isEmpty()) {
            int size = queue.size();
            d += 1;
            for(int i=0; i<size; i++) {
                int land = queue.remove();
                int x = land / N;
                int y = land % N;
                for(int k=0; k<4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if(xx>=0 && xx<N && yy>=0 && yy<N && grid[xx][yy] == 0) {
                        grid[xx][yy] = d;
                        queue.add(xx*N + yy);
                    }
                }
            }
        }
        return d - 2;
    }
}
```