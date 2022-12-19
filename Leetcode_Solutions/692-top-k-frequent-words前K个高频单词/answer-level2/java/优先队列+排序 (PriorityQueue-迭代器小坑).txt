**对单词进行统计得到数据对<string, int>，最后根据int排序**
## 排序
```
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for (String i : words) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        List<String> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (o1, o2) -> map.get(o1).equals(map.get(o2)) ?
        o1.compareTo(o2) : map.get(o2) - map.get(o1));
        return list.subList(0, k);
    }
}
```
时间复杂度O(nlogn), 空间O(n)
## 优先队列
**注意: 优先队列的迭代器访问不保证有序，因此最后输出需要注意不能用迭代器**
```
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for (String i : words) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        PriorityQueue<String> pq = new PriorityQueue<>((o1, o2) -> 
            map.get(o1).equals(map.get(o2)) ? o2.compareTo(o1) : map.get(o1) - map.get(o2));
        for (String i : map.keySet()) {
            pq.offer(i);
            if (pq.size() > k) pq.poll();
        }
        List<String> result = new ArrayList<>();
        while (!pq.isEmpty()) result.add(pq.poll());
        Collections.reverse(result);
        return result;
    }
}
```
时间复杂度：O(nlogk)
空间复杂度：O(n)

