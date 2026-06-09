```
class Solution {
    public boolean isPossible(int[] nums) {
        //key: 目标值, value 长度
        HashMap<Integer, PriorityQueue<Integer>> map = new HashMap<>();

        for (int num : nums) {
            PriorityQueue<Integer> queue = map.get(num - 1);
            int value;
            if (queue == null || queue.isEmpty()) {
                value = 1;
            } else {
                value = queue.poll() + 1;
            }
            if (!map.containsKey(num)) {
                map.put(num, new PriorityQueue<>());
            }
            map.get(num).add(value);
        }
        return !map.values().stream().flatMap(Collection::stream).anyMatch(i -> i < 3);
    }
}
```
