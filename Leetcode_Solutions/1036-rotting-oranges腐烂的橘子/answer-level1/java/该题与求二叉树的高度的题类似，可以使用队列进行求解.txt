### 解题思路
统计好的橘子的个数`goodOrangeCount`，并创建一个队列`badOrangeQueue`存放坏的橘子的位置信息
而后再每次时间结束后往其中添加一个边界点`new postion(-1, -1)`，便于计算时间，

在第一次统计结束后，判断是否存在好橘子，若不存在则返回0，结束；
若存在，则判断队列`badOrangeQueue.isEmpty() == true`是否为空，若为空，则好橘子无法被传染变质，返回-1，结束；
而后通过while循环开始统计每个时间对其上下左右的好橘子（`(i-1, j),(i+1,j),(i,j-1),(i,j+1)`）进行传染，并将变为2，便是已经腐败防止再次统计。
因为结尾只剩下边界点时，需要判断结束，否则会出现死循环；
最后因为最后坏橘子出队列后才能结束，因而多统计一次，需`time-1`。

在写代码过程中突然想起来可以通过单独count统计每次的坏橘子个数从而减少边界点的添加，减少内存占用。（见方法二，本以为内存会少，但测试发现占用内存低，而且击败对手只有71.83%）

### 代码
1. 方法一
```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int goodOrangeCount = 0;
        int time = 0;
        Deque<postion> badOrangeQueue = new ArrayDeque<postion>();
        int n = grid.length;
        int m = grid[0].length;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(grid[i][j] == 1) goodOrangeCount ++;
                else if(grid[i][j] == 2) {
                    badOrangeQueue.offer(new postion(i, j));
                }
            }
        }
        if(goodOrangeCount == 0) return 0;
        if(badOrangeQueue.size() == 0) return -1;
        badOrangeQueue.offer(new postion(-1, -1));
        while(!badOrangeQueue.isEmpty()){
            postion cur = badOrangeQueue.poll();
            int x = cur.x;
            int y = cur.y;
            if(x == -1 && y == -1){
                time ++;
                if(badOrangeQueue.isEmpty()) break;
                badOrangeQueue.offer(new postion(-1, -1));
                continue;
            }
            if(x > 0 && grid[x - 1][y] == 1){
                grid[x - 1][y] = 2;
                badOrangeQueue.offer(new postion(x - 1, y));
                goodOrangeCount --;
            }
            if(x < n - 1 && grid[x + 1][y] == 1){
                grid[x + 1][y] = 2;
                badOrangeQueue.offer(new postion(x + 1, y));
                goodOrangeCount --;
            }
            if(y > 0 && grid[x][y - 1] == 1){
                grid[x][y - 1] = 2;
                badOrangeQueue.offer(new postion(x, y - 1));
                goodOrangeCount --;
            }
            if(y < m - 1 && grid[x][y + 1] == 1){
                grid[x][y + 1] = 2;
                badOrangeQueue.offer(new postion(x, y + 1));
                goodOrangeCount --;
            }
        }
        return goodOrangeCount == 0 ? time - 1 : -1;
    }

    public class postion{
        int x;
        int y;
        public postion(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
```

2. 方法二
```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0].length == 0) return 0;
        int goodOrangeCount = 0;
        int time = 0;
        Deque<postion> badOrangeQueue = new ArrayDeque<postion>();
        int n = grid.length;
        int m = grid[0].length;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(grid[i][j] == 1) goodOrangeCount ++;
                else if(grid[i][j] == 2) {
                    badOrangeQueue.offer(new postion(i, j));
                }
            }
        }
        if(goodOrangeCount == 0) return 0;
        int badOrangeCount = badOrangeQueue.size();
        if(badOrangeCount == 0) return -1;
        while(!badOrangeQueue.isEmpty()){
            postion cur = badOrangeQueue.poll();
            int x = cur.x;
            int y = cur.y;
            if(x > 0 && grid[x - 1][y] == 1){
                grid[x - 1][y] = 2;
                badOrangeQueue.offer(new postion(x - 1, y));
                goodOrangeCount --;
            }
            if(x < n - 1 && grid[x + 1][y] == 1){
                grid[x + 1][y] = 2;
                badOrangeQueue.offer(new postion(x + 1, y));
                goodOrangeCount --;
            }
            if(y > 0 && grid[x][y - 1] == 1){
                grid[x][y - 1] = 2;
                badOrangeQueue.offer(new postion(x, y - 1));
                goodOrangeCount --;
            }
            if(y < m - 1 && grid[x][y + 1] == 1){
                grid[x][y + 1] = 2;
                badOrangeQueue.offer(new postion(x, y + 1));
                goodOrangeCount --;
            }
            badOrangeCount --;
            if(badOrangeCount == 0){
                time ++;
                badOrangeCount = badOrangeQueue.size();
            }
        }
        return goodOrangeCount == 0 ? time - 1 : -1;
    }

    public class postion{
        int x;
        int y;
        public postion(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
```
