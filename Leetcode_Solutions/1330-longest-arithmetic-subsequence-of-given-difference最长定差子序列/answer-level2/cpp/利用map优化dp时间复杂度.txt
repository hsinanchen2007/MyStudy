常规dp解法时间复杂度O(n^2)，超时
利用map查找时间复杂度为O(log n)的特点，使用map替代内层循环，将时间复杂度降低为O(n*log n)
```cpp
class Solution
{
public:
	int longestSubsequence(vector<int>& arr, int difference)
	{
		int n = arr.size();
		if (n == 0)
		{
			return 0;
		}
		unordered_map<int, int> mymap;
		int res = 1;
		for (auto n : arr)
		{
			if (mymap.find(n - difference) != mymap.end())
			{
				mymap[n] = mymap[n - difference] + 1;
			}
            else
			{
				mymap[n] = 1;
			}
			res = max(res, mymap[n]);
		}
		return res;
	}
	/*常规dp解法
	int longestSubsequence(vector<int>& arr, int difference)
	{
		int n = arr.size();
		if (n == 0)
		{
			return 0;
		}
		vector<int> dp(n, 1);
		int res = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (arr[j] + difference == arr[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}*/
};
```