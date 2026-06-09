
dp[i]代表的是加i次油能获得的最大油量，dp[0]是起始位置的油量，其余位置初始化为0；
那么核心点在于如何获取加油i次能获得的最大油量
我刚开始是通过二维的搜索，j=0开始，dp也是从前向后进行更新最大油量（k=0-k=j）
但是结果不太对，发现的问题主要是从前向后更新，后面的点会用到前面更新的结果，从而出现问题，
看了官方答案是从后向前遍历的，有点意思，因为每次用的数据是前一个和当前的加油站的油量
所以每个点都不受到影响。。动态规划总是感觉想的不清楚。。
```

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		//dp[i]代表加i次油能获得的最大油量
		vector<long>dp(stations.size() + 1);
		dp[0] = startFuel;
		for (int i = 0; i < stations.size(); i++) {
			for (int t = 0; t<= i; t++) {
				if (dp[t] >= stations[i][0]) {
					dp[t+1] = max(dp[t+1], dp[t] + stations[i][1]);
				}
			}
			for (auto a : dp)cout << a << " ";
			cout << endl;
		}
		int i = 0;
		for (; i < dp.size(); i++) {
			if (dp[i] >= target) return i;
		}
		return -1;
	}
};
```
