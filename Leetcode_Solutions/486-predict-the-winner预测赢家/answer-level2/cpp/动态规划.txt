### 解题思路
构建2个二维dp数组dp_max[start][end],dp_min[start][end],分别维护对于从名nums的vector中，start到end这段子数组，先手所能取到的最小值，在后手的回合，求start到end这段子数组的最小值，并存在dp_min[start][end]以备下次使用。在先手的回合，求start到end这段子数组的最大值，并存在dp_max[start][end]以备下次使用。

### 代码

```cpp
class Solution {
public:
int maxm =static_cast<int>( pow(2, 31) )- 1;
int predictWinner(int**dp_max, int**dp_min, bool firstTurn,int start,int end,vector<int>&nums)
{
	if (firstTurn)
	{
		if (dp_max[start][end] != -1)
			return dp_max[start][end];
		else
		{
			int max = 0;
			if (start == end)
				max = nums[start];
			else if (start + 1 == end)
				max = nums[start] > nums[end] ? nums[start] : nums[end];
			else
			{
				int a = nums[start] + predictWinner(dp_max, dp_min, !firstTurn, start + 1, end, nums);
				int b= nums[end] + predictWinner(dp_max, dp_min, !firstTurn, start , end - 1, nums);
				max = a > b ? a : b;
			}
			dp_max[start][end] = max;
			return max;
		}
	}
	else
	{
		if (dp_min[start][end] != -1)
			return dp_min[start][end];
		else
		{
			int min = maxm;
			if (start == end)
				min = nums[start];
			else if (start + 1 == end)
				min = nums[start] > nums[end] ? nums[end] : nums[start];
			else
			{
				int a = predictWinner(dp_max, dp_min, !firstTurn, start + 1, end, nums);
				int b = predictWinner(dp_max, dp_min, !firstTurn, start, end - 1, nums);
				min = a < b ? a : b;
			}
			dp_min[start][end] = min;
			return min;
		}
	}
}
    bool PredictTheWinner(vector<int>& nums) {
    if(nums.size()<=1)//特判
    return true;
    int size = nums.size();
	int**dp_max = new int*[size];
	int**dp_min = new int*[size];
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += nums[i];
		dp_max[i] = new int[size];
		dp_min[i] = new int[size];
		for (int j = 0; j < size; j++)
			dp_min[i][j] = dp_max[i][j] = -1;
	}
	int re = predictWinner(dp_max, dp_min, true, 0, size - 1, nums);
    if(re>=sum-re)
	return true;
    else return false;
    }
};
```