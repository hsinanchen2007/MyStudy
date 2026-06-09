/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/27
 *
 * 解题思路: 找出最小的两个值min_A min_B 和 最大的三个值max_A max_B max_C
 * 取 min_A*min_B*max_C 和 max_A*max_B*max_C 的最大值
 *
 */
```
public int maximumProduct(int[] nums) {
    Arrays.sort(nums);
    return Math.max(nums[0]*nums[1]*nums[nums.length - 1],nums[nums.length - 1]*nums[nums.length - 2]*nums[nums.length - 3]);
}
```