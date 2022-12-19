# 1、动态规划
动态规划的本质是穷举，再在有限状态机中进行状态转化。
步骤：
一、定义dp数组含义，dp[所在加油站][加油的次数]=所能行驶的最长距离。
二、定义base_case 对于所有i,dp[i][0]=startFuel。
三、定义状态转移方程，dp[所在加油站][加油的次数]=max(dp[所在加油站-1][加油的次数-1]+dp[所在加油站-1][加油的次数])。
代码：
```javascript []
class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		//一、定义dp数组含义，dp[所在加油站][加油的次数]=所能行驶的最长距离。
		//tips:这道题的答案是最后一个加油站在满足行驶距离的情况下最少的加油次数，答案在索引里，而有的题目答案是在值里面。
		vector<vector<long>> dp;
		for (int i = 0; i <= stations.size(); i++)
		{
			vector<long> line(stations.size() + 1);
			dp.push_back(line);
		}
		//二、定义base_case 对于所有i,dp[i][0]=startFuel。
		for (int i = 0; i <= stations.size(); i++)
			dp[i][0] = startFuel;
		//三、定义状态转移方程，dp[所在加油站][加油的次数]=max(dp[所在加油站-1][加油的次数-1]+dp[所在加油站-1][加油的次数])。
		for (int i = 1; i <= stations.size(); i++)
		{
			int currStationPos = stations[i - 1][0];
			int currStationGas = stations[i - 1][1];
			for (int j = 1; j <= stations.size(); j++)
			{
				if (dp[i - 1][j] >= currStationPos)//如果到达不了就没有意义。
					dp[i][j] = dp[i - 1][j];
				if (dp[i - 1][j - 1]  >= currStationPos)
					dp[i][j] = max(dp[i - 1][j - 1] + currStationGas, dp[i][j]);
			}
		}
		for (int i=0;i<dp.size();i++)
		{
			if (dp[dp.size() - 1][i] >= target)
				return i;
		}
		return -1;
	}
```
# 2、栈（我认为更准确的说法是贪心算法）
注意到这个问题的一个性质：只要能够到达某个站点，之前的站点都可以自由的选择加油或者不加油。
这样我们可以每次不能到达下一个站点时，选择之前站点里面油最多的站点进行加油，直到到达终点或无论如何都到达不小下一个站点。
贴一个官方解答最后的别人的代码。
```javascript []
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back(vector<int>({ target, 0 }));
        priority_queue<int> pq;
        int res = 0, pos = 0, tank = startFuel;
        for (auto& v : stations) {
            int curpos = v[0];
            int curval = v[1];
            tank = tank - curpos + pos;
            while (!pq.empty() && tank < 0) {
                tank += pq.top();
                pq.pop();
                res++;
            }
            if (tank < 0) return -1;
            pq.push(curval);
            pos = curpos;
        }
        return res;
    }
};
```

# 这类问题的关键
1. 要把问题具体化、建立数学模型、找到数据模型内在的性质
2. 利用动态规划或者贪心算法进行解答
