### 解题思路
进程之间的父子关系可以抽象成树，所以本题首先利用树的邻接矩阵将树表示出来，然后再利用树的先根遍历将该kill根节点以及子节点找出来即可。

### 代码

```cpp
class Solution {
public:
	void DFSFindChild(map<int, vector<int>>& ppidPidMap, vector<int>& results, int kill)
	{
		results.push_back(kill);
		if (ppidPidMap.find(kill) == ppidPidMap.end()) {
			return;
		}
		auto pPidMap = ppidPidMap.find(kill);
		for (auto killItem : pPidMap->second) {
			DFSFindChild(ppidPidMap, results, killItem);
		}
	}
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> results;
		if (pid.empty()) {
			return results;
		}
		map<int, vector<int>> ppidPidMap;
		for (int i = 0; i < pid.size(); i++) {
			if (ppid[i] != 0) {
				ppidPidMap[ppid[i]].push_back(pid[i]);
			}
		}
		DFSFindChild(ppidPidMap, results, kill);
		return results;
    }
};
```