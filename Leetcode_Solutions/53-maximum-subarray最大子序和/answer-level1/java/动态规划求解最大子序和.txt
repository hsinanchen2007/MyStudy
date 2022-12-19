__# 思路：__
- 动态规划：通过把原问题分解为相对简单的子问题的方式求解复杂问题的方法。动态规划常常适用于有重叠子问题和最优子结构性质的问题。

- 从题目给出例题输入来找规律，我们需要一个head来指向最优解序列的头结点，head指向将不断变化，定义一个最优解数组dp[i]记录截至到当前元素的最优子序和.

- 输入: [-2,1,-3,4,-1,2,1,-5,4],
- 输出: 6
- 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

- 初始化dp[0] = -2
- -2   : dp[0] = -2, head = 0
- 1    :  dp[1] = 1  head = 1
- -3  :  dp[2] = -2  head = 1
- 通过前三项可以总结出规律：dp[i] = max(dp[i-1] + nums[i], nums[i])   如果选中当前项，则更改head指向当前项
- 4  :   dp[3] = max(dp[2] + 4,  4) = max(-2, 4) = 4   head = 3
- -1:    dp[4] = max(dp[3] +-1 , -1) = max(3, -1) = 3  head不变
- 2：  dp[5] = max(5, 2) = 5, head 不变
- 1  :   dp[6] = 6  head不变
- -5 ： dp[7] = 1  head不变
- 4  :   dp[8] = 5   head不变

- 我们只需要其中最大的子序号，遍历一遍dp数组找出最大项dp[i]，并且从 head 到 i 的序列就是最大子序列     
__即动态规划解题方法：__     
1. 分析最优解的结构特征
2. 建立最优值的递归式    
3. 自底向上计算最优值，并记录

- __# 代码：__
```
class Solution {
    public int maxSubArray(int[] nums) {

        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];

        int []dp = new int[nums.length];
        int head = 0;
        dp[0] = nums[0];

        for(int i = 1; i < nums.length; i++){
            dp[i] = Math.max(dp[i-1] + nums[i], nums[i]); //核心代码
            if(dp[i-1] + nums[i] < nums[i])
                head = i;
        }

        int max = dp[0]; //找最大和
        for(int i = 0; i < dp.length; i++){
            if(max < dp[i])
                max = dp[i];
        }
        
        return max;
        
    }
}
```
