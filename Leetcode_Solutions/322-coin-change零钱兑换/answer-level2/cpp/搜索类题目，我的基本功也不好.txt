需要注意的是递归出口应该是数组长度为零的情况下的最小值。否侧数组下标会超。
```
class Solution {
public:
	void dfs(vector<int>coins, int amount, int&ans,int coin)
	{
        if(coins.size()==0)
        {
            if(amount==0)
                ans=min(ans,coin);
            return;
        }
		int temp = coins[0];
		coins.erase(coins.begin());
		for (int k = amount / temp; k >= 0 && k + coin < ans; k--)
		{
			dfs(coins, amount - k*temp, ans, coin + k);
		}
		coins.insert(coins.begin(), temp);
	}
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		int ans = INT_MAX;
		sort(coins.rbegin(), coins.rend());
		dfs(coins, amount, ans, 0);
		return ans==INT_MAX?-1:ans;
	}
};
```
