### 解题思路
1. 参考官方题解

### 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        if(tasks == null || tasks.length == 0) return 0;
        if(n == 0) return tasks.length;

        int[] nums = new int[26];
        for(char task : tasks) nums[task - 'A'] += 1;
        Arrays.sort(nums);
        int max_val = nums[25] - 1, idle_slots = max_val * n;
        for (int i = 24; i >= 0 && nums[i] > 0; i--) {
            idle_slots -= Math.min(nums[i], max_val);
        }
        return idle_slots > 0 ? idle_slots + tasks.length : tasks.length;

    }
}
```