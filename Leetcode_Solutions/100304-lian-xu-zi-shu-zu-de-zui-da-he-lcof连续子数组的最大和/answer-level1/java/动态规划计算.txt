### 解题思路


### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums == null || nums.length ==0){
            return 0;
        }
        if(nums.length ==1){
            return nums[0];
        }
        int max = Integer.MIN_VALUE;
        int cur = 0;
        for(int num : nums){
            cur += num;
            max = Math.max(max, cur);
            cur = Math.max(0, cur);
        }
        return max;
    }
}
```