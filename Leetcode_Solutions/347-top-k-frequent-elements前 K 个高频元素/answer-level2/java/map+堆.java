### 解题思路
map+堆

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }
        
        Queue<Map.Entry<Integer, Integer>> queue = new PriorityQueue<>(k, new Comparator<Map.Entry<Integer, Integer>>() {
            @Override
            public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
                return o1.getValue() - o2.getValue();
            }
        });
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(queue.size() < k){
                queue.add(entry);
            } else {
                if(queue.peek().getValue() < entry.getValue()){
                    queue.poll();
                    queue.add(entry);
                }
            }
        }
        
        List<Integer> res = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : queue) {
            res.add(entry.getKey());
        }
        return res;
    }
}
```