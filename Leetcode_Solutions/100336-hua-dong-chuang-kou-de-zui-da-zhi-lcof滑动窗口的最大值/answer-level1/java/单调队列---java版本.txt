这是典型的单调队列问题，利用单调队列求 k 个数的最大值或者最小值，能使得时间复杂度降到最低，因为进队出队仅需 O(1) 的时间复杂度。
顺便啰嗦一句，其实单调队列在多重背包问题中也有用到，有兴趣的朋友可以关注一下dd大牛的背包九讲，讲的挺好！
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
         if(nums == null || nums.length < 2) return nums;
        // 双向队列 保存当前窗口最大值的数组位置 保证队列中数组位置的数值按从大到小排序
        LinkedList<Integer> queue = new LinkedList();
        // 结果数组
        int[] result = new int[nums.length-k+1];
        // 遍历nums数组
        for(int i = 0;i < nums.length;i++){
            // 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
            while(!queue.isEmpty() && nums[queue.peekLast()] <= nums[i]){
                queue.pollLast();
            }
            // 11 10 9 8 7 6 5
            // 判断当前队列中队首的值是否有效
            if(!queue.isEmpty() && queue.peek() <= i-k){
                queue.poll();
            }
            // 添加当前值对应的数组下标
            queue.addLast(i);
            // 当窗口长度第一次达到k后，开始保存当前窗口中最大值
            // 以后每走一步，就会保存一个最大值
            if(i+1 >= k){
                result[i+1-k] = nums[queue.peek()];
            }
        }
        return result;
    }
}
```
