当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？它只有两种 选择：
1、加入之前的SubArray；
2. 自己另起一个SubArray。

那什么时候会出现这两种情况呢？ 
如果之前SubArray的总体和大于0的话，我们认为其对后续结果是有贡献的。这种情况下我们 选择加入之前的SubArray 
如果之前SubArray的总体和为0或者小于0的话，我们认为其对后续结果是没有贡献，甚至是 有害的（小于0时）。这种情况下我们选择以这个数字开始，另起一个SubArray。 

设状态为 f[j]，表示以 S[j] 结尾的最大连续子序列和，则状态转移方程如下： 
f[j] = max{f[j −1] + S[j],S[j]}, 其中1 ≤ j ≤ n target = max{f[j]}, 其中1 ≤ j ≤ n 

解释如下： 
• 情况一，S[j] 不独立，与前面的某些数组成一个连续子序列，则最大连续子序列和为 f[j −1] + S[j]。 
• 情况二，S[j] 独立划分成为一段，即连续子序列仅包含一个数 S[j]，则最大连续子序列和为 S[j]。 


public class Solution {
    public int MaxSubArray(int[] nums) {
          var sum = 0;
            var result = int.MinValue;
            for (int i =  0; i< nums.Length; i++)
            {
                if (sum + nums[i] > nums[i])  // means before this number the sum is >0 we can use it, otherwise we just use current number
                {
                    sum += nums[i];
                }
                else
                {
                    sum = nums[i]; // otherwise we just use current number
                }

                result = sum > result ? sum : result; // save current number or sum value
            }

            return result;
        }
}