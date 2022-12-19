```
public int[] maxSlidingWindow(int[] nums, int k) {
    if (nums == null || nums.length == 0) {
        return nums;
    }
    int[] result = new int[nums.length - k + 1];
    int index = 0, i;
    LinkedList<Integer> list = new LinkedList<>();
    for (i = 0; i < nums.length; i ++) {
        if (i > k - 1) {
            list.pollFirst();
        }
        while (list.size() != 0 && nums[i] > list.peekLast()) {
            list.pollLast();
        }
        while (list.size() < Math.min(i + 1, k)) {
            list.addLast(nums[i]);
        }
        if (i > k - 2) {
            result[index ++] = list.peekFirst();
        }
    }
    return result;
}
```
