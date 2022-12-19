### 解题思路
此处撰写解题思路
直接考虑环形的比较复杂，可以拆成两个不是环形的数组，有以下两种情况，如果打劫第一个则不能打劫最后一个，如果打劫最后一个则不能打劫第一个。
### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        return Math.max(myRob(Arrays.copyOfRange(nums, 0, nums.length - 1)),
                myRob(Arrays.copyOfRange(nums, 1, nums.length)));
    }
    private int myRob(int[] nums) {
        //dp0为不接受，dp1为接受
        int dp0 = 0, dp1 = nums[0];
        int n = nums.length;
        for(int i = 1; i < n; i++){
            int t0 = Math.max(dp0,dp1);
            int t1 = dp0 + nums[i];
            dp0 = t0;
            dp1 = t1;
        }
        return Math.max(dp0,dp1);
    }
}
```