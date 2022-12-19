### 解题思路
参考自
[@jyd](/u/jyd/)

环状排列意味着第一个房子和最后一个房子只能选择一个偷窃，因此可以把此环装排列房间问题简化成为两个单排排列房间子问题：
1.在不偷窃第一个房子的情况下(即nums[1:])，最大金额是p1；
2.在不偷窃最后一个房子的情况下(即nums[:n-1])，最大金额是p2；

综合偷窃最大金额：为以上情况的较大值,即max(p1,p2);
因此问题转换为解决两个单排排列房间问题。
自己分别写了两份代码，第一份是直接利用198.打家劫舍的版代码复制了其中一些内容完成的。时间复杂度O(n)，空间复杂度O(1)
第二份代码，参考了[krahets的题解](https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/)进行了优化和修改，
时间复杂度O(n),空间复杂度O(1)


### 代码

#### 未简化版代码

dp[i]：表示为盗窃到第i个房间获得的最大值
由于不可以在相邻的房屋闯入,所以在当前位置i房屋可盗窃的最大值，要么就是i-1房屋可盗窃的最大值，要么就是
i-2房屋可盗窃的最大值加上当前房屋的值，二者之前取最大值
dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
```cpp

class Solution {
public:
	int rob(vector<int>& nums) {
		int sizeNums = nums.size();
		//对size==0、1、2时的特殊判断
		if (sizeNums == 0||sizeNums==1||sizeNums==2) return 0;
		//dp数组
		vector<int> dp(nums.size() + 1);
		//边界值
		dp[1] = nums[0];//第1个房屋可盗窃的最大值
		dp[2] = max(nums[1], dp[1]);//第2个房屋可盗窃的最大值
		//状态转移
		//偷1房间不偷n房间
		for (int i = 3; i < nums.size() + 1; i++)
		{
			if (i != nums.size())
				dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
			else dp[i] = dp[i - 1];
		}
		int maxOne = dp[nums.size()];
		//偷n房间，不偷1房间
		dp[2] = nums[1];
		dp[3] = max(nums[2], dp[2]);
		for (int i = 4; i < nums.size() + 1; i++)
		{
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		}
		return max(maxOne, dp[nums.size()]);
	}
};
```
#### 简化版代码
dp[i]=max(dp[i-2]+num[i],dp[i-1])
pre对应的是前dp[i-2];
cur对应dp[i-1]，也对应着dp[i]
在该式cur=max(pre + num, cur)中，cur在左侧充当dp[i]，在右侧充当dp[i-1]
```cpp
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		return max(myRob(vector<int>(nums.begin(), nums.end() - 1)), myRob(vector<int>(nums.begin() + 1, nums.end())));
	}
private:
	int myRob(vector<int> nums) {
		int pre = 0, cur = 0, tmp;
		for (auto num : nums)
		{
			tmp = cur;
			cur = max(pre + num, cur);
			pre = tmp;
		}
		return cur;
	}
};
```