### 解题思路
由于正负号因素，同时记录以i为结尾的子数组最大乘积和最小乘积

### 代码

```java
class Solution {
    public int maxProduct(int[] nums) {
        //以i结尾的子数组最大乘积
        int[] dpMax = new int[nums.length];
        //以i结尾的子数组最小乘积
        int[] dpMin = new int[nums.length];
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int res = Integer.MIN_VALUE;
        for (int i = 1; i < nums.length; i++) {
            dpMax[i] = Math.max(Math.max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]), nums[i]);
            dpMin[i] = Math.min(Math.min(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]), nums[i]);
            res = Math.max(res, dpMax[i]);
        }
        return Math.max(res, dpMax[0]);
    }
}
```