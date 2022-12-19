思路：对于每个循环，把最后一位的复制到数组的0位置，然后剔除最后一位
就是不知道为何超时，请高手指教！
class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		for (int i = 0; i < k; i++)
		{
			nums.insert(nums.begin(), nums.back());
			nums.pop_back();
		}

	}
};