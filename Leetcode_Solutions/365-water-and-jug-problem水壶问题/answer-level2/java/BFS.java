### 解题思路
1、抽象输入，二元组（x,y）
2、其次抽象输出，也是二元组，但是要满足条件 x==z || y==z || x+y==z
3、抽象分支（6个分支）：清空x，清空y，装满x，装满y，x尽力给y倒（注意这里水不能流出去），y尽力给x到。

有以上三个思维准备，一个类似树的算法结构图就出来了，然后就用BFS或DFS处理就完事了。
例子给的是BFS，
DFS也可以，把队列改成栈就完事了，DFS的优势是可以顺便记录记录一下具体的操作步骤。

### 注意事项
头部加 import java.util.*;
二元组用AbstractMap.simpleEntry代替。

### 代码

```java
import java.util.*;

class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        AbstractMap.SimpleEntry<Integer, Integer> start = new AbstractMap.SimpleEntry<>(0,0);
        Queue<AbstractMap.SimpleEntry<Integer, Integer>> queue = new ArrayDeque<>();
        Set<AbstractMap.SimpleEntry<Integer, Integer>> set = new HashSet<>();
        queue.add(start);
        set.add(start);
        AbstractMap.SimpleEntry<Integer, Integer> entry;
        while (!queue.isEmpty()) {
            entry = queue.poll();
            if (entry.getKey() == z || entry.getValue() == z || entry.getKey() + entry.getValue() == z) {
                return true;
            }
            // 清空x
            AbstractMap.SimpleEntry<Integer, Integer> entry1 = new AbstractMap.SimpleEntry<>(0, entry.getValue());
            if (!set.contains(entry1)) {
                set.add(entry1);
                queue.offer(entry1);
            }
            // 清空y
            AbstractMap.SimpleEntry<Integer, Integer> entry2 = new AbstractMap.SimpleEntry<>(entry.getKey(), 0);
            if (!set.contains(entry2)) {
                set.add(entry2);
                queue.offer(entry2);
            }
            // 装满x
            AbstractMap.SimpleEntry<Integer, Integer> entry3 = new AbstractMap.SimpleEntry<>(x, entry.getValue());
            if (!set.contains(entry3)) {
                set.add(entry3);
                queue.offer(entry3);
            }
            // 装满y
            AbstractMap.SimpleEntry<Integer, Integer> entry4 = new AbstractMap.SimpleEntry<>(entry.getKey(), y);
            if (!set.contains(entry4)) {
                set.add(entry4);
                queue.offer(entry4);
            }
            // y给x倒
            AbstractMap.SimpleEntry<Integer, Integer> entry5;
            if (entry.getKey() + entry.getValue() >= x) {
                entry5 = new AbstractMap.SimpleEntry<>(x, entry.getKey() + entry.getValue() - x);
            } else {
                entry5 = new AbstractMap.SimpleEntry<>(entry.getKey() + entry.getValue(), 0);
            }

            if (!set.contains(entry5)) {
                set.add(entry5);
                queue.offer(entry5);
            }
            // x给y到
            AbstractMap.SimpleEntry<Integer, Integer> entry6;
            if (entry.getKey() + entry.getValue() >= y) {
                entry6 = new AbstractMap.SimpleEntry<>(entry.getKey() + entry.getValue() - y, y);
            } else {
                entry6 = new AbstractMap.SimpleEntry<>(0, entry.getKey() + entry.getValue());
            }
            if (!set.contains(entry6)) {
                set.add(entry6);
                queue.offer(entry6);
            }
        }
        return false;
    }
}
```