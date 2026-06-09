### 解题思路
和岛屿面积那题很像，不过这里统计的是岛屿个数，所以只用把遍历过的点标记成水即可

### 代码

```cpp
class Solution {
public:
	int line, column;
	vector<vector<char > > m;
	void dfs(int x, int y) {
		// 出界判断 
		if (x >= line || x < 0 || y >= column || y < 0) return;
		// 访问过判断以及是否是水判断 
		if (m[x][y] != '1') return; 
		// 将已经访问过的点标记为0，这样也可以避免重复访问，同时
		// 方便了调用时的判断 
		m[x][y] = '0'; 
		// 标记		
		dfs(x + 1, y);
		dfs(x - 1, y);
		dfs(x, y + 1);
		dfs(x, y - 1);
	}
    int numIslands(vector<vector<char> >& grid) {
    	if (grid.size() <= 0 || grid.empty()) return 0;
        this->line = grid.size();
        this->column = grid[0].size();
        this->m = grid;
        int cnt = 0;
        for (int i = 0; i < this->line; i++) {
        	for (int j = 0; j < this->column; j++) {
        		// 对子图开始填充 
        		if (m[i][j] != '0') {
        			dfs(i, j);
        			cnt++;
				}
			}
		}
        return cnt;
    }
}; 
```