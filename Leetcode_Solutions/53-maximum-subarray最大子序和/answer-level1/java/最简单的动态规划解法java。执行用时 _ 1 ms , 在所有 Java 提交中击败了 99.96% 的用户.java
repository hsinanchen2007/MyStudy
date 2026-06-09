### 解题思路

        动态规划：
        一：状态
          dp[i]表示包含第i个数的前i个数中连续最大和。
        二：转移状态方程：
          包含第i个数的连续最大和我们知道有
          dp[i] = max(dp[i-1] + nums[i],nums[i])
### 代码
![image.png](https://pic.leetcode-cn.com/fc1f1745bc2fda29bf6b75d963b2ac3bfccaed20b56910d4872863a31089e271-image.png)

不知道为啥粘贴代码会错位。。。
```
class Solution {
    public int maxSubArray(int[] nums) {
    	int length = nums.length;                        //记录数组长  	
		int[] dp = nums;                                 //生成同样长度的dp数组
		int max = dp[0];                                 //在计算dp的同时记录最大值，省的最后再算一遍dp数组中的最大数
		for(int i = 1; i < length; i++)                  //遍历nums
		{
			dp[i] = Math.max(dp[i-1] + nums[i], nums[i]);//转移状态方程
            max = dp[i] > max ? dp[i]:max;               //更新最大值
		}	
    	return max;                                      //返回结果
    }
}
```
