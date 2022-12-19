### 解题思路
贪心思路，从外围删除，直至最后剩下的节点只有一个或者两个的时候得到结果。
实现代码的时候注意，每次都需要删除等价的节点，也即是说，当前度为1的所有节点实际上他们等价，一次循环，将其删除干净，然后再来一次，直到剩下的元素只有1个或者2个，而且入度为1；
为了避免重复，使用set进行操作。

### 代码

```cpp
class Solution {
public:
bool Isdone(map<int, int>& nodeIndgreeMap, vector<int>& results)
{
	if (nodeIndgreeMap.size() == 2) {
		auto pFirst = nodeIndgreeMap.begin();
		auto pSec = nodeIndgreeMap.rbegin();
		if (pFirst->second == pSec->second && pFirst->second == 1) {
			results.push_back(pFirst->first);
			results.push_back(pSec->first);
			return true;
		} 
	}
	else if (nodeIndgreeMap.size() == 1) {
		auto pFirst = nodeIndgreeMap.begin();
		results.push_back(pFirst->first);
		return true;
	}
	return false;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
{
	if (n == 2) {
		return (vector<int> {0,1});
	}
	map<int, int> nodeIndgreeMap;
	for (int i = 0 ; i < n; i++) {
		nodeIndgreeMap[i] = 0;
	}
	vector<vector<int>> edgeMap(n, vector<int> ());
	vector<int> results;
	for (auto edge : edges) {
		nodeIndgreeMap[edge[0]]++;
		nodeIndgreeMap[edge[1]]++;
		edgeMap[edge[1]].push_back(edge[0]);
		edgeMap[edge[0]].push_back(edge[1]);
	}
	queue<int> OneIndgreeQueue;
	for (int i = 0; i < n; i++) {
		if (nodeIndgreeMap[i] == 1) {
			OneIndgreeQueue.push(i);
		}
	}
	while(1) {
		set <int> nodeSet;
		while(!OneIndgreeQueue.empty()) {
			int index = OneIndgreeQueue.front();
			nodeIndgreeMap.erase(nodeIndgreeMap.find(index));
			OneIndgreeQueue.pop();
			for (auto node : edgeMap[index]) {
				if (nodeIndgreeMap.find(node) != nodeIndgreeMap.end()) {
					nodeIndgreeMap[node]--;
					if (nodeIndgreeMap[node] == 1) {
						nodeSet.insert(node);
					}
				}
			}
		}
		for (auto node : nodeSet) {
			OneIndgreeQueue.push(node);
		}
		if (Isdone(nodeIndgreeMap, results)) {
			break;
		}
	}
	return results;
}
};
```