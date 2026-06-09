官方题解`Python`版本写得很好了，这里用`Java`实现，也是用了一个`Stack`记录所有的可能情况，同时用`HashSet`记录已经处理过的状态。需要注意的是，这里`HashSet`不能直接存储一个`int[]`，可以用`Map.Entry`代替，原因看个简单的例子就懂。
```
// int[]
HashSet<int[]> set = new HashSet<>();
int[] arr = new int[]{1,2};
set.add(arr);
System.out.println(set.contains(new int[]{1,2}));  // false
System.out.println(set.contains(arr));  // true

// Map.Entry
Set<Map.Entry<Integer, Integer>> seenSet = new HashSet<>();
Map.Entry<Integer, Integer> entry = new AbstractMap.SimpleEntry<Integer, Integer>(2,3);
seenSet.add(entry);
System.out.println(seenSet.contains(entry));  // true
System.out.println(seenSet.contains(new AbstractMap.SimpleEntry<Integer, Integer>(2,3)));  // true
```
其他基本和官方题解一样，记得要`import java.util.*`具体代码如下。
```
import java.util.*;
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        Stack<int[]> stack = new Stack<>();  // 存储所有可能的状态
        Set<Map.Entry<Integer, Integer>> seenSet = new HashSet<>();  // 存储处理过的状态
        stack.push(new int[]{0,0});
        while(!stack.isEmpty()) {
            int[] arr = stack.pop();
            if((arr[0] == z) || (arr[1] == z) || (arr[0]+arr[1] == z)) return true;
            Map.Entry<Integer,Integer> currEntry = new AbstractMap.SimpleEntry<>(arr[0], arr[1]);
            if(seenSet.contains(currEntry)) continue;  // 之前处理过这个状态，跳过
            seenSet.add(currEntry);  // 把处理过的这个状态加入到已经处理过的集合内
            stack.add(new int[]{0, arr[1]});  // 倒空x
            stack.add(new int[]{arr[0], 0});  // 倒空y
            stack.add(new int[]{x, arr[1]});  // 加满x
            stack.add(new int[]{arr[0],y});   // 加满y 
            // x往y中倒水
            if(arr[0] + arr[1] < y) stack.add(new int[]{0, arr[0]+arr[1]});  // 如果不会倒满，x空，y是当前两桶水之和
            else stack.add(new int[]{arr[0]+arr[1]-y, y});  // 如果会倒满，x中会有剩余，y满
            // y往x中倒水 
            if(arr[0] + arr[1] < x) stack.add(new int[]{arr[0]+arr[1], 0});  // 如果不会倒满，y空，x是当前两桶水之和
            else stack.add(new int[]{x, arr[0]+arr[1]-x});  // 如果会倒满，y中会有剩余，x满
        }
        return false;  // 没有达到z，桟已空，返回false不可能
    }
}
```
