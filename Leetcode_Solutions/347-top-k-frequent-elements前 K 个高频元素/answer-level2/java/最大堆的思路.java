### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.merge(num, 1, Integer::sum);
        }
        //取前k个value最大的
        int cnt=0;
        //最大堆
        PriorityQueue<Integer> queue = new PriorityQueue(Collections.reverseOrder());
        for (Integer value : counts.values()) {
            queue.offer(value);
        }
        HashSet<Integer> result = new HashSet<>(k);
        for (int i = 0; i < k; i++) {
            Integer peek = queue.peek();
            queue.remove();
            for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
                if (entry.getValue().equals(peek)){
                    result.add(entry.getKey());
                }
            }
        }
        return new ArrayList<>(result);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.topKFrequent(new int[]{1,2},2));
    }
}
```