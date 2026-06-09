### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Map.Entry;

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            Integer count = map.get(num);
            map.put(num, (count != null) ? count + 1 : 1);
        }
        PriorityQueue<Entry<Integer, Integer>> queue = new PriorityQueue<>(k, new Comparator<Entry<Integer, Integer>>() {
            @Override
            public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });
        for (Entry<Integer, Integer> entry : map.entrySet()) {
            if (queue.size() < k) {
                queue.offer(entry);
            } else if (entry.getValue() > queue.peek().getValue()) {
                queue.poll();
                queue.offer(entry);
            }
        }
        List<Integer> ans = new LinkedList<>();
        while (queue.size() > 0) {
            ans.add(0, queue.poll().getKey());
        }
        return ans;
    }
}
```