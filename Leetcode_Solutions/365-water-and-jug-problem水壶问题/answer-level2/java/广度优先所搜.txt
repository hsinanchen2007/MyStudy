### 解题思路
借鉴官方题解，复杂度比较高

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (z > x + y) return false;
        // 保存状态的队列
        Stack<Pair<Integer, Integer>> stack = new Stack<>();
        stack.add(new Pair<>(0, 0));
        // 记录状态是否被访问过的数组
        Set<Pair<Integer, Integer>> visited = new HashSet<>();
        while (!stack.isEmpty()){
            Pair<Integer, Integer> currState = stack.pop();
            int remainX = currState.getKey();
            int remainY = currState.getValue();
            if (remainX == z || remainY == z || remainX + remainY == z) return true;
            if (visited.contains(new Pair<>(remainX, remainY))) continue;
            visited.add(new Pair<>(remainX, remainY));
            stack.add(new Pair<>(x, remainY));  // x 倒满
            stack.add(new Pair<>(remainX, y));  // y 倒满
            stack.add(new Pair<>(0, remainY));  // x 倒空
            stack.add(new Pair<>(remainX, 0));  // y 倒空
            // 把 x 倒入 y ，直至 y 满或 x 空
            stack.add(new Pair<>(remainX - Math.min(remainX, y - remainY), remainY + Math.min(remainX, y - remainY)));
            // 把 y 倒入 x，直至 x 满或 y 空
            stack.add(new Pair<>(remainX + Math.min(remainY, x - remainX), remainY - Math.min(remainY, x - remainX)));
        }
        return false;
    }
}
```