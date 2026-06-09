### 解题思路
先把所有的面都加上，然后在减去被遮掩的面

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    	int N = grid.size(), ans = 0;

    	int nr[4] = {-1, 0, 1, 0};
    	int nc[4] = {0, 1, 0, -1};

    	for (int i = 0; i < N; ++i) {
    		for (int j = 0; j < N; ++j) {
    			if (grid[i][j] == 0) continue;
    			ans += grid[i][j] * 4 + 2;
    			for (int k = 0; k < 4; ++k) {
    				int ni = i + nr[k], nj = j + nc[k];
    				if (ni >= 0 && ni < N && nj >=0 && nj < N) {
    					ans -= min(grid[i][j], grid[ni][nj]);
    				}
    			}
    		}
    	}
    	return ans;
    }
};
```