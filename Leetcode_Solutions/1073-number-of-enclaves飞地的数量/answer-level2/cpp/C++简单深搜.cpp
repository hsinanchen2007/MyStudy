### 解题思路
思路和求岛屿数量一样，关键是如何判断某一块陆地是飞陆地。

### 代码

```cpp
class Solution {
public:
	int line, col;
	int oneCnt;
	vector<vector<int> > g;
	// 记得加&，不然flag的值不会改变 
	void dfs(int sx, int sy, bool& flag) {
        // 关键：如果遍历出去了，就说明不是飞陆地，题目中也是这样说的
		if (sx < 0 || sx >= line || sy < 0 || sy >= col) {
			flag = false;
			// oneCnt = 0;
			return;
		}
		// 只对陆地进行遍历 
		if (g[sx][sy]) {
			g[sx][sy] = 0;
			oneCnt++;
			dfs(sx + 1, sy, flag);
			dfs(sx - 1, sy, flag);
			dfs(sx, sy + 1, flag);
			dfs(sx, sy - 1, flag);
		}
	}
    int numEnclaves(vector<vector<int> >& A) {
    	this->g = A;
		this->line = A.size(), this->col = A[0].size();
		bool flag;
		int ans = 0;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (g[i][j]) {
					flag = true, oneCnt = 0;
					dfs(i, j, flag);
					if (flag) ans += oneCnt;
				}
			}
		}
		return ans;
    }
};
```