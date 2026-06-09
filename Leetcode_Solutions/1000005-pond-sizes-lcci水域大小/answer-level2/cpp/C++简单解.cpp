### 解题思路
这个题其实是个漫水填充题（FloodFill），我们只需要对所有为0的点进行DFS，并将遍历过的点标记即可。
![image.png](https://pic.leetcode-cn.com/82ea7fa4223e0ec2b5f8dcd47b3f001f673062aa806f5a4af9a64e2a0ae05f8c-image.png)

### 代码

```cpp
class Solution {
public:
	vector<int > result;
	int line, col;
	vector<vector<int> > land;
	int dfs(int x, int y) {
		if (x < 0 || x >= this->line || y < 0 || y >= this->col) return 0;
		if (land[x][y] != 0) return 0;
		land[x][y] = 1;
		// 返回八个方向为0的点的个数
		int sumNum = 1;
		sumNum += dfs(x + 1, y);	
		sumNum += dfs(x - 1, y);
		sumNum += dfs(x, y + 1);
		sumNum += dfs(x, y - 1);
		sumNum += dfs(x + 1, y + 1);
		sumNum += dfs(x - 1, y - 1);
		sumNum += dfs(x + 1, y - 1);
		sumNum += dfs(x - 1, y + 1);
		return sumNum;
	}
    vector<int> pondSizes(vector<vector<int> >& land) {
    	this->land = land;
		this->line = land.size();
		this->col = land[0].size();
		int ans;
		for (int i = 0; i < this->line; i++) {
			for (int j = 0; j < this->col; j++) {
				if (land[i][j] != 0) continue;
				ans = dfs(i, j);
				// 因为有各种不合法条件都返回的0，所以这里要进行判断答案是否合法
				if (ans != 0) result.push_back(ans);
			}
		}
		sort(result.begin(), result.end());
		return result;
    }
};

```