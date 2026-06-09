贪心写了半天没写对！ 换了思路.
干脆我就一个一个往里面填，我发现有日期冲突的会议，我就去搜索那个冲突的会议能不能换日子！

代码中vis[]数组表示在某天有什么会议
比如vis[2] = 4;说明第二天有个4号会议。

代码的核心就是暴力递归..
最优解嘛肯定会是最优解.就是时间长了点..好像240ms。

经验就是.自己不够聪明的话 还是别随随便便用贪心了.

```
class Solution {
	int vis[100005];
	bool trans(int day, vector<vector<int>>& events) {
		int cur = vis[day]; //表示发生冲突的会议；
		for (int i = day+1; i <= events[cur][1]; i++) {
			if (vis[i]==-1) //如有有空位置
			{
				swap(vis[day], vis[i]);
				return true;
			}
			else {
				//没有空位置
				if (trans(i, events)) {
					//那么看看这些位置是不是还可以挤一挤
					swap(vis[day], vis[i]);
					return true;
				}
			}
		}
		return false;

	}

public:
	int maxEvents(vector<vector<int>>& events) {
		int n = events.size();
		int day = 0;
		memset(vis, -1, sizeof(vis));
		for (int cnt = 0; cnt < events.size();cnt++) {
			auto ev = events[cnt];
			for (int i = ev[0]; i <= ev[1]; i++) {
				if (vis[i]==-1 || trans(i, events)) {
					vis[i] = cnt;
					day++;
					break;
				}
			}
		}
		return day;
	}
};
```
