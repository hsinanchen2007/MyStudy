常数优化是真的玄学 同样算法 TLE和双百的差别
优化点1 用自己的struct代替vector<int>作为queue内单元 效率提升100% queue里套vector<int>效率不是一般的低
优化点2 将2维数组展开到1维 效率提升60%
优化点3 memset代替重拷贝或重分配标记矩阵 效率提升40%
优化点4 标记提前到入队列时 效率提升无穷大 (原来习惯是遍历到在=true)
优化点5 剪枝 提前结束遍历

```cpp
class Solution {
public:
	int cutOffTree(vector<vector<int>>& forest) {
		int m = forest.size();
		int n = forest[0].size();
		struct Tu {
			int pos;
			int val;

			Tu(int pos, int val) {
				this->pos = pos;
				this->val = val;
			}
		};
		int result = 0;
		vector<Tu> que;
		que.push_back(Tu(0, 0));
		for (int i = 0; i < forest.size(); ++i)
			for (int j = 0; j < forest[0].size(); ++j)
				if (forest[i][j])
					que.push_back(Tu(i * n + j, forest[i][j]));
		sort(que.begin(), que.end(), [](Tu& a, Tu& b) { return a.val < b.val; });
		bool* visited = new bool[forest.size() * forest[0].size()];
		for (int i = 0; i < que.size() - 1; ++i) {
			memset(visited, false, sizeof(bool) * forest.size() * forest[0].size());
			visited[que[i].pos] = true;
			bool find = false;
			queue<Tu> mQue;
			mQue.push(Tu(que[i].pos, 0));
			while (!mQue.empty()) {
				Tu& c = mQue.front();
				if (c.pos == que[i + 1].pos) {
					find = true;
					result += c.val;
					break;
				}
				int cx = c.pos / n;
				int cy = c.pos % n;
				if (cy != forest[0].size() - 1 && forest[cx][cy + 1] && !visited[c.pos + 1]) {
					visited[c.pos + 1] = true;
					mQue.push(Tu(c.pos + 1, c.val + 1));
				}
				if (cx != 0 && forest[cx - 1][cy] && !visited[c.pos - n]) {
					visited[c.pos - n] = true;
					mQue.push(Tu(c.pos - n, c.val + 1));
				}
				if (cy != 0 && forest[cx][cy - 1] && !visited[c.pos - 1]) {
					visited[c.pos - 1] = true;
					mQue.push(Tu(c.pos - 1, c.val + 1));
				}
				if (cx != forest.size() - 1 && forest[cx + 1][cy] && !visited[c.pos + n]) {
					visited[c.pos + n] = true;
					mQue.push(Tu(c.pos + n, c.val + 1));
				}
				mQue.pop();
			}
			if (!find)
				return -1;
		}
		// delete[](visited);
		return result;
	}
};
```

