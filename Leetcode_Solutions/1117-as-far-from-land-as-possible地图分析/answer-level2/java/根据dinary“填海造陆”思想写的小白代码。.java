    public int maxDistance(int[][] grid) {
        N = grid.length;

        List<Point> landList = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    landList.add(new Point(j, i));
                }
            }
        }

        // 如果我们的地图上只有陆地或者海洋，请返回 -1
        int size = landList.size();
        if (size == 0 || size == N * N) {
            return -1;
        }

        //开始填海
        fillSea(landList);

        return distance;
    }

    public void fillSea(List<Point> landList) {
        if (landList.isEmpty()) {
            return;
        }

        distance++;

        // 计算新陆地
        List<Point> newLandList = new ArrayList<>();
        for (Point p : landList) {
            landMap.putIfAbsent(p.getKey(), p);

            Point top = new Point(p.x, p.y - 1);
            if (isNewLand(top)) {
                newLandList.add(top);
            }

            Point bottom = new Point(p.x, p.y + 1);
            if (isNewLand(bottom)) {
                newLandList.add(bottom);
            }

            Point left = new Point(p.x - 1, p.y);
            if (isNewLand(left)) {
                newLandList.add(left);
            }

            Point right = new Point(p.x + 1, p.y);
            if (isNewLand(right)) {
                newLandList.add(right);
            }

        }

        fillSea(newLandList);
    }

    public boolean isNewLand(Point p) {

        if (p.x < 0 || p.x > (N - 1) || p.y < 0 || p.y > (N - 1)) {
            return false;
        }

        if (landMap.containsKey(p.getKey())) {
            return false;
        }

        landMap.put(p.getKey(), p);
        return true;
    }

    int N = 0;

    private int distance = -1;

    // 存陆地，防止重复计算
    private Map<String, Point> landMap = new HashMap<>();

    private class Point {
        int x = 0;

        int y = 0;

        public Point(int x1, int y1) {
            x = x1;
            y = y1;
        }

        // 坐标拼接，作为唯一标识
        public String getKey() {
            return x + "," + y;
        }

    }