### 解题思路
倒排加速策略
使用mValue判断某个值是否被访问过，从后向前判断，并把到达过的值从mValue中删掉。

### 代码

```cpp
class Solution {
public:
	int minJumps(vector<int>& arr) {
		if (arr.empty() || arr.size() == 1) return 0;
		unordered_map<int, vector<int>>mValue;//
		int size = arr.size();
		for (int i = 0; i < size; i++) {
			mValue[arr[i]].push_back(i);
		}

		return BFS(arr, mValue);
	}
	int BFS(vector<int>& arr, unordered_map<int, vector<int>>&mValue) {
		unordered_map<int, int>dist;
		queue<int>q1;
		int idx, tmp, size = arr.size();
		q1.push(size - 1);
		dist[size - 1] = 0;
		while (!q1.empty()) {
			idx = q1.front();
			q1.pop();
			tmp = idx - 1;
			if (tmp >= 0 && dist.find(tmp) == dist.end()) {
				q1.push(tmp);
				dist[tmp] = dist[idx] + 1;
			}
			tmp = idx + 1;
			if (tmp <= size - 1 && dist.find(tmp) == dist.end()) {
				q1.push(tmp);
				dist[tmp] = dist[idx] + 1;
			}
			//相当于mValue做key值的isVisited ，判断该key是否存在。
			//只要value值被加入队列中，value值对应的所有下标都会加入队列，并且该value值会被删除
			if (mValue.find(arr[idx]) == mValue.end()) continue;//倒排加速关键
			for (int& next : mValue[arr[idx]]) {
				if (next != idx && dist.find(next) == dist.end()) {
					q1.push(next);
					dist[next] = dist[idx] + 1;
					if (next == 0) {
						return dist[0];
					}
				}
			}
			mValue.erase(arr[idx]);
		}
		return  dist[0];
	}
};
```