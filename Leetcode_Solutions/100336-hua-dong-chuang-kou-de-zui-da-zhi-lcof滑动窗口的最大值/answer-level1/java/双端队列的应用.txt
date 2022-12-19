### 解题思路
本题采用双端队列来进行辅助求解。队列中存放的是nums数组中的index
该队列确保，队列的头部位置，存放的是当前滑动窗口的最大值所对应的index。
队列中的数据按照如下方式进行存取。

当队列中要加入的那个数字的index大于k，且index-k要大于等于队列头部的元素。
	则需要将队列头部的数字移除，因为这个时候滑动窗口已经滑过了队列头部数字所对应的值了。
当队列不为空，且队列中要加入的那个数大于队尾所对应的数字，则应当将队尾的数移除队列，
	直到队尾的数不大于要加入的数，或者队列为空。
将要加入的数的index加入到队列中。
判断，当i>=k-1的时候，开始将队列头部的数，作为当前滑动窗口最大值所对应于nums数组中的值，记录到result数组中去。
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums==null || nums.length==0 || k<=0){
            return new int[0];
        }
        int[] result = new int[nums.length-k+1];
        Deque<Integer> queue = new ArrayDeque<>();
        for(int i=0; i<nums.length; i++){
            if(i>=k && queue.peekFirst()<=i-k){
                queue.pollFirst();
            }
            while(!queue.isEmpty() && nums[queue.peekLast()]<nums[i]){
                queue.pollLast();
            }
            queue.add(i);
            if(i>=k-1){
                result[i-k+1] = nums[queue.peekFirst()];
            }
        }
        return result;
    }
}
```