### 解题思路
先用hashmap计数，O(n)，然后minheap筛选，堆最大深度为k+1，n*log(k+1)，总时间复杂度 n*log(k+1)

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {

        List<Integer> result = new LinkedList<>();
        Map<Integer, Integer> count = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<>((o1, o2) -> o1.getValue() - o2.getValue());

        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        for (Map.Entry entry : count.entrySet()) {
            minHeap.add(entry);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }
        while (minHeap.size() > 0) {
            result.add(minHeap.poll().getKey());
        }
        Collections.reverse(result); // minheap出来是递增序的，反转成递减序

        return result;
    }
}
```