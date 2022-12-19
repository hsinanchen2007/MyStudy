

代码1：
![image.png](https://pic.leetcode-cn.com/820747a2efaade798a870412e6139e30850afe8dfed53231ee53d5708883db71-image.png)


```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (Integer i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((o1, o2) -> o2.getValue().compareTo(o1.getValue()));
        pq.addAll(map.entrySet());
        List<Integer> list = new LinkedList<>();

        for (int i=0;i<k;i++){
            list.add(pq.poll().getKey());
        }
        return list;
    }
}
```
代码2：
![image.png](https://pic.leetcode-cn.com/7d127ad567f857c808bb5ebf313ef30571c6272531ec451e8db005a0e232b41c-image.png)

```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
                Map<Integer, Integer> map = new HashMap<>();
        for (Integer i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        List<Map.Entry<Integer,Integer>> list = new ArrayList<>();
        list.addAll(map.entrySet());
        Collections.sort(list,(o1,o2)->o2.getValue().compareTo(o1.getValue()));
        List<Integer> list1 = new LinkedList<>();

        for (int i=0;i<k;i++){
            list1.add(list.get(i).getKey());
        }
        return list1;
    }
}
```
