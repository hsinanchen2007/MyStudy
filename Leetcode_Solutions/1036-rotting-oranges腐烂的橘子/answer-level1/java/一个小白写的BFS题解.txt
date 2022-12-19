### 解题思路
0. 准备：
        1. boolean[][] isRotted -记录是否已经腐烂
        2. Queue<int[]> queue -BFS遍历时的队列
        3. int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}} -方向数组
1. 初始化：
        1. 找出在0分钟已经腐烂的橘子坐标,入队列
        2. 是否已经全部腐烂，如果是，返回0
2. 开始bfs：我们知道，对于任意无向图的通用的bfs算法如下(伪代码)：
```
    void bfs(){
        while (!queue.isEmpty()){
                Node node= queue.poll();
                for (Node neighbour : node.neighbours) {
                    if (isVisited(neighbour)){
                        queue.add(neighbour);
                        setVisited(neighbour);
                    }
                }
            }
        }
    }
```
那么这里有什么不同呢：
    1. 此处不是邻接矩阵，而是二维数组，通过坐标的形式访问，并且要盘是否越界
       这个简单，简单代码实现：
        
```java
int[] coordinate= queue.poll();
                for (int[] direction : directions) {
                    int currX=coordinate[0]+direction[0];
                    int currY=coordinate[1]+direction[1];
                    if (currX>=0&&currX<grid.length&&currY>=0&&currY<grid[0].length){
                        queue.add(new int[]{currX,currY});
                        isRotted[currX][currY]=true;
                    }
                }
```
        同时要加上条件：grid[currX][currY]==1&&!isRotted[currX][currY]
    2. 每分钟不只有一个橘子在腐烂，所以我们要标记上一分钟腐烂的个数为numPerMinute，并统计这一分钟的，这里的技巧类似于102-levelOrder题,
      随后我们就让numPerMinute个坐标出队列
3. 返回bfs
    1. 要统计是否能全部腐烂
    2. 返回的是result-1，因为最有一轮腐烂的橘子空循环了一轮
### 代码

```java
class Solution {
    private int[][] grid;
    private int[][] directions = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private Queue<int[]> queue;
    private boolean[][] isRotted;
    private int result = 0;
    private int numPerMinute=0;

    public int orangesRotting(int[][] grid) {
        this.grid = grid;
        queue =new LinkedList<>();
        isRotted = new boolean[grid.length][grid[0].length];
        if (init()) {
            return 0;
        } else {
            bfs();
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid[0].length; j++) {
                    if (grid[i][j]==1&& !isRotted[i][j]){
                        return -1;
                    }
                }
            }
            return result-1;
        }
    }

    public void bfs(){
        while (!queue.isEmpty()){
            int temp=0;
            for (int i=0;i<numPerMinute;i++) {
                int[] coordinate= queue.poll();
                for (int[] direction : directions) {
                    int currX=coordinate[0]+direction[0];
                    int currY=coordinate[1]+direction[1];
                    if (currX>=0&&currX<grid.length&&currY>=0&&currY<grid[0].length&&grid[currX][currY]==1&&!isRotted[currX][currY]){
                        queue.add(new int[]{currX,currY});
                        temp++;
                        isRotted[currX][currY]=true;
                    }
                }
            }
            result++;
            numPerMinute=temp;
        }
    }

    public boolean init() {
        boolean result=true;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j]==1){
                    result=false;
                    isRotted[i][j]=false;
                }
                if (grid[i][j] ==2){
                    queue.add(new int[]{i,j});
                    isRotted[i][j]=true;
                    numPerMinute++;
                }
            }
        }
        return result;
    }
}
```