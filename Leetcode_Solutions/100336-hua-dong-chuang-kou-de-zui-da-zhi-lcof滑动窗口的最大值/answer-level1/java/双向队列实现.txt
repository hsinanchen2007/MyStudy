### 解题思路
此处撰写解题思路
双向队列
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (null == nums || nums.length == 0 || k > nums.length ) {
            return new int[0];
        }
        Deque<Integer> deque = new ArrayDeque<>();
        int index = 0;
        int[] results = new int[nums.length - k +1];
        for (int i = 0; i< nums.length; i++) {
            // 比i之前的小数全部弹出，留i及大于i的数
            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
                deque.pollLast();
            }
            deque.addLast(i);
            // 如果队列的最大值不在窗口内，则弹出
            while (deque.peekFirst() < i - k + 1) {
                deque.pollFirst();
            }
            // 判断当前是不是已经到窗口的最后一个值
            if (i >= k - 1) {
                results[index++] = nums[deque.peekFirst()];
            }
        }
        return results;
    }
}
```