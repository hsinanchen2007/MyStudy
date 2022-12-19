### 解题思路
几个点：只能减少，不能增加；
如果没有该限制，贪心做法是修改当前的数而不是修改上一个数；比如[5,6,6],要让该数组呈减增态，第一步将6减少为4比将5变成7更优；

但是有了递减的规定，在当前需要增加时，只能减少之前的数；而当前需要递减的场景不用变化。

### 代码

```cpp
class Solution {
public:
int GetMinSum(vector<int> nums, int flag)
{
	int results = 0;
	for (int i = 1; i < nums.size(); i++) {
		if (flag == 1) {
			if (nums[i] <= nums[i - 1]) {
				results += nums[i - 1] + 1 - nums[i];
			} 
		} else {
			if (nums[i] >= nums[i - 1]) {
				results += nums[i] - nums[i - 1] + 1;
				nums[i] = nums[i - 1] - 1;
			}
		}
		flag = flag ^ 1;
	}
	return results;
}

int movesToMakeZigzag(vector<int>& nums) {
	if (nums.size() <= 1) {
		return 0;
	}
	int flag = 0;
	return min(GetMinSum(nums, flag), GetMinSum(nums, flag ^ 1));
}
};
```