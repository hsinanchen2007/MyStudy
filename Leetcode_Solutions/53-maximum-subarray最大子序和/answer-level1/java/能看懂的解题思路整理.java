### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length == 0){
            return 0 ;
        }
       if (nums.length == 1) {
            return nums[0];
        }
        int max = nums[0];
        int preMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (preMax > 0) {
                preMax += nums[i];
            } else {
                preMax = nums[i];
            }
            max = Math.max(preMax,max);
        }
        return max;

    }


}
```