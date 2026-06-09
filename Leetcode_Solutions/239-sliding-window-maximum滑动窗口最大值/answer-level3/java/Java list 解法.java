```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) return nums;
        LinkedList<Integer> list = new LinkedList<>();
        int[] res = new int[nums.length - k + 1];
        for (int i = 0; i < nums.length; i ++) {
            if (!list.isEmpty() && list.peek() < i - k + 1) {
                list.poll();
            }
            while (!list.isEmpty() && nums[list.peekLast()] <= nums[i]) {
                list.pollLast();
            }
            list.offer(i);
            if (i - k + 1 >= 0) {
                res[i - k + 1] = nums[list.peek()];
            }
        }
        return res;
    }
}
```