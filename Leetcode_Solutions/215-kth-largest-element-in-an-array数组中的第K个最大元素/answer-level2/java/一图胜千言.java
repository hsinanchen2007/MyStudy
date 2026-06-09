```
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            if (heap.size() < k) {
                heap.add(nums[i]);
            } else if (nums[i] > heap.peek()) {
                heap.remove();
                heap.add(nums[i]);
            }
        }
        return heap.peek();

    }
}
```

![image.png](https://pic.leetcode-cn.com/173cb725ab22ca40ee0757ea5dce9a3a5d37ad1e9810040a71ac2e3266eb64c5-image.png)
