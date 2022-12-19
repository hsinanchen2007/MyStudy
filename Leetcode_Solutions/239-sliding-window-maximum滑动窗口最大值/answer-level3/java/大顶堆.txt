### 解题思路
用一个大顶堆，每次拿堆顶元素

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
         if (k == 0 || nums.length == 0) {
            return nums;
        }
        PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        for (int i = 0; i < k; i++) {
            priorityQueue.add(nums[i]);
        }

        int[] results = new int[nums.length - k + 1];
        int index = 0;
        for (int i = k; i < nums.length; i++) {
            int max = priorityQueue.peek();
            priorityQueue.remove(nums[i - k]);
            priorityQueue.add(nums[i]);
            results[index++] = max;
        }
        results[index] = priorityQueue.peek();
        return results;
    }
}
```