使用java的优先队列实现，维护一个k大小的大顶堆。

```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null || nums.length < 2) return nums;
        int[] result = new int[nums.length - k + 1];
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            maxHeap.offer(nums[i]);
            if(i >= k - 1 || i == nums.length - 1){
                result[count ++] = maxHeap.peek();
                // 将窗口最后的数据出堆
                maxHeap.remove(nums[i - (k - 1)]);
            }

        }
        return result;
    }
}
```
