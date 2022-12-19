### 解题思路
# 递归思路
- 首先确定特殊情况 `nums.length == 0` 的情况，直接返回0
- 递归函数，需要确定终止条件，在确定前两个和第一个的最大值
- 最后返回 `Math.max(digui(nums,num-2) + nums[num-1], digui(nums, num-1))`
### 代码
```java
    public int rob(int[] nums) {
        if(nums.length == 0) 
            return 0;
        return digui(nums, nums.length);
        
    }

    public int digui(int[] nums,int num) {
        if(num == 1)
            return nums[0];
        if(num == 2)
            return Math.max(nums[0], nums[1]);
        return Math.max(digui(nums,num-2) + nums[num-1], digui(nums, num-1));

    }
```
# 动态规划
- 确定特殊情况 `nums.length == 0` 返回0 和 `nums.length == 1` 返回第一个值
- 当 `nums.length >= 2` 时，注意事先确定前两个中最大数，这里不用再次申请一个 dp 数组用来存储，直接采用 int[] nums ，前 n 个最大值等于 `nums[i] = Math.max(nums[i]+ nums[i-2], nums[i-1]);`

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0 || nums == null)
            return 0;
        if(nums.length == 1)
            return nums[0];
        // find max of first two numbers
        nums[1] = Math.max(nums[0],nums[1]);
        for(int i = 2; i<nums.length; i++) {
            nums[i] = Math.max(nums[i]+ nums[i-2], nums[i-1]);
        }

        return nums[nums.length-1];
    }
}
```