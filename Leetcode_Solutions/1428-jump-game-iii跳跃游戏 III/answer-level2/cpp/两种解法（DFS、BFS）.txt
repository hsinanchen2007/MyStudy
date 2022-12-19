### 解题思路
1.DFS ：函数内写好basecase，直接递归调用左右两个下标的DFS函数即可。
2.BFS：用队列做宽度优先遍历，结点出队列的时候将左右两个下标加入队列中，如果队列弹空了都没有下标满足arr[index]==0,则返回false。
DFS代码风格比较简洁，需要对递归程序有一定掌握；BFS方法更直观和易于理解。因为都是只遍历一遍数组，因此时间复杂度都为O(arr.size()),DFS因为递归调用会多一点常数项时间。建议两种方法都要掌握。

### 代码

```cpp
class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		vector<bool>isVisited(arr.size());
		return bfs(arr, start, isVisited);
	}
	bool dfs(vector<int>&arr, int index, vector<bool>&isVisited) {
		if (index <0 || index>(int)arr.size() - 1 || isVisited[index]) return false;
		if (arr[index] == 0) return true;
		isVisited[index] = true;
		return dfs(arr, index - arr[index], isVisited) || dfs(arr, index + arr[index], isVisited);
	}
	bool bfs(vector<int>&arr, int start, vector<bool>&isVisited) {
		queue<int>q1;
		int index, tmp, size = arr.size();
		q1.push(start);
		isVisited[start] = true;
		while (!q1.empty()) {
			index = q1.front();
			q1.pop();
			if (arr[index] == 0) return true;
			tmp = index - arr[index];
			if (tmp >= 0 && !isVisited[tmp]) {
				q1.push(tmp);
				isVisited[tmp] = true;
			}
			tmp = index + arr[index];
			if (tmp <= size - 1 && !isVisited[tmp]) {
				q1.push(tmp);
				isVisited[tmp] = true;
			}
		}
		return false;
	}
};
```