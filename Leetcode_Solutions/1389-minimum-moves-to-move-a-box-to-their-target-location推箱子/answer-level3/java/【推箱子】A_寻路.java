箱子按A*寻路运动，箱子有3个状态：坐标(x,y),方向d。之所以要d，是考虑有些地形需要往回走，A*寻路不支持。
每次箱子运动时，检查人是否能从运动前的位置到新的方向的后方。
按面向对象的方式定义了一些类，写的比较长
```java []
class Solution {

    public static class Vec3 {
        public final int x;
        public final int y;
        public final int d;

        public Vec3(int x, int y, int d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Vec3 vec3 = (Vec3) o;

            if (x != vec3.x) return false;
            if (y != vec3.y) return false;
            return d == vec3.d;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            result = 31 * result + d;
            return result;
        }

        @Override
        public String toString() {
            return "(" + x + "," + y + "," + d + ")";
        }

        public static Vec3 create(int x, int y, int d) {
            return new Vec3(x, y, d);
        }

        public Vec2 toVec2() {
            return Vec2.create(x, y);
        }

    }

    public static class Vec2 {
        public final int x;
        public final int y;

        public Vec2(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Vec2 vec2 = (Vec2) o;

            if (x != vec2.x) return false;
            return y == vec2.y;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

        @Override
        public String toString() {
            return "(" + x + "," + y + ")";
        }

        public Vec2 add(Vec2 v) {
            return new Vec2(x + v.x, y + v.y);
        }

        public Vec2 subtract(Vec2 v) {
            return new Vec2(x - v.x, y - v.y);
        }

        public int distanceTo(Vec2 v) {
            return Math.abs(this.x - v.x) + Math.abs(this.y - v.y);
        }

        public static Vec2 create(int x, int y) {
            return new Vec2(x, y);
        }

        public Vec3 toVec3(int d) {
            return Vec3.create(x, y, d);
        }
    }

    public static class PathCost {

        public int toStart;
        public int toTarget;
        public int totalCost;

        public Vec2 point;

        public PathCost(int toStart, int toTarget, Vec2 point) {
            this.toStart = toStart;
            this.toTarget = toTarget;
            this.totalCost = toStart + toTarget;
            this.point = point;
        }

        @Override
        public String toString() {
            return "PathCost[" +
                    "" + toStart +
                    "," + toTarget +
                    "," + totalCost +
                    ']';
        }
    }

    // 方向代号
    private static final int DIR_TOP = 0;
    private static final int DIR_RIGHT = 1;
    private static final int DIR_DOWN = 2;
    private static final int DIR_LEFT = 3;

    private static final int DIR_NUM = 4;

    // 方向向量
    private static final Vec2[] dirArr = new Vec2[]{
            new Vec2(0, 1),
            new Vec2(1, 0),
            new Vec2(0, -1),
            new Vec2(-1, 0),
    };

    private int[][] map;

    private Vec2 dimVec;
    // 起点
    private Vec2 start;
    // 目标
    private Vec2 target;
    // 存放未确定路径点
    private Set<Vec3> openSet;
    // 存放已确定的路径点
    private Set<Vec3> closeSet;
    // 存放路径点和上一级路径点的关系,3个维度:x,y,dir
    private Vec3[][][] parentMap;
    // 路径代价 v -> (p,h,g)
    private PathCost[][][] costMap;

    private PathFinder playerPathFinder;

    public void setMap(char[][] grid) {
        this.map = createMap(grid);
        this.dimVec = Vec2.create(map.length, map[0].length);
        this.playerPathFinder = new PathFinder(map);
    }

    public boolean isWall(Vec2 v) {
        return getMapVal(v) < 0;
    }

    public int getMapVal(Vec2 v) {
        if ((v.x < 0 || v.x >= dimVec.x) || (v.y < 0 || v.y >= dimVec.y)) {
            return -1;
        }
        return this.map[v.x][v.y];
    }

    public Vec3 getParent(Vec3 v) {
        return this.parentMap[v.x][v.y][v.d];
    }

    public void putParent(Vec3 v, Vec3 parent) {
        this.parentMap[v.x][v.y][v.d] = parent;
    }

    public PathCost getCost(Vec3 v) {
        return this.costMap[v.x][v.y][v.d];
    }

    public void putCost(Vec3 v, PathCost cost) {
        this.costMap[v.x][v.y][v.d] = cost;
    }

    // 设置起点和目标点
    public void setStartAndTarget(Vec2 start, Vec2 target, Vec2 player) {
        this.start = start;
        this.target = target;
        this.openSet = new HashSet<>();
        this.closeSet = new HashSet<>();
        this.parentMap = new Vec3[dimVec.x][][];
        this.costMap = new PathCost[dimVec.x][][];
        for (int i = 0; i < dimVec.x; i++) {
            parentMap[i] = new Vec3[dimVec.y][];
            costMap[i] = new PathCost[dimVec.y][];
            for (int j = 0; j < dimVec.y; j++) {
                parentMap[i][j] = new Vec3[DIR_NUM];
                costMap[i][j] = new PathCost[DIR_NUM];
            }
        }

        PathCost startCost = new PathCost(0, estimateToTarget(start, target), start);
        for (int d = DIR_TOP; d <= DIR_LEFT; d++) {
            Vec2 dir = dirArr[d];
            Vec2 p2 = start.add(dir);
            if (isWall(p2)) continue;
            Vec2 player2 = start.subtract(dir);
            if (isWall(player2)) continue;

            List<Vec2> uPath = minPathByAStar(playerPathFinder, player, player2, start);
            if (uPath == null) continue;

            Vec3 p = start.toVec3(d);
            openSet.add(p);
            putCost(p, startCost);
//            putParent(p, player2.toVec3(d));
        }
    }

    public Vec3 getTarget(Set<Vec3> set, Vec2 target) {
        for (int d = DIR_TOP; d <= DIR_LEFT; d++) {
            Vec3 target_ = target.toVec3(d);
            if (set.contains(target_)) return target_;
        }
        return null;
    }

    public int next() {
        if (getTarget(openSet, target) != null) {
            return 0; // 找到了终点
        }
        if (openSet.isEmpty()) {
            return -1; // 终点不存在
        }
        // 找到代价最小的路径
        final Vec3 p = openSet.stream().min(Comparator.comparingInt(it -> getCost(it).totalCost)).orElse(null);
        openSet.remove(p);
        closeSet.add(p);
        // 旋转
        for (int i = 0; i < DIR_NUM; i++) {
            int d = (i + p.d) % DIR_NUM;
            final Vec2 dir = dirArr[d]; // 优先正向移动

            final Vec2 p_ = p.toVec2();
            // box: p3 --push--> p -> p2
            // player: p0 --move--> p3
            final Vec2 p2 = p_.add(dir); // 后一个点
            final Vec3 p2_ = p2.toVec3(d);
            // System.out.println(p + "->" + dir + "->" + p2_);
            if (closeSet.contains(p2_)) continue;
            if (isWall(p2)) continue;
            final Vec2 p3 = p_.subtract(dir); // 后一个推点
            if (isWall(p3)) continue;
//            final Vec2 p0 = p_.subtract(dirArr[p.d]);
//            final Vec2 p0 = getParent(p).toVec2();
//            Vec2 dir0 = p.toVec2().subtract(p0);
            if (d != p.d) { // box直线运动
                final Vec2 p0 = p_.subtract(dirArr[p.d]);
                List<Vec2> uPath = minPathByAStar(playerPathFinder, p0, p3, p_);
                if (uPath == null) continue;
            }
            PathCost cost = estimateCost(p, p2);
            if (openSet.contains(p2_)) {
                PathCost oldCost = getCost(p2_);
                if (cost.totalCost < oldCost.totalCost) {
                    putParent(p2_, p);
                    putCost(p2_, cost);
                }
            } else {
                openSet.add(p2_);
                putParent(p2_, p);
                putCost(p2_, cost);
            }
        }
        return 1;
    }

    public List<Vec3> findPath() {
        int result;
        for (int i = 0; (result = next()) == 1; i++) {
            // System.out.printf("%02d:\n", i);
            // System.out.println(mapToViews());
        }
        if (result != 0) {
            return null;
        }
        final List<Vec3> path = findPath(parentMap, getTarget(openSet, target));
        // System.out.printf("step:%s\n", path.size());
        // System.out.printf("path:%s\n", path);
        return path;
    }

    public List<Vec3> findPath(Vec3[][][] parentMap, Vec3 v) {
        List<Vec3> path = new ArrayList<>();
        Vec3 pre;
        while ((pre = getParent(v)) != null) {
            path.add(v);
            v = pre;
        }
        return path;
    }

    private PathCost estimateCost(Vec3 v, Vec2 v2) {
        return new PathCost(computeToStart(v, v2), estimateToTarget(v2, target), v2);
    }

    // 计算到起点的路径长度
    private int computeToStart(Vec3 v, Vec2 v2) {
        return getCost(v).toStart + getMapVal(v2);
    }

    // 估算到终点的路径长度
    private int estimateToTarget(Vec2 v2, Vec2 target) {
        return target.distanceTo(v2);
    }

    public static int[][] createMap(char[][] grid) {
        Map<Character, Integer> valMap = new HashMap<>();
        valMap.put('#', -1); // 不可移动
        valMap.put('.', 1); // 移动代价是1
        valMap.put('S', 1);
        valMap.put('B', 1);
        valMap.put('T', 1);

//        final Vec3 dimVec3 = Vec3.create(grid[0].length, grid.length, DIR_NUM);
//        Vec3Map<Integer> map = new Vec3Map<>(dimVec3);
        int[][] map = new int[grid.length][];
        for (int i = 0; i < grid.length; i++) {
            final char[] line = grid[i];
            map[i] = new int[line.length];
            for (int j = 0; j < line.length; j++) {
                final char val = line[j];
                final Integer val2 = valMap.get(val);
                if (val2 == null) {
                    throw new IllegalArgumentException("找不到对应的映射,val(" + i + "," + j + ")=" + val);
                }
                map[i][j] = val2;
            }
        }
        return map;
    }

    public static Vec2 searchVec2(char[][] grid, char x) {
        for (int i = 0; i < grid.length; i++) {
            final char[] line = grid[i];
            for (int j = 0; j < line.length; j++) {
                if (line[j] == x) {
                    return Vec2.create(i, j);
                }
            }
        }
        return null;
    }

    public static class PathFinder {

        private int[][] map;

        private Vec2 dimVec;
        // 起点
        private Vec2 start;
        // 目标
        private Vec2 target;
        // 存放未确定路径点
        private Set<Vec2> openSet;
        // 存放已确定的路径点
        private Set<Vec2> closeSet;
        // 存放路径点和上一级路径点的关系
        private Vec2[][] parentMap;
        // 路径代价 v -> (p,h,g)
        private PathCost[][] costMap;

        private static final Vec2[] unitVecList = dirArr;

        public int getMapVal(Vec2 v) {
            if ((v.x < 0 || v.x >= dimVec.x) || (v.y < 0 || v.y >= dimVec.y)) {
                return -1;
            }
            return this.map[v.x][v.y];
        }

        public Vec2 getParent(Vec2 v) {
            return this.parentMap[v.x][v.y];
        }

        public void putParent(Vec2 v, Vec2 parent) {
            this.parentMap[v.x][v.y] = parent;
        }

        public PathCost getCost(Vec2 v) {
            return this.costMap[v.x][v.y];
        }

        public void putCost(Vec2 v, PathCost cost) {
            this.costMap[v.x][v.y] = cost;
        }

        public int next() {
            if (openSet.contains(target)) {
                return 0; // 找到了终点
            }
            if (openSet.isEmpty()) {
                return -1; // 终点不存在
            }
            // 找到代价最小的路径
            final Vec2 v = openSet.stream().min(Comparator.comparingInt(it -> getCost(it).totalCost)).orElse(null);
            openSet.remove(v);
            closeSet.add(v);
            for (Vec2 unitVec : unitVecList) {
                final Vec2 v2 = v.add(unitVec);
                if (isWall(v2)) {
                    continue; // 不可通过的点
                }
                if (closeSet.contains(v2)) {
                    continue; // 已经确定的路径
                }
                final PathCost cost = estimateCost(v, v2);
                if (!openSet.contains(v2)) {
                    openSet.add(v2);
                    putCost(v2, cost);
                    putParent(v2, v);
                } else {
                    // 已经探测过的路径，重新计算代价
                    PathCost oldCost = getCost(v2);
                    if (cost.totalCost < oldCost.totalCost) {
                        putCost(v2, cost);
                        putParent(v2, v);
                    }
                }
            }
            return 1;
        }

        public boolean isWall(Vec2 v2) {
            return getMapVal(v2) < 0;
        }

        private PathCost estimateCost(Vec2 v, Vec2 v2) {
            return new PathCost(computeToStart(v, v2), estimateToTarget(v2, target), v2);
        }

        // 计算到起点的路径长度
        private int computeToStart(Vec2 v, Vec2 v2) {
            return getCost(v).toStart + getMapVal(v2);
        }

        // 估算到终点的路径长度
        private int estimateToTarget(Vec2 v2, Vec2 target) {
            return target.distanceTo(v2);
        }

        public List<Vec2> findPath() {
            int result;
            for (int i = 0; (result = next()) == 1; i++) {
            }
            if (result != 0) {
                return null;
            }
            final List<Vec2> path = findPath(parentMap, target);
            return path;
        }

        public List<Vec2> findPath(Vec2[][] parentMap, Vec2 v) {
            List<Vec2> path = new ArrayList<>();
            Vec2 pre;
            while ((pre = getParent(v)) != null) {
                path.add(v);
                v = pre;
            }
            return path;
        }

        public PathFinder(int[][] map) {
            this.map = map;
            this.dimVec = Vec2.create(map.length, map[0].length);
        }

        // 设置起点和目标点
        public void setStartAndTarget(Vec2 start, Vec2 target) {
            this.start = start;
            this.target = target;
            this.openSet = new HashSet<>();
            this.closeSet = new HashSet<>();
            this.parentMap = new Vec2[dimVec.x][];
            this.costMap = new PathCost[dimVec.x][];
            for (int i = 0; i < dimVec.x; i++) {
                parentMap[i] = new Vec2[dimVec.y];
                costMap[i] = new PathCost[dimVec.y];
            }
            openSet.add(start);
            putCost(start, new PathCost(0, estimateToTarget(start, target), start));
        }

    }

    public static List<Vec2> minPathByAStar(char[][] grid) {
        int[][] map = createMap(grid);
        PathFinder pathFinder = new PathFinder(map);
//        final Vec2 player = searchVec2(grid, 'S');
        final Vec2 box = searchVec2(grid, 'B');
        final Vec2 target = searchVec2(grid, 'T');
        pathFinder.setStartAndTarget(box, target);
        return pathFinder.findPath();
    }

    public static List<Vec2> minPathByAStar(PathFinder pathFinder, Vec2 start, Vec2 target, Vec2 box) {
        pathFinder.setStartAndTarget(start, target);
        pathFinder.closeSet.add(box);
        return pathFinder.findPath();
    }

    public List<Vec3> minPath(char[][] grid) {
        setMap(grid);
        final Vec2 player = searchVec2(grid, 'S');
        final Vec2 box = searchVec2(grid, 'B');
        final Vec2 target = searchVec2(grid, 'T');
        setStartAndTarget(box, target, player);
        return findPath();
    }

    public int minPushBox(char[][] grid) {
        List<Vec3> path = minPath(grid);
        return path != null ? path.size() : -1;
    }

    private void forEach(int[][] map, BiConsumer<Vec2, Integer> consumer) {
        for (int i = 0; i < dimVec.x; i++) {
            for (int j = 0; j < dimVec.y; j++) {
                consumer.accept(Vec2.create(i, j), map[i][j]);
            }
        }
    }

    private <T> void forEach(T[][][] map, BiConsumer<Vec3, T> consumer) {
        for (int i = 0; i < dimVec.x; i++) {
            for (int j = 0; j < dimVec.y; j++) {
                for (int d = DIR_TOP; d <= DIR_LEFT; d++) {
                    if (map[i][j][d] == null) continue;
                    consumer.accept(Vec3.create(i, j, d), map[i][j][d]);
                }
            }
        }
    }

    public List<String> pathToViews(List<Vec3> path) {
        LinkedHashMap<Vec2, String> symbolMap = new LinkedHashMap<>();
        forEach(map, (v, val) -> symbolMap.put(v, val >= 0 ? "." : "#"));
        symbolMap.put(start, "S");
        symbolMap.put(target, "T");
        path.forEach(v -> symbolMap.put(v.toVec2(), "@"));
        return mapToView(symbolMap, 2);
    }

    public String mapToViews() {
//            System.out.println("openSet:" + openSet);
//            System.out.println("closeSet:" + closeSet);
//            System.out.println("costMap:" + costMap);
        LinkedHashMap<Vec2, String> symbolMap = new LinkedHashMap<>();
        forEach(map, (v, val) -> symbolMap.put(v, val >= 0 ? "." : "#"));
        openSet.forEach(v -> symbolMap.put(v.toVec2(), "O"));
        closeSet.forEach(v -> symbolMap.put(v.toVec2(), "X"));
        symbolMap.put(start, "S");
        symbolMap.put(target, "T");

        final List<String> view1 = mapToView(symbolMap, 2);

        LinkedHashMap<Vec2, String> symbolMap2 = new LinkedHashMap<>();
        forEach(map, (v, val) -> symbolMap2.put(v, val >= 0 ? "." : "#"));
        symbolMap2.put(start, "S");
        symbolMap2.put(target, "T");
//        costMap.forEach((v, cost) -> symbolMap2.put(v, cost.totalCost + ""));
        forEach(costMap, (v, cost) -> symbolMap2.put(v.toVec2(), cost.toStart + "+" + cost.toTarget));
        final List<String> view2 = mapToView(symbolMap2, 5);

        final Vec3 v = openSet.stream().min(Comparator.comparingInt(it -> getCost(it).totalCost)).orElse(null);
        if (v == null) {
            return "";
        }
        List<Vec3> path = findPath(parentMap, v);
        List<String> view0 = pathToViews(path);

        String str = "";
        str += "path:" + path + "\n";
        for (int i = 0; i < view1.size(); i++) {
            str += view0.get(i) + "  |   " + view1.get(i) + "  |   " + view2.get(i) + "\n";
//            str += view1.get(i) + "  |   " + view2.get(i) + "\n";
        }
        return str;
    }

    private List<String> mapToView(LinkedHashMap<Vec2, String> symbolMap, int width) {
        List<String> lines = new ArrayList<>();
        for (int i = 0; i < dimVec.x; i++) {
            String line = "";
            for (int j = 0; j < dimVec.y; j++) {
                final Vec2 v = Vec2.create(i, j);
                final String symbol = symbolMap.getOrDefault(v, "?");
                line += String.format("%-" + width + "s", symbol) + " ";
            }
            lines.add(line);
        }
        return lines;
    }

}
```
