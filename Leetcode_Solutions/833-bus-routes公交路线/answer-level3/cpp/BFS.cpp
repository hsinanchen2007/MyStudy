### 解题思路
一道广度优先搜索题目，看到题目里面提示station的数量很大，想到应该使用路线作为搜索目标。

此题目坑的地方是，给的测试用例里面，一条公交路线包含了多次station，其实没有意义。所以不能使用vector来存储，需要使用set来去重。

### 代码

```cpp
class Solution
{
   public:
    int BFSGetMinLine(int S, map<int, set<int>>& stationLineMap, int T, vector<vector<int>>& routes)
    {
        queue<int> bfsQueue;
        vector<bool> lineSet(routes.size(), false);
        for (auto line : stationLineMap[S]) {
            bfsQueue.push(line);
			lineSet[line] = true;
        }
		int step = 0;
        while (!bfsQueue.empty()) {
			step++;
			int bfsLenth = bfsQueue.size();
			for (int i = 0; i < bfsLenth; i++) {
				int line = bfsQueue.front();
				bfsQueue.pop();
				for (auto station : routes[line]) {
					if (station == T) {
						return step;
					}
					for (auto line : stationLineMap[station]) {
						if (! lineSet[line]) {
							lineSet[line] = true;;
							bfsQueue.push(line);
						}
					}
				}
			}
		}
        return routes.size() + 1;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int S, int T)
    {
        map<int, set<int>> stationLineMap;
        for (int i = 0; i < routes.size(); i++) {
            for (auto station : routes[i]) {
                stationLineMap[station].insert(i);
            }
        }
        int ans = routes.size() + 1;
        if (stationLineMap.find(S) != stationLineMap.end()) {
            if (S == T) {
                ans = 0;
                return ans;
            }
            ans = min(ans, BFSGetMinLine(S, stationLineMap, T, routes));
        } else {
            return -1;
        }
        return ans == (routes.size() + 1) ? -1 : ans;
    }
};
```