```
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		vector<int> presum = { 0 };
		stack<int> st;
		for (int i = 0; i < nums.size(); i++)
		{
			presum.push_back(presum[i] + nums[i]);
			if (!st.size())
				st.push(i);
			else
				if (presum[st.top()] > presum[i])
					st.push(i);
		}
		int len = 0;
		int maxsum = INT_MIN;
		for (int i = presum.size() - 1; i >= 1 && st.size(); i--)
		{
			while (st.size() && st.top() > i)
				st.pop();
			while (st.size() && presum[i] - presum[st.top()] > maxsum)
			{
				if (st.top() == i)
				{
					maxsum = max(maxsum, nums[i - 1]);
					st.pop();
				}
				else
					maxsum = max(maxsum,presum[i] - presum[st.top()]);
			}
		}
		return maxsum;
	}
};
```
