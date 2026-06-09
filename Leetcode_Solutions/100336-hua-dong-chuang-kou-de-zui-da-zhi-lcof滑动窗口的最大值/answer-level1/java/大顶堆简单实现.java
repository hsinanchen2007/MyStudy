### 解题思路
利用大顶堆的peek()是最大值，remove(num)可以直接去除num元素，每一轮去掉一个数，再添加一个数，将当前peek添加到结果中

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 0)
            return new int[0];

        PriorityQueue<Integer> queue = new PriorityQueue<Integer>((a, b) -> b - a);
        for (int i = 0; i < k; i++){
            queue.add(nums[i]);
        }

        int[] res = new int[nums.length - k + 1];
        int j = 0;
        res[j++] = queue.peek();

        for (int i = k; i < nums.length; i++){
            queue.remove(nums[i - k]);
            queue.add(nums[i]);
            res[j++] = queue.peek();
        }

        return res;
    }
}
```