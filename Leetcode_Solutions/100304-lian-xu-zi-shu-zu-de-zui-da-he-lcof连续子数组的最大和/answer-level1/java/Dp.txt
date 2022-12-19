### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int curSum = nums[0];
        int maxSum = nums[0];
        for(int i=1;i < nums.length;i++){
            curSum = Math.max(nums[i],nums[i]+curSum);
            maxSum = Math.max(curSum,maxSum);
        }
        return maxSum;
    }
}
```