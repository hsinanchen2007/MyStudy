**1.关注代码的规范性、完整性、鲁棒性。
2.维护一个双向队列(头尾元素可以直接进行操作),用链表实现,队列的头元素为每次存放窗口的最大值(可结合官方题解的动画来看);
3.如果arr为空，直接放入当前下标i;
4.如果arr不为空:（1）如果nums[i] < nums[list.peek()],放入list;（2）如果nums[i] > nums[list.peekLast()]循环弹出队列的元素;
5.记得判断list.peek() == i - k;判断队列的头元素是否有效;
6.完结。**

        public int[] maxSlidingWindow(int[] nums, int k) {
            if (nums == null || nums.length == 0)
                return new int[0];

            int[] arr = new int[nums.length - k + 1];
            LinkedList<Integer> list = new LinkedList<>();

            for (int index = 0, i = 0; i < nums.length; i++) {
                while (!list.isEmpty() && nums[list.peekLast()] < nums[i]) {
                    list.pollLast();
                }
                list.add(i);
                if (list.peek() == i - k) {
                    list.poll();
                }
                if (i >= k - 1) {
                    arr[index++] = nums[list.peek()];
                }
            }
            return arr;
        }