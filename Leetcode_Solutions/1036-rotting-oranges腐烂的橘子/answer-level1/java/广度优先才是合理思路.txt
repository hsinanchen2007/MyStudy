### 解题思路
首先开始的时候 大家都会看图的描述，一步，一步被带入 dfs 的思路上来，但是实际情况一个区域里面明显会出现不止一个烂番茄，那么我们用 dfs 显然是不合理的，
因为如果有两个番茄从两端开始腐烂 明显速度是快于从一端开始腐烂的，所以我们要采用 bfs 来遍历，bfs 主要思路就是使用 队列/queue 来实现，在遍历过程中我们要记录对象的坐标 x，y，以及到达当前对象的时间 time，简单操作之后便可以写代码了。

### 代码

```java
class Solution {
     // 解题思路 1 bfs 2 标记 3 遍历 查看是否还有未变质的橘子
    int minTime = 0;

    class DataBean{
        int x;
        int y;
        int time;

        public DataBean(int x, int y, int time) {
            this.x = x;
            this.y = y;
            this.time = time;
        }
    }
    // 广度优先 第一步 寻找烂橘子 第二部 开始搞事 第三部 重复 第四部 遍历结果
    public int orangesRotting(int[][] grid) {
        Queue<DataBean> queue = new LinkedList();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 2 ) {
                    queue.add(new DataBean(i,j,0));
                }
            }
        }

        while (!queue.isEmpty()){
            gonext(grid,queue.poll(),queue);
        }
         for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minTime;
    }

    public void gonext(int[][] grid, DataBean bean,Queue<DataBean> queue) {

        int i = bean.x;
        int j = bean.y;
        int val = bean.time;
        minTime = val;
        // 上下左右操作一下
        if (i + 1 < grid.length && grid[i + 1][j] == 1) {
            grid[i+1][j] = 2;
            DataBean nextBean = new DataBean(i+1,j,val+1);
            queue.add(nextBean);
        }

        if (j + 1 < grid[i].length && grid[i][j + 1] == 1) {
            grid[i][j+1] = 2;
            DataBean nextBean = new DataBean(i,j+1,val+1);
            queue.add(nextBean);
        }

        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            grid[i-1][j] = 2;
            DataBean nextBean = new DataBean(i-1,j,val+1);
            queue.add(nextBean);
        }

        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            grid[i][j-1] = 2;
            DataBean nextBean = new DataBean(i,j-1,val+1);
            queue.add(nextBean);
        }

    }
}
```