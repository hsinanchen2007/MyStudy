# 全排序思路(不符合`O(nlogk)`)
最朴素的思路，充分利用内置函数。

```java [-4行代码(易读)]
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Long> map = Arrays.stream(words).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        ArrayList<String> list = new ArrayList<>(map.keySet());
        Collections.sort(list, (a, b) -> (int) (map.get(a) == map.get(b) ? a.compareTo(b) : map.get(b) - map.get(a)));
        return list.subList(0, k);
    }
}
```
```java [-2行代码(略显抽象)]
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Long> map = Arrays.stream(words).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        return map.keySet().stream().sorted((a, b) -> (int) (map.get(a) == map.get(b) ? a.compareTo(b) : map.get(b) - map.get(a))).limit(k).collect(Collectors.toList());
    }
}
```


# 最小堆(符合`O(nlogk)`)
```java [-Java]
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Long> map = Arrays.stream(words).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        PriorityQueue<String> pQueue = new PriorityQueue<>(k, (a, b) -> (int) (map.get(a) == map.get(b) ? b.compareTo(a) : map.get(a) - map.get(b)));
        for (String str : map.keySet()) {
            pQueue.offer(str);
            if (pQueue.size() > k)
                pQueue.poll();
        }
        String[] res = new String[k];
        for (int i = k - 1; i > -1; --i)
            res[i] = pQueue.poll();
        return Arrays.asList(res);
    }
}
```
