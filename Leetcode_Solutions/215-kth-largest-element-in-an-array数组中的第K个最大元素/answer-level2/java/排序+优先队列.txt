## 排序
```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
}
```
时间复杂度：nlogn
空间复杂度：n
## 优先队列
```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i : nums) {
            pq.offer(i);
            if (pq.size() > k) pq.poll();
        }
        return pq.peek();
    }
}
```
时间复杂度：nlogk
空间复杂度：n