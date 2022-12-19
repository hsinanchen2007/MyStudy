
参考大佬们的思路，终于自己搞出来了。。。
BFS,访问到一个没访问过的结点时将可以到达的点都处理
![image.png](https://pic.leetcode-cn.com/6891a4c141da5b1273a1739c91f5c533d84c2c8586bcb59ca779ee8334fa8c53-image.png)

    int[] dx = new int[]{0,1,-1,0,0};
    int[] dy = new int[]{0,0,0,1,-1};
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];//访问数组
        Queue queue = new ArrayDeque();//顺序队列
        int cost = 0;int count = 0;
        addNoCost(queue,new int[2],grid,visited);
        while (!visited[m - 1][n - 1]) {
            count = queue.size();
            for (int i = 0; i < count; i++) {
                addSome(queue,(int[])(queue.poll()),grid,visited);
            }
            cost++;
        }
        return cost;
    
    //将传入坐标可以无损耗到达的结点处理
    private void addNoCost(Queue queue,int[] location,int[][] grid,boolean[][] visited){
        while (location[0] >= 0 && location[0] < grid[0].length && location[1] >= 0 &&
                location[1] < grid.length) {
            if (visited[location[1]][location[0]]) break;
            queue.add(new int[]{location[0],location[1]});
            visited[location[1]][location[0]] = true;
            int x = location[0],y = location[1];
            location[0] += dx[grid[y][x]];
            location[1] += dy[grid[y][x]];
        }
        return;
    }

    //处理修改方向可以到达的点
    private void addSome(Queue queue,int[] location,int[][] grid,boolean[][] visited) {
        for (int i = 1; i <= 4; i++) {
            int x = location[0] + dx[i];
            int y = location[1] + dy[i];
            addNoCost(queue,new int[]{x,y},grid,visited);
        }
        return;
    }
}