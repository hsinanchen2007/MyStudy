### 解题思路
难得有个双百，上备忘录
动态规划的核心：备忘录！！！加了之后速度上天！！！

### 代码

```cpp
#define max(x,y) x>y?x:y
class Solution {
public:
	int massage(vector<int>& nums) {
		const int sizeN = nums.size();
		//备忘录
		int* memo = new int[sizeN + 1];
		for (size_t i = 0; i < sizeN + 1; i++)
		{
			memo[i] = -1;
		}
		//如果nums为空
		if (sizeN == 0)
			return 0;
		//如果nums长度为1
		if (sizeN == 1)
			return nums[0];
		//如果nums长度为2
		if (sizeN == 2)
			return max(nums[0], nums[1]);
		//如果大于3，遍历解决
		int r0 = bestResult(nums, 0, sizeN, memo);
		int r1 = max(bestResult(nums, 1, sizeN, memo), bestResult(nums, 2, sizeN, memo));
		return max(r0, r1);
	}
	//动态规划，求最优子解
	int bestResult(const vector<int>& nums, int index, const int sizeN, int* memo) {
		if (memo[index] >= 0)
			return memo[index];
		if (index >= sizeN) {
			memo[index] = 0;
			return 0;
		}
		if (index == sizeN - 1) {
			memo[index] = nums.back();
			return memo[index];
		}
		if (index == sizeN - 2) {
			memo[index] = max(nums[index], nums[index + 1]);
			return memo[index];
		}
		memo[index] = max((nums[index] + bestResult(nums, index + 2, sizeN, memo)), (nums[index] + bestResult(nums, index + 3, sizeN, memo)));
		return memo[index];
	}
};
```