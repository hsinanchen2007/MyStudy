### 解题思路


### 代码

```cpp
class Solution {
public:
bool cross(int k, map<int, bool>*dp,int curr,vector<int>&stones,map<int,int>&exist)
{
	if (curr >= stones.size())
		return false;
	if (curr == stones.size() - 1)
		return true;
	if (dp[curr].count(k) != 0)
		return dp[curr][k];
	if (k < 0)
		return 0;
	else
	{
		bool res = false;
		if (curr == 0)
		{
            if(exist.count(stones[curr] + k)==0)
            res=(res||false);
            else
			res = (res || cross(k, dp, exist[stones[curr] + k], stones, exist));
		}
		else
		{
			if (k != 0)
			{
				if (exist.count(stones[curr] + k) == 0)
					res = (res || false);
				else res = (res || cross(k, dp, exist[stones[curr] + k], stones, exist));
			}
			if (exist.count(stones[curr] + k - 1) == 0)
				res = (res || false);
			else res = (res || cross(k-1, dp, exist[stones[curr] + k-1], stones, exist));
			if (exist.count(stones[curr] + k + 1) == 0)
				res = (res || false);
			else res = (res || cross(k+1, dp, exist[stones[curr] + k+1], stones, exist));
		}
		dp[curr][k] = res;
		return res;
	}
}
    bool canCross(vector<int>& stones) {
        int size = stones.size();
	map<int, bool>*dp = new map<int, bool>[size];
	map<int, int>exist;
	for (int i = 0; i < size; i++)
	{
		exist[stones[i]] = i;
		dp[i] = map<int, bool>();
	}
	bool re = cross(1, dp, 0, stones, exist);
	return re;
    }
};
```