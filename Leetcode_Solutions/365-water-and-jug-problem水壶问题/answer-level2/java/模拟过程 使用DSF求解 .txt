### 解题思路
    模拟过程 使用DSF求解 
    X -> 0 | X -> Full | Y -> 0 | Y -> Full | X -> Y | Y -> x
    时间复杂度O(xy)

    相比而言 数学方法更好 
    求 x y 的最大公约数，判断 z 是否可被 最大公约数整除
    mX + nY = Z
### 代码

```java
import java.util.*;

class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z == 0) return true;
        if(x + y < z) return false;
        if((x == 0 && y != z) || (y == 0 && x != z)) return false;
        Stack<Map.Entry<Integer, Integer>> stack = new Stack<>();
        AbstractMap.SimpleEntry<Integer, Integer> status = new AbstractMap.SimpleEntry<Integer, Integer>(0, 0);
        stack.push(status);
        Set<Map.Entry<Integer, Integer>> set = new HashSet<>();
        while(stack.size() > 0){
            Map.Entry<Integer, Integer> currentStatus = stack.pop();
            int remainX = currentStatus.getKey();
            int remainY = currentStatus.getValue();
            if(remainX==z || remainY==z || remainX+remainY==z) return true;
            if(set.contains(currentStatus)) continue;
            set.add(currentStatus);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus1 = new AbstractMap.SimpleEntry<>(0, remainY);
            stack.push(nextStatus1);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus2 = new AbstractMap.SimpleEntry<>(x, remainY);
            stack.push(nextStatus2);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus3 = new AbstractMap.SimpleEntry<>(remainX, 0);
            stack.push(nextStatus3);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus4 = new AbstractMap.SimpleEntry<>(remainX, y);
            stack.push(nextStatus4);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus5 =
                    new AbstractMap.SimpleEntry<>(remainX - Math.min(remainX, y - remainY), remainY + Math.min(remainX, y - remainY));
            stack.push(nextStatus5);
            AbstractMap.SimpleEntry<Integer, Integer> nextStatus6 =
                    new AbstractMap.SimpleEntry<>(remainX + Math.min(remainY, x - remainX), remainY - Math.min(remainY, x - remainX));
            stack.push(nextStatus6);
        }
        return false;
    }
}
```