**方法一：最大公约数思想**
```
class Solution {
  /**
  * 思路：
  * 由题可以转化为容量x和y的两个水杯往足够大的容器中倒水，杯子只能空或者满。
  *   要得到z升水，则z = ax + by（a和b为整数，正表示往里到，负表示往出舀水）。
  *   所以根据裴蜀定律，z只要能除尽x和y的最大公约数就能符合要求。
  */
  public boolean canMeasureWater(int x, int y, int z) {
    // 如果z为0，则不需要操作就满足要求
    if (z == 0){
      return true;
    }
    // 如果x和y都装满都比z小则满足不了要求
    if (z < 0 || x + y < z){
      return false;
    }
    int temp;
    // 区分x和y的大小
    if (x < y){
      temp = x;
      x = y;
      y = temp;
    }
    // 如果小的是0，只有大的等于z才能符合要求
    if (y == 0){
      return x == z;
    }
    // 辗转相除得出初始x和y的最大公约数
    while (x % y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }
    return z % y == 0;
  }
}
```

**方法二：广度优先搜索(BFS)**
由题两容器只能是倒满、清空或者从一个容器倒入另一个容器直到倒满或者自己倒空三种操作。
两容器组合操作状态：
(1) 倒满A。
(2) 倒满B。
(3) 清空A。
(4) 清空B。
(5) A给B倒水。
(6) B给A倒水。
```
import java.util.*;
class Solution {
  /**
  * 思路：
  * 按六种操作状态广度优先遍历，直到找到符合要求的操作状态或者完成所有操作。
  */
  public boolean canMeasureWater(int x, int y, int z) {
    if (z == 0) {
      return true;
    }
    if (z < 0 || x + y < z) {
      return false;
    }
    // 存储所有的组合状态
    Queue<Map.Entry<Integer, Integer>> queue = new ArrayDeque<>();
    AbstractMap.SimpleEntry<Integer, Integer> start = new AbstractMap.SimpleEntry<>(0, 0);
    queue.add(start);
    // 存储处理过的组合状态
    Set<Map.Entry<Integer, Integer>> visited = new HashSet<>();
    visited.add(start);
    while (!queue.isEmpty()) {
      Map.Entry<Integer, Integer> entry = queue.poll();
      int curX = entry.getKey();
      int curY = entry.getValue();
      if (curX == z || curY == z || curX + curY == z) {
        return true;
      }
      if (curX == 0) {
        // 把第一个桶倒满
        addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(x, curY));
      }
      if (curY == 0) {
        // 把第二个桶倒满
        addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(curX, y));
      }
      if (curY < y) {
        // 把第一个桶清空
        addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(0, curY));
      }
      if (curX < x) {
        // 把第二个桶清空
        addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(curX, 0));
      }

      // y - curY是第二个桶还可以再加的水的升数，但是最多只能加curX升水。
      int moveSize = Math.min(curX, y - curY);
      // 把第一个桶里的curX升水倒到第二个桶里去。
      addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(curX - moveSize, curY + moveSize));
      // 反过来同理，x - curX是第一个桶还可以再加的升数，但是最多只能加curY升水。
      moveSize = Math.min(curY, x - curX);
      // 把第一个桶里的curX升水倒到第二个桶里去。
      addIntoQueue(queue, visited, new AbstractMap.SimpleEntry<>(curX + moveSize, curY - moveSize));
    }
    return false;
  }

  private void addIntoQueue(Queue<Map.Entry<Integer, Integer>> queue,
                            Set<Map.Entry<Integer, Integer>> visited,
                            Map.Entry<Integer, Integer> newEntry) {
    if (!visited.contains(newEntry)) {
      visited.add(newEntry);
      queue.add(newEntry);
    }
  }
}
```

**方法三：精简广度优先搜索**
```
class Solution {
  /**
  * 思路：
  * 由题可知，循环操作只能有加减x和加减y四种操作，记录所有能得到的结果。
  */
  public boolean canMeasureWater(int x, int y, int z) {
      if (z < 0 || z > x + y) {
          return false;
      }
      // 存储已经得到过的结果。
      Set<Integer> set = new HashSet<>();
      // 存储所有操作中组合能得到的结果。
      Queue<Integer> q = new LinkedList<>();
      // 保证开始队列不为空。
      q.offer(0);
      while (!q.isEmpty()) {
          // 依次从队列中取出头元素。
          int n = q.poll();
          // set.add方法，返回true表示已存在则不再插入，否则返回false并插入。
          if (n + x <= x + y && set.add(n + x)) {
              // 添加元素到队列队尾。
              q.offer(n + x);
          }
          if (n + y <= x + y && set.add(n + y)) {
              q.offer(n + y);
          }
          if (n - x >= 0 && set.add(n - x)) {
              q.offer(n - x);
          }
          if (n - y >= 0 && set.add(n - y)) {
              q.offer(n - y);
          }
          // 经过四种操作后set中包含结果z，则表示操作符合要求。
          if (set.contains(z)) {
              return true;
          }
      }
      return false;
  }
}
```
