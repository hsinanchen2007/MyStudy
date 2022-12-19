### 解题思路
此处撰写解题思路
思想步骤：
第一步：统计每个公交站 有哪些路线经过
第二步：统计起始公交站S的有哪些路径
第三步：遍历现有的路径，如果找到T，则直接退出；如果没有找到，则说明当前选择的路径是找不到T，则寻你S路径中其他公交站台的路径S'队列。之后S'再循环的去查找S'' 的路径队列。依次循环。
### 代码

```cpp
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;
	int N = routes.size();
	map<int, set<int>> m; //统计每个公交站 有哪些路线经过
	for (int i = 0; i < N; i++) {
		for (auto j : routes[i]){
			m[j].insert(i);
		}
	}

	// 统计已经遍历过公交线
	vector<bool> visited(N, false); // 初始化 N条路线，默认都是为false
	// 记录需要遍历的公交线ID
	queue<int> q;
	
	// 统计起始公交站S的路径
	for (auto x : m[S]) {
		q.push(x);
		visited[x] = true;
	}

	int step = 0;

	while (!q.empty()) {
		// 取出目前q 中的公交线路
		step++;
		int l = q.size();
		for (int i = 0; i < l; i++) {
			int s = q.front();
			q.pop();

			//遍历每一个公交线路的公交站
			for (auto x : routes[s]) {
				if (x == T) {
					return  step;
				}
				// 这个公交线 记录其他公交站 涉及到的公交线 可以遍历
				for (auto j : m[x]) {
					if (!visited[j]) {
						q.push(j);
						visited[j] = true;
					}
				}
			}
		}

	}
	return -1;
    }
};
```