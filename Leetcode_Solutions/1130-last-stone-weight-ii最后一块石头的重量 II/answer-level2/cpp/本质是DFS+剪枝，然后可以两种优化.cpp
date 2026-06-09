```
/*
由于石头碎掉之后还能放回去，类似于把石头分成两堆来看。
只要依次拿两堆的石头互相粉碎，最后剩下的就是最小整数。
最多有30个石头，每个石头最多1000的重量。所以两个集合最大的差值不会超过30000。
用数组构造结果。
在加入第n个石头重量为m时，查找n-1个石头能够组成的两堆石头的差值的绝对值为diff。
该石头两个选择，放入多的堆，则差值更大，为diff+m；
放入小的堆，则差值为|diff-m|。这时更新n个石头能组成的所有重量。
最后输出最后一个石头能组成的最小重量即可。*/
//dfs版本

class Solution {
public:
	vector<int> vec;
	vector<vector<bool>> flag;//剪枝，标记是否访问过，否则会超时
	void dfs(vector<int>& stones, int sum = 0, int index = 0)
	{
		if (index == stones.size() && sum >= 0)
			vec.push_back(sum);
		if (index < stones.size())
		{
			if (flag[index][sum + stones[index]] == false)
			{
				flag[index][sum + stones[index]] = true;
				dfs(stones, sum + stones[index], index + 1);
			}
			if (flag[index][abs(sum - stones[index])] == false)
			{
				flag[index][abs(sum - stones[index])] = true;
				dfs(stones, abs(sum - stones[index]), index + 1);
			}
		}
	}
	int lastStoneWeightII(vector<int>& stones)
	{
		int n = stones.size();
		int sum = accumulate(stones.begin(), stones.end(), 0);
		flag.resize(n, vector<bool>(sum + 1));
		dfs(stones, 0, 0);
		sort(vec.begin(), vec.end());
		return vec[0];
	}
};
//优化直接状态即输出版本
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones)
	{
		int n = stones.size();
		int sum = accumulate(stones.begin(), stones.end(), 0);
		vector<vector<bool>> dp;
		dp.resize(n, vector<bool>(sum + 1));
		dp[0][stones[0]] = true;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= sum; ++j)
			{
				if (dp[i - 1][j])
				{
					dp[i][j + stones[i]] = true;
					dp[i][abs(j - stones[i])] = true;
				}
			}
		}
		int w;
		for (int i = 0; i <= sum; ++i)
		{
			if (dp[n - 1][i])
			{
				w = i;
				break;
			}
		}
		return w;
	}
};
//更加优化版本位记录
class Solution 
{
public:
	int lastStoneWeightII(vector<int> A)
	{
		bitset<30005> dp = { 1 };
		int sumA = 0, res = 100;
		//各种组合能访问到哪些位置
		for (int a : A)
		{
			sumA += a;
			for (int i = sumA; i >= a; --i)
				dp[i] = dp[i] | dp[i - a];
		}
		//从中间开始查找能组合成最接近一半的数。
		for (int i = sumA / 2; i > 0; --i)
		{
			if (dp[i])
				return sumA - i - i;//两堆石头互减，所以是总和减去两个i。
		}
		return 0;
	}
};
```
