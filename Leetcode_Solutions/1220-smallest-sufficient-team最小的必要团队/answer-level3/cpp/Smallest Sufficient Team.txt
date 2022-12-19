
$S$表示一个二进制集合.$S$中第$i$位是$1$表示该集合包含标号是$i$的技能

令$dp[S]$表示要获得集合$S$表示的技能的最小花费.也就是最少需要选多少人

假设技能个数是$n$,那么要求的答案就是$dp[(1 << n)-1]$ 

对于状态转移方程:

假设当前第$i$个人的技能集合是$now$.我们就拿当前的技能集合

$now$去更新每一个$dp[now|j], 0 <= j < (1 << n)$的值. 

因为要记录最后所选的答案.所以拿一个$team$数组维护一下

时间复杂度$O(m*2^n)$.$m$是人的个数,$n$是技能个数

ps:看了[mike-meng](https://leetcode-cn.com/problems/smallest-sufficient-team/solution/bei-bao-wen-ti-by-mike-meng/)大佬的题解.所以加了自己的见解

```c++

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int>  mp;
        int n = req_skills.size();
        for(int i = 0; i < n; ++i) mp[req_skills[i]] = i;
        vector<int> dp(1 << n, -1);
		vector<int> team[1 << n];
		dp[0] = 0; // 一个技能都没有的最小花费是0 
		for(int i = 0; i < people.size(); ++i){
			int now = 0;
			for(string s : people[i]){
				int x = mp[s];
				now |= (1 << x);
			}
			for(int j = 0; j < (1 << n); ++j){
				if(dp[j] >= 0){ // 当前集合计算过 
					int x = now | j; // 要更新的集合 
					if(dp[x] == -1 || dp[x] > dp[j]+1){ // 集合没有计算过,或者当前选择更优 
						dp[x] = dp[j]+1;
						team[x] = team[j];
						team[x].push_back(i);
					} 
				}
			}
		}
		return team[(1 << n)-1];
    }
};
```