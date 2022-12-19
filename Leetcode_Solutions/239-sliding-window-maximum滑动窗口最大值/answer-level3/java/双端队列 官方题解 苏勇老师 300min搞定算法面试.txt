思路同官方题解, 晒一下Java代码, 都是坑

```

    public int[] maxSlidingWindow(int[] nums, int k) {

        int nums_length = nums.length;
        if (1 >= nums_length || 1 == k)
            return nums;

        int ans_length = nums_length-k+1;
        int [] ans = new int[ans_length];

        Deque<Integer> deque = new LinkedList<Integer>();
        //用来存窗口中最大值的数组下标
        int indexOfMaxNum = -1;

        for (int i = 0; i < nums_length; i++) {

            if (deque.isEmpty()) {
                deque.addLast(i);
                indexOfMaxNum = deque.getFirst();
            }

            //注意这里是>= 遇到相等的最大值也需要更新双端队列
            if (!deque.isEmpty() && nums[i] >= nums[indexOfMaxNum]) {
                deque.clear();
                deque.addLast(i);
                indexOfMaxNum = deque.getFirst();
            }

            if (!deque.isEmpty() && nums[i] < nums[indexOfMaxNum]) {

                //滑动窗口, 需要先移除头部最大值, 再做操作
                if (i-indexOfMaxNum>=k) {
                    deque.removeFirst();
                }

                while (!deque.isEmpty() && nums[i] > nums[deque.getLast()]) {
                    deque.removeLast();
                }

                deque.addLast(i);
                indexOfMaxNum = deque.getFirst();
            }

            //这个地方要小心
            int index = i<k ? 0 : i-k+1;
            ans[index] = nums[indexOfMaxNum];
        }

        return ans;
    }
```
