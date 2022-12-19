## 排序
```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums)
            map.put(i, map.getOrDefault(i, 0) + 1);
        List<Integer> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (o1, o2) -> map.get(o2) - map.get(o1));
        return list.subList(0, k);
    }
}
```
时间复杂度：O(nlogn)
空间复杂度：O(n)

## 优先队列
```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums)
            map.put(i, map.getOrDefault(i, 0) + 1);
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> 
            map.get(o1) - map.get(o2));
        for (int i : map.keySet()) {
            pq.offer(i);
            if (pq.size() > k) pq.poll();
        }
        List<Integer> list = new ArrayList<>();
        while (!pq.isEmpty()) list.add(pq.poll());
        Collections.reverse(list);
        return list;        
    }
}
```
时间复杂度：O(nlogk)
空间复杂度：O(n)