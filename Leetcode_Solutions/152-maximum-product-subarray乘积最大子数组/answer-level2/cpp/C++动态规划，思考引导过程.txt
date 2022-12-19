### 解题思路
最直接的想法，dp[i][j]为第i到第j元素能形成的子数组最大乘积，但是这么设发现递归式无法表示，因为要满足连续的话，子数组不一定包含i或j
这种表示造成的困难在于i、j并无法确定连续子数组的位置，所以我们希望dp的下标能够包含连续子数组的位置，以便推导递归式

那去掉一个维度，重新把dp[i]理解为以第i个元素结尾的子数组最大乘积（其实2维情况加个限制，即dp[i][j]表示以i开头j结尾的子数组最大乘积也可以，只不过后面发现2个维度是多此一举的，因为有很多情况是dp[i][i]、dp[j][j]这种）
那dp[i]:
 如果nums[i]>0，那希望dp[i-1]是正的，dp[i]就直接用dp[i-1]×nums[i]
 如果nums[i]<0，那希望dp[i-1]是负的，dp[i]也直接dp[i-1]×nums[i]
 如果nums[i]==0，那dp[i]=0（因为以第i元素结尾，必须包含第i元素）
按照这个思路，看来应该维护两个dp：dpMax和dpMin，以便应对nums不同符号的情况

但还要注意一点，虽然我们希望dp[i-1]×nums[i]变得更大，但也不是总能满足（例如nums=[-1, 2]），如果不能满足的话，那dp[i]只好取nums[i]，表示以i结尾的子数组就只有第i这么一个元素。

综合来看:
 dpMax[i] = nums[i] > 0 ? max(dpMax[i-1]×nums[i], nums[i]) : max(dpMin[i-1]×nums[i], nums[i])
 dpMin[i] = nums[i] > 0 ? min(dpMin[i-1]×nums[i], nums[i]) : min(dpMax[i-1]×nums[i], nums[i])
 dpMax[i] = dpMin[i] = 0 , nums[i] == 0 

### 代码

```cpp
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		vector<int> dpMax, dpMin;
		int size = nums.size(), result;

		if (size == 0)
		{
			return 0;
		}

		result = nums.front();
		for (int i = 0; i < size; i++)
		{
			if (i == 0 || nums[i] == 0)
			{
				dpMax.push_back(nums[i]);
				dpMin.push_back(nums[i]);
			}
			else
			{
				dpMax.push_back(max((nums[i] > 0 ? dpMax[i - 1] : dpMin[i - 1])* nums[i], nums[i]));
				dpMin.push_back(min((nums[i] > 0 ? dpMin[i - 1] : dpMax[i - 1])* nums[i], nums[i]));
			}
			result = max(result, dpMax[i]);
		}

		return result;
	}
};
```