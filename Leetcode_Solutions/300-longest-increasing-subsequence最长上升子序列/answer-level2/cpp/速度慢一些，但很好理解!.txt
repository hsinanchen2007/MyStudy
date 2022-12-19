### 解题思路
发现需要修改的地方，还望指正，谢谢！

### 代码

```cpp
class Solution {
public:
   int lengthOfLIS(vector<int>& nums)
	{
		int nSize = nums.size();
		if (0 == nSize)
		{
			return 0;
		}
		int nRes = lengthOfLIS(nums, 0, -0x7fffffff);
		return nRes;
	}
	int lengthOfLIS(vector<int>& nums,  int nCur, int nPre)
	{
		if (nCur >= nums.size())
		{
			return 0;
		}

		int nNUmber1 = 0;
		int nNumber2 = 0;
		if (nums[nCur] > nPre)
		{
			nNUmber1 = 1 + lengthOfLIS(nums, nCur + 1, nums[nCur]);
			int i = nCur;
			while (i < nums.size() && (nums[i] >= nums[nCur] || nums[i] <= nPre))
			{
				i++;
			}
			if (nCur < nums.size())
			{
				nNumber2 = lengthOfLIS(nums, i, nPre);
			}
			else
			{
				nNumber2 = 0;
			}
		}
		else
		{
			nNUmber1 = lengthOfLIS(nums, nCur + 1, nPre);
			nNumber2 = nNUmber1;
		}
		return max(nNUmber1, nNumber2);
	}
};
```