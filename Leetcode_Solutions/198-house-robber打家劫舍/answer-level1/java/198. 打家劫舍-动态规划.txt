/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/8/27
 *
 * 解题思路：动态规划 设f(i) 为 从num[i]开始的最优解(不连续数的最大和) f(i) = MAX(f(i + 1) , f(i + 2) + num[i]) 有最优子结构 有重叠子问题 动态规划(自底向上,记忆功能)
 */

```
    public int rob(int[] nums) {
        int length = nums.length;
        int[] max = new int[length + 1];
        for(int i = length - 1; i >= 0; i--){
            if(i == length - 1){
                max[i] = nums[i];
            }else if(i == length - 2){
                max[i] = Math.max(nums[i] , nums[i+1]);
            }else{
                max[i] = Math.max(max[i + 1],max[i+2] + nums[i]);
            }
        }
        return max[0];
    }
```