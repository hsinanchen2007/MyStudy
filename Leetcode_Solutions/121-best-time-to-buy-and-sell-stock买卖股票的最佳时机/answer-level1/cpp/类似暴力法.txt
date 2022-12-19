class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxDifference = 0;
		int priceNum = prices.size();
		for (int i = 0; i < priceNum - 1; i++)
		{
			for (int j = i; j < priceNum; j++)
			{
				int tmpDiff = prices[j] - prices[i];
				if (tmpDiff > maxDifference)
				{
					maxDifference = tmpDiff;
				}
				else if (tmpDiff < 0)
					break;
				else
					continue;
			}
		}
		return maxDifference;
	}
};

这个方法有点蠢，只是自己记录一下