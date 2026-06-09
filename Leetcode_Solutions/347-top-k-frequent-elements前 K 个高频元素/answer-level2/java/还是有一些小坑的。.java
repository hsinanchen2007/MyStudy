### 解题思路
1.统计数字频率，自然想到Map
2.Top K 问题，自然想到小顶堆
3.小顶堆里面存的是key，但是排序按value来，所以重写了Comparator方法
4.比较的时候注意是和value比。即：
(Integer) entry.getValue() > map.get(priorityQueue.peek())

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

                PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return map.get(o1) - map.get(o2);
            }
        });
        for (Map.Entry entry : map.entrySet()) {
            if (priorityQueue.size() < k) {
                priorityQueue.add((Integer) entry.getKey());
            } else {
                if ((Integer) entry.getValue() > map.get(priorityQueue.peek())) {
                    priorityQueue.poll();
                    priorityQueue.add((Integer) entry.getKey());
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        while (!priorityQueue.isEmpty()) {
            list.add(priorityQueue.poll());
        }
        return list;
    }
}
```