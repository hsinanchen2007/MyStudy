### 解题思路
跟据大佬代码进行简化了，或者说脑回路简易。首先定义Pos类，用于记录定位和时间，更重要是方便放入队列里。
然后主体操作就是，首尾两个遍历整个数组，首部遍历定位腐烂的橘子，记录位置放入队列。
中间进行BFS广度优先搜索操作，队列推出一个值，进行上下左右四个放心感染腐烂橘子，被感染的放入队列，以此循环，直到无法再感染橘子为止，也就是队列里没有值后，结束循环。
尾部遍历查看有没有未腐烂的橘子，如果有返回-1。
最后返回时间。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        int R = grid.length;
        int C = grid[0].length;
        Queue<Pos> queue = new LinkedList<>();
        int min = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 2){
                    queue.add(new Pos(i,j,min));
                }
            }
        }
        int i,j;
        while (!queue.isEmpty()){
            Pos p = queue.poll();
            min = p.minute;
            i = p.x;
            j = p.y;
            if( i+1<R && grid[i+1][j] == 1 ){
                grid[i+1][j] = 2;
                queue.add(new Pos(i+1,j,min+1));
            }
            if( j+1<C && grid[i][j+1] == 1 ){
                grid[i][j+1] = 2;
                queue.add(new Pos(i,j+1,min+1));
            }
            if( i-1>=0 && grid[i-1][j] == 1 ){
                grid[i-1][j] = 2;
                queue.add(new Pos(i-1,j,min+1));
            }
            if( j-1>=0 && grid[i][j-1] == 1 ){
                grid[i][j-1] = 2;
                queue.add(new Pos(i,j-1,min+1));
            }
        }
        for (int i1 = 0; i1 < R; i1++) {
            for (int j1 = 0; j1 < C; j1++) {
                if (grid[i1][j1] == 1){
                    return  -1;
                }
            }
        }
        return min;
    }
}
class Pos{
    int x ;
    int y ;
    int minute;
    Pos(int x , int y ,int minute){
        this.x=x;
        this.y=y;
        this.minute=minute;
    }
}
```