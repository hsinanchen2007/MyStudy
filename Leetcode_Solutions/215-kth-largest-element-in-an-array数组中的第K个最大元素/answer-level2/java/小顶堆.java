### 代码

```java
class Solution {
    public int findKthLargest(int[] nums, int k) {
         // 小顶堆
         PriorityQueue<Integer> queue = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1-o2;
            }
        });

         for (int i = 0; i < k; ++i) {
            queue.offer(nums[i]);
        }

        for (int i = k; i < nums.length; ++i) {
            if (nums[i] > queue.peek()) {
                queue.poll();
                queue.offer(nums[i]);
            }
        }
        
        return queue.peek();
    }
}
```