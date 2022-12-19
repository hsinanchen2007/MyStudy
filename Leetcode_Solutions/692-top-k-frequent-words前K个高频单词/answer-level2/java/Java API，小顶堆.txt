### 解题思路
相同频次时，字母序小的输出在前，输出在前表示要频次更高，
所以字母小的看作大值

### 代码

```java
import java.util.*;
import java.util.Map.Entry;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        // 频率表
        HashMap<String, Integer> map = new HashMap<>();
        for (String w: words) {
            map.put(w, map.getOrDefault(w, 0) + 1);
        }
        // 最小堆
        PriorityQueue<String> minHeap = new PriorityQueue<>(k, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                int ans = map.get(o1) - map.get(o2);
                if (ans == 0) {
                    // 相同频次时，字母序小的输出在前，输出在前表示要频次更高，
                    // 所以字母小的看作大值
                    return o2.compareTo(o1);
                }
                return ans;
            }
        });
        // 遍历频率表，把key放入堆，完毕后的堆内元素就是最大的元素
        for (String key : map.keySet()) {
            minHeap.offer(key);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
            //System.out.println(key + " -> " + minHeap);
        }
        // 输出
        List<String> ans = new LinkedList<>();
        while (!minHeap.isEmpty()) {
            ans.add(0, minHeap.poll());
        }
        return ans;
    }
}
```