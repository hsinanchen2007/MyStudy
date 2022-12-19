### 解题思路
法一贪心算法
当寻找下一个点时，判断该点下一步能够到达最远的位置。选择最远的那个点。
法二
从结尾开始往前找当前点找下一个能跳到的点且能最少步数跳到终点的点，这需要保存从末尾开始每个点最少跳跃点数。
### 代码

```cpp
class Solution {
public:
//方法一
int jump(vector<int>& nums) {
	int len = nums.size();
	if (len == 1)
		return 0;
	int index = 0, steps = 0;
	int mins = 0;
	int minsindex = 0;
	int s = 0;
	while (1)
	{
		mins = len - 1 - nums[index + 1]- index - 1;
		mins = mins < 0 ? 0 : mins;
		minsindex = 0;
		s = mins;
		for (int i = 0; i < nums[index]; i++)
		{
			if ((i + 1 + index) < len)
			{
				s = len - 1 - i - nums[index + i + 1] - index - 1;
				s = s < 0 ? 0 : s;
				if (mins >= s)
				{
					mins = s;
					minsindex = i + 1 + index;
				}
			}
			else
			{
				break;
			}
		}
		index = minsindex;
		steps++;
		if (index == len - 1)
			return steps;
	}
}
//方法二
int jump1(vector<int>& nums) {
	vector<int> step;
	step.insert(step.begin(), 0);
	if (nums.size() == 1)
		return 0;
	int end = nums.size() - 2;
	int index = 0;
	while (1)
	{
		int mins = step[0];
		if (nums[end] == 0)
			mins = -1;
		int i = 0;
		if (nums[end] >= step.size())
			i = step.size() - 1;
		else{
			i = nums[end] - 1;
		}
		for (i; i >= 0; i--)
		{
			if (i >= step.size())
			{
				break;
			}
			else
			{
				if (mins > step[i] && step[i] >= 0)
				{
					mins = step[i];
					index = i;
				}
				else if (mins < 0 && step[i] >= 0)
				{
					mins = step[i];
					index = i;
				}
				if (mins == 1 && nums[end] < step.size())
				{
					break;
				}
			}
		}
		if (mins < 0)
		{
			step.insert(step.begin(), -1);
			end--;
		}
		else
		{
			step.insert(step.begin(), mins + 1);
			if (end == 0)
			{
				return step[0];
			}
			end--;
		}

	}
}
};
```