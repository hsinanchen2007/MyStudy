### 解题思路
DFS 遍历所有状态，不过未避免死循环，用一个Set将遍历过的状态存起来，这种思路是比较容易想到的

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        Stack<Pair<Integer, Integer>> stack = new Stack<>();
        Set<Pair<Integer, Integer>> set = new HashSet<>(); // 遍历过的节点存起来，防止死循环
        stack.push(new Pair<>(x, y));
        set.add(new Pair<>(x, y));
        while (!stack.isEmpty()) {
            Pair<Integer, Integer> pair = stack.pop();
            if (pair.getKey() == z || pair.getValue() == z || pair.getKey() + pair.getValue() == z) {
                return true;
            }
            // 装满x水壶
            if (!set.contains(new Pair<>(x, pair.getValue()))) {
                stack.add(new Pair<>(x, pair.getValue()));
                set.add(new Pair<>(x, pair.getValue()));
            }
            // 装满y水壶
            if (!set.contains(new Pair<>(pair.getKey(), y))) {
                stack.add(new Pair<>(pair.getKey(), y));
                set.add(new Pair<>(pair.getKey(), y));
            }
            // 清空x水壶
            if (!set.contains(new Pair<>(0, pair.getValue()))) {
                stack.add(new Pair<>(0, pair.getValue()));
                set.add(new Pair<>(0, pair.getValue()));
            }
            // 清空y水壶
            if (!set.contains(new Pair<>(pair.getKey(), 0))) {
                stack.add(new Pair<>(pair.getKey(), 0));
                set.add(new Pair<>(pair.getKey(), 0));
            }

            // x水壶向y水壶倒水
            if (pair.getKey() + pair.getValue() < y && !set.contains(new Pair<>(0, pair.getKey() + pair.getValue()))) {
                stack.add(new Pair<>(0, pair.getKey() + pair.getValue()));
                set.add(new Pair<>(0, pair.getKey() + pair.getValue()));
            }
            if (pair.getKey() + pair.getValue() > y && !set.contains(new Pair<>(pair.getKey() + pair.getValue() - y, y))) {
                stack.add(new Pair<>(pair.getKey() + pair.getValue() - y, y));
                set.add(new Pair<>(pair.getKey() + pair.getValue() - y, y));
            }

            // y水壶向x水壶倒水
            if (pair.getValue() + pair.getKey() < y && !set.contains(new Pair<>(pair.getValue() + pair.getKey(), 0))) {
                stack.add(new Pair<>(pair.getValue() + pair.getKey(), 0));
                set.add(new Pair<>(pair.getValue() + pair.getKey(), 0));
            }
            if (pair.getValue() + pair.getKey() > y && !set.contains(new Pair<>(x, pair.getValue() + pair.getKey() - x))) {
                stack.add(new Pair<>(x, pair.getValue() + pair.getKey() - x));
                set.add(new Pair<>(x, pair.getValue() + pair.getKey() - x));
            }


        }
        return false;
    }
}
```