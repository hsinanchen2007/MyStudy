### 解题思路
参考英文区这个答案秒懂的[https://leetcode.com/problems/water-and-jug-problem/discuss/83716/Java-Programmatic-Solution-BFS-without-GCD]()

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
//1.边界判断
        if (x + y < z || z < 0) return false;
        //2.存放所有可能的状态,并用来防止重复进入同一状态
        Set<Integer> set = new HashSet<>();
        //3.存放当前存活的各种状态
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            //1.将x灌满;(curr + x <= x + y -->说明curr<=y,可以将curr 全部放入 y 中,x此时为空)
            if (curr + x <= x + y && set.add(curr + x))
                queue.offer(curr + x);
            //2.将y灌满
            if (curr + y <= x + y && set.add(curr + y))
                queue.offer(curr + y);
            //3.将x清空
            if (curr - x >= 0 && set.add(curr - x))
                queue.offer(curr - x);
            //4.将y清空
            if (curr - y >= 0 && set.add(curr - y))
                queue.offer(curr - y);
            if (set.contains(z))
                return true;
        }
        return false;
    }
}
```