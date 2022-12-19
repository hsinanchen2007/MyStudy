### 解题思路

![image.png](https://pic.leetcode-cn.com/6e1b41b56a3e8031593c569ec05b79d33e65409996b5178752f0f45d5d253efa-image.png)

### 代码

```cpp
class Solution {
public:
int dp[50009];
struct work
{
	int st, en, pro;
	friend bool operator<(const work&a, const work&b)
	{
        if(a.en<b.en)
		return 1;
        else if(a.en==b.en)return a.st<b.st;
        else return 0;
	}
}works[50009];
int rig[50009];
vector<int>toid[50009];
int lower(int*s, int cnt, int val)
{
	int L = 0;
	int R = cnt - 1;
	int mid;
	while (L < R)
	{
		mid = (L + R) / 2;
		if (s[mid] >= val)
			R = mid - 1;
		else L = mid + 1;
	}
	if (rig[L + 1] <= val && rig[L + 1])
		L++;
    if(rig[L]>val&&L>0)
     L--;
	return L;
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int sz = startTime.size();
	for (int i = 0; i < sz; i++)
	{
		works[i].st = startTime[i];
		works[i].en = endTime[i];
		works[i].pro = profit[i];
	}
	sort(works, works + sz);
	int cnt = 1;
	toid[0].push_back(0);
	rig[0] = works[0].en;
	for (int i = 1; i < sz; i++)
	{
		if (works[i].en == works[i - 1].en)
			toid[cnt-1].push_back(i);
		else rig[cnt] = works[i].en, toid[cnt++].push_back(i);
	}
	int id = 0;
	for (int i = 0; i < toid[0].size(); i++)
	{
		dp[0] = max(dp[0], works[toid[0][i]].pro);
	}
	for (int i = 1; i < cnt; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 0; j < toid[i].size(); j++)
		{
			id = lower(rig, cnt, works[toid[i][j]].st);
            if(rig[id]<=works[toid[i][j]].st)
			dp[i] = max(dp[i], works[toid[i][j]].pro + dp[id]);
            else dp[i] = max(dp[i], works[toid[i][j]].pro);
		}
	}
	return dp[cnt - 1];
    }
};
```