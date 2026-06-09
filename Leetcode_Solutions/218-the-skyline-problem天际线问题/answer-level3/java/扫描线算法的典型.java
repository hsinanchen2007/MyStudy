### 解题思路
  这是典型的扫描线算法的应用场景。
  扫描线算法就是把所有的点排序。然后从左到右扫描，维护数据结构保存当前还活跃的实体。本题就是维护当前还存在的building。
  在每一点，天际线的高度就是当前还存在的building的最大高度。每到第一个点，核算当前还有那些building存在。它们的最高点就是当前天际线的高度。如果跟之前发生了变化，就形成了一个关键点。记录下来。
  算法的实现其实很简单。有两个数据结构需要注意。
  一是维护当前存在的building，并能够随时取得最大高度。这需要以高度进行排序，并且能够快速查找某个building。这就需要用二叉树排序。Java中就是TreeSet。TreeSet有个特性，如果compareTo()返回0，就认为是同一个元素。但是我们这里楼高相同是允许的。因此，实现的时候需要对楼高相同的再比较另一个字段确定大小的不同。我给每个building了一个id，专用来比较。
  二是所有的点，就是楼的左边界和右边界。一个办法是都堆到一个List里，再用Collections.sort()排序。还可以用堆，PriorityQueue。理论上用堆更合适。但复杂度是一样的。实际中也没有看到明显的区别。
  代码执行用时19ms，前10%。

### 代码

```java
class Solution {
    private class Point {
        int pos;
        boolean isLeft;
        Building building;
        public Point(int pos, boolean isLeft, Building building) {
            this.pos = pos;
            this.isLeft = isLeft;
            this.building = building;
        }
    }
    private class Building implements Comparable<Building> {
        int height, id;
        public Building(int height, int id) {
            this.height = height;
            this.id = id;
        }
        @Override
        public int compareTo(Building another) {
            int diff = this.height - another.height;
            return diff != 0 ? diff : this.id - another.id;
        }
    }
    private List<Integer> buildKeyPoint(int pos, int height) {
        List<Integer> k = new ArrayList<>();
        k.add(pos);
        k.add(height);
        return k;
    }
    public List<List<Integer>> getSkyline(int[][] buildings) {
        if (buildings == null) {
            return null;
        }
        List<List<Integer>> result = new ArrayList<>();
        PriorityQueue<Point> points = new PriorityQueue<Point>((x,y) -> x.pos - y.pos);
        int[] b;
        Building building;
        for (int i = 0; i < buildings.length; i++) {
            b = buildings[i];
            building = new Building(b[2], i);
            points.offer(new Point(b[0], true, building));
            points.offer(new Point(b[1], false, building));
        }
        if (points.isEmpty()) {
            return result;
        }
        TreeSet<Building> liveBuildings = new TreeSet<Building>();
        int currentHeight = 0;
        int currentPos = points.peek().pos;
        int height;
        Point point;
        while ((point = points.poll()) != null) {
            if (point.pos != currentPos) {
                height = liveBuildings.isEmpty() ? 0 : liveBuildings.last().height;
                if (height != currentHeight) {
                    result.add(buildKeyPoint(currentPos, height));
                    currentHeight = height;
                }
                currentPos = point.pos;
            }
            if (point.isLeft) {
                liveBuildings.add(point.building);
            } else {
                liveBuildings.remove(point.building);
            }
        }
        result.add(buildKeyPoint(currentPos, 0));
        return result;
    }
}
```