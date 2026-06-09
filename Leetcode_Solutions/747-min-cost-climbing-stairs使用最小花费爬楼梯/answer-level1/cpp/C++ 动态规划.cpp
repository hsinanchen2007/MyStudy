### 思路
#### 第一步：定义数组元素的含义
题目的要求的是爬到楼层顶部需要的最低花费。因此可将``dp``定义为，**到达第n阶台阶时的最低花费``dp[i]``**
由于最终要到达的是楼顶，所以此处``dp``的``size``为``cost``的``size+1``。
#### 第二步：找出关系数组元素间的关系时
要到达下一阶，可以走一步，也可以走两步，要到达位置``i``，
一种是从``i-1``这个位置走一步到达
一种是从``i-2``这个位置走一步到达
因为是要计算走到``i``位置时，花费最小，要取上述两种情况中的最小者，此处``cost[i]``表示的是到达i+1/i+2阶所需要的体力花费值，所以到达了i-1/i-2阶后，再到达i阶台阶要花费的最小力气关系式是``dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])``

#### 第三步：找出初始值
由题目可知，在开始时，我们可以从索引0或者1的元素作为初始阶梯，因此初始值为``dp[0]=0``和``dp[1]=0``

另外需要注意的是对特殊情况的判断
### 代码
```cpp
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		//特判
		if (cost.empty()) return 0;
		if (cost.size() == 1) return cost[0];
		if (cost.size() == 2) return min(cost[0], cost[1]);
		vector<int> dp(cost.size()+1);
		//初始值
		dp[0] = 0;
		dp[1] = 0;
		//状态转移
		for (int i=2;i<=cost.size();i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}
};
```