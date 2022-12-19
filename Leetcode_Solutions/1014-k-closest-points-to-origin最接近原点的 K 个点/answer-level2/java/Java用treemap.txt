### 解题思路
将距离用treeMap保存起来，自动按从小到大排序，然后遍历输出k位即可

### 代码

```java
class Solution {
  public int[][] kClosest(int[][] points, int K) {
        if (points == null || points.length == 0 || points[0].length == 0) {
            return new int[][] {};
        }
        TreeMap<Double, List<int[]>> treeMap = new TreeMap<>();
        for (int[] point : points) {
            int s = point[0] * point[0] + point[1] * point[1];
            Double sqrt = Math.sqrt(s);
            List<int[]> pointList = treeMap.getOrDefault(sqrt, new ArrayList<>());
            pointList.add(point);
            treeMap.put(sqrt, pointList);
        }
        List<int[]> output = new LinkedList<>();
        int i = 0;
        for (Map.Entry<Double, List<int[]>> entry : treeMap.entrySet()) {
            List<int[]> pointList = entry.getValue();
            for (int[] p : pointList) {
                if (i < K) {
                    output.add(p);
                    i++;
                }
            }
        }
        return output.toArray(new int[K][2]);
    }
}
```