### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k == 0 )
            return new int[0];
        int[] res = new int[nums.length - k + 1];
        PriorityQueue<Integer> priorityQueue = 
                new PriorityQueue<>((o1, o2) -> (o2-o1));
        int max = nums[0];
        priorityQueue.add(nums[0]);
        int slow = 0 , fast = 1;
        for ( ; fast < k ; fast++){
            priorityQueue.add(nums[fast]);
            max = max > nums[fast] ? max : nums[fast];
        }
        res[0] = priorityQueue.peek();
        for ( ;fast < nums.length ; fast++ ){
            priorityQueue.remove(nums[slow]);
            priorityQueue.add(nums[fast]);
            res[++slow] = priorityQueue.peek();
        }
        return res;
    }
}
```