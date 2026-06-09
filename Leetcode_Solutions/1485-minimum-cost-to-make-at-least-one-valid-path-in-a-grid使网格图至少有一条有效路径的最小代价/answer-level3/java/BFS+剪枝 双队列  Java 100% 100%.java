使用两个队列，一个队列存储按照指示走能到达的点BFS，另一个队列忽略指示存储所有BFS能到达的点。
如果无法到达目的地（BFS队列空了），则将另一个队列所有元素置入BFS队列中，同时增加一个花费，继续进行BFS，直到到达目的地为止，注意不要走已经走过的结点，否则会超时，代码如下：
```
    public int minCost(int[][] grid) {
        class Point {
            int x;
            int y;

            Point(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }
        int cost = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[][] used = new int[m][n];
        used[0][0] = 1;
        Queue<Point> queue = new LinkedList<Point>();
        Queue<Point> tmpQueue = new LinkedList<Point>();
        Point p = new Point(0, 0);
        queue.add(p);
        while (true) {
            p = queue.poll();
            int x = p.x;
            int y = p.y;
            if(x == m - 1 && y == n - 1)
                break;
            //备用队列填数
            if (x < m - 1 && used[x + 1][y] == 0) {
                tmpQueue.add(new Point(x + 1, y));
            }
            if(x > 0 && used[x - 1][y] == 0){
                tmpQueue.add(new Point(x - 1, y));
            }
            if(y < n - 1 && used[x][y + 1] == 0){
                tmpQueue.add(new Point(x, y + 1));
            }
            if(y > 0 && used[x][y - 1] == 0){
                tmpQueue.add(new Point(x, y - 1));
            }

            if (grid[x][y] == 1 && y < n - 1 && used[x][y+1] == 0) {
                used[x][y+1] = 1;
                ++p.y;
                queue.add(p);
            } else if (grid[x][y] == 2 && y > 0 && used[x][y-1] == 0) {
                used[x][y-1] = 1;
                --p.y;
                queue.add(p);
            } else if (grid[x][y] == 3 && x < m - 1 && used[x+1][y] == 0) {
                used[x+1][y] = 1;
                ++p.x;
                queue.add(p);
            } else if (grid[x][y] == 4 && x > 0 && used[x-1][y] == 0) {
                used[x-1][y] = 1;
                --p.x;
                queue.add(p);
            }

            if(queue.isEmpty()){
                while (!tmpQueue.isEmpty()){
                    Point tmp = tmpQueue.poll();
                    used[tmp.x][tmp.y] = 1;
                    queue.add(tmp);
                }
                ++cost;
            }
        }
        return cost;
    }
```
