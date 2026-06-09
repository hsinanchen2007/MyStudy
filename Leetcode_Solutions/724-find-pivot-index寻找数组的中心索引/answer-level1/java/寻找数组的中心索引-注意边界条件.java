
执行用时：1 ms，击败100% java
内存消耗：42.1 MB，击败30.42% java

这题需要理解清楚题意，再开始做，然后要注意边界条件。比如nums的长度有约定可能是0，但没有说当中心索引是0或nums.length-1时，左侧或右侧元素之和到底算不算，算的话是假定为0吗？
边界问题需要确认清楚。

我的方法中规中矩，分别记录了左边的和、右边的和。
也可以通过灵活变换计算公式优化，比如，当左右和相等时，sum = 2*leftSum + nums[i]，这样只要计算一个动态变化的变量leftSum.

``` java
class Solution {
    // nums = [1, 7, 2, 6, 5, 6]
    public int pivotIndex(int[] nums) {
        if(nums == null || nums.length < 3) {
            return -1;
        }
        
        int pointer = nums.length - 1;
        int leftSum = 0, rightSum = 0;
        while (pointer > 0) {
            rightSum += nums[pointer];
            pointer --;
        }
        
        // start from pointer = 0
        while (leftSum != rightSum && pointer < nums.length - 1) {
            leftSum += nums[pointer];
            pointer++;
            rightSum -= nums[pointer];
        }
        
        if (leftSum == rightSum) {
            return pointer;
        } else {
            return -1;
        }
        
    }
}
```



【附：原题】
给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。

我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。

如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。

示例 1:

输入: 
nums = [1, 7, 3, 6, 5, 6]
输出: 3
解释: 
索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
同时, 3 也是第一个符合要求的中心索引。
示例 2:

输入: 
nums = [1, 2, 3]
输出: -1
解释: 
数组中不存在满足此条件的中心索引。
说明:

nums 的长度范围为 [0, 10000]。
任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。