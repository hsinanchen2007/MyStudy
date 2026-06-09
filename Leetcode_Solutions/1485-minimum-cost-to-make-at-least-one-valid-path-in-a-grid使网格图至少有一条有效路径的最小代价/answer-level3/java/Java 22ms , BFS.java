
思路就是从目标开始逐层传染，能直接到目的地的点传染为0层。
然后0层相邻的不可直达点传染为1层，
然后1层相邻的不可直达点传染为2层，
依次类推


```
    class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    int[][] mark;

    public int minCost(int[][] grid) {
        int count = 0;
        ArrayDeque<Point> searchLayer = new ArrayDeque<>();
        int m = grid.length;
        int n = grid[0].length;
        mark = new int[m][n];
        for (int i = 0; i < mark.length; i++) Arrays.fill(mark[i], -1);
        searchLayer.add(new Point(m - 1, n - 1));
        mark[m - 1][n - 1] = 0;
        boolean[] found =  new boolean[]{false};
        List<Point> pathPoints = findPathPoints(grid, searchLayer.peek(), count, found);
        if(found[0]) return count;
        searchLayer.addAll(pathPoints);
        while (!searchLayer.isEmpty()) {
            count++;
            int size = searchLayer.size();
            for (int i = 0; i < size; i++) {
                Point point = searchLayer.poll();
                int nx;
                int ny;
                Point[] neighbors = new Point[4];
                //left
                nx = point.x;
                ny = point.y-1;
                if(ny>=0 && mark[nx][ny] == -1){
                    neighbors[0] = new Point(nx, ny);
                }
                //right
                nx = point.x;
                ny = point.y+1;
                if(ny<n && mark[nx][ny] == -1){
                    neighbors[1] =  new Point(nx, ny);
                }
                //up
                nx = point.x-1;
                ny = point.y;
                if(nx>=0 && mark[nx][ny] == -1){
                    neighbors[2] =  new Point(nx, ny);

                }
                //down
                nx = point.x+1;
                ny = point.y;
                if(nx<m && mark[nx][ny] == -1){
                    neighbors[3] =  new Point(nx, ny);
                }
                for(Point p:neighbors){
                    if(p == null) continue;
                    mark[p.x][p.y] = count;
                    searchLayer.add(p);
                    found[0] = false;
                    searchLayer.addAll(findPathPoints(grid,p,count,found));
                    if(found[0])return count;
                }
            }
        }
        return -1;
    }

    List<Point> findPathPoints(int[][] grid, Point point, int count, boolean[] found){
        List<Point> res =  new ArrayList<>();
        ArrayDeque<Point> deque= new ArrayDeque<>();
        if(point.x == 0 && point.y ==0){
            found[0] = true;
            return res;
        }
        deque.add(point);
        while(!deque.isEmpty()){
            int size = deque.size();
            for(int i=0;i<size;i++){
                Point p = deque.poll();
                Point[] neighbors =  new Point[4];
                neighbors[0] = leftOK(grid, p);
                neighbors[1] = rightOK(grid, p);
                neighbors[2] = upOK(grid, p);
                neighbors[3] = downOK(grid, p);
                for(Point nb :neighbors){
                    if(null != nb){
                        if(nb.x ==0 && nb.y==0){
                            found[0] = true;
                            return res;
                        }
                        deque.add(nb);
                        res.add(nb);
                        mark[nb.x][nb.y]=count;
                    }
                }
            }
        }
        return res;
    }

    Point upOK(int[][] grid, Point point) {
        int nx = point.x - 1;
        int ny = point.y;
        if (nx >= 0 && mark[nx][ny] == -1 && grid[nx][ny] == 3 ) {
            return new Point(nx, ny);
        }
        return null;
    }

    Point downOK(int[][] grid, Point point) {
        int nx = point.x + 1;
        int ny = point.y;
        if (nx < grid.length && mark[nx][ny] == -1 && grid[nx][ny] == 4 ) {
            return new Point(nx, ny);
        }
        return null;
    }

    Point leftOK(int[][] grid, Point point) {
        int nx = point.x;
        int ny = point.y - 1;
        if (ny >= 0 && mark[nx][ny] == -1 && grid[nx][ny] == 1 ) {
            return new Point(nx, ny);
        }
        return null;
    }

    Point rightOK(int[][] grid, Point point) {
        int nx = point.x;
        int ny = point.y + 1;
        if (ny < grid[0].length && mark[nx][ny] == -1 && grid[nx][ny] == 2 ) {
            return new Point(nx, ny);
        }
        return null;
    }
```
