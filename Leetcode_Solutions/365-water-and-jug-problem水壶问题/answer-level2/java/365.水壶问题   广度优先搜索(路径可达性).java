参考甜姨的题解，广度优先搜索实现，甜姨题解Tips提到的将queue改成stack即为深度优先搜索的实现。
x、y桶水量构成的Tuple2可以看作图中一个节点，每次装水/倒水，相当于从一个状态向另一个状态的转换，即从图中的一个节点走向另一个节点。因此该题目也可以看作了，从(0,0)节点出发，到(x+y=z)节点的可达性问题。因此采用广度/深度优先搜索可以解决。
```java
import java.util.*;
class Solution {
   public boolean canMeasureWater(int x, int y, int z) {
        Queue<Map.Entry<Integer, Integer>> queue = new ArrayDeque<>();
        Set<Map.Entry<Integer, Integer>> visited = new HashSet<>();
        // 搜索出发点
        queue.add(new AbstractMap.SimpleEntry<>(0, 0));
        while (!queue.isEmpty()) {
            Map.Entry<Integer, Integer> node = queue.poll();
            // 当前x桶水量
            Integer curX = node.getKey();
            // 当前y桶水量
            Integer curY = node.getValue();
            // 异常情况直接返回
            if (x + y < z) {
                return false;
            }
            if ((x == 0) || (y == 0)) {
                return z == 0 || x + y == z;
            }
            if ((curX == z) || (curY == z) || (curX + curY == z)) {
                return true;
            }

            // 装满x桶
            if (curX == 0) {
                addWater(queue, new AbstractMap.SimpleEntry<>(x, curY), visited);
            }
            // 装满y桶
            if (curY == 0) {
                addWater(queue, new AbstractMap.SimpleEntry<>(curX, y), visited);
            }
            // 倒空x桶
            if (curY < y) {
                addWater(queue, new AbstractMap.SimpleEntry<>(0, curY), visited);
            }
            // 倒空y桶
            if (curX < x) {
                addWater(queue, new AbstractMap.SimpleEntry<>(curX, 0), visited);
            }

            // 向y桶装水
            int modifyYSize = Math.min(curX, y - curY);
            addWater(queue, new AbstractMap.SimpleEntry<>(curX - modifyYSize, curY + modifyYSize), visited);

            // 向x桶装水
            int modifyXsize = Math.min(x - curX, curY);
            addWater(queue, new AbstractMap.SimpleEntry<>(curX + modifyXsize, curY - modifyXsize), visited);

        }
        return false;
    }

    private void addWater(Queue<Map.Entry<Integer, Integer>> queue, Map.Entry<Integer, Integer> entry,
                          Set<Map.Entry<Integer, Integer>> visited) {
        if (!visited.contains(entry)) {
            visited.add(entry);
            queue.add(entry);
        }
    }
}
```
