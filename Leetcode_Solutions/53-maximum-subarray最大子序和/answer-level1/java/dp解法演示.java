### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE; 
        int currentSum = 0;
        for(int i = 0; i < nums.length; i++) {
            currentSum = currentSum <= 0 ? nums[i]: currentSum + nums[i];
            if(currentSum > maxSum) maxSum = currentSum; 
        }

        return maxSum;
    }
}
```