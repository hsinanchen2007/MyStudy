### 解题思路
核心思想在于K个和的计算，没必要每次全加一遍，只需关注进来的和出去的差。

### 代码

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        long sum = 0;
        long maxSum = 0;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            queue.add(nums[i]);
            sum += nums[i];
        }
        maxSum = sum;
        for (int i = k; i < nums.length; i++) {
            int leave = queue.peek();
            int come = nums[i];
            maxSum = Math.max(maxSum, sum + (come - leave));
            queue.poll();
            queue.add(come);
            sum = sum + (come - leave);
        }
        return (double) maxSum / k;
    }
}
```