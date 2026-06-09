### 解题思路
1，看题一脸懵逼，直接去看题解吧
2，一开始先用投影，但是无法处理中间有洞的情况，那就用去重吧
3，先计算上下贴合的，再计算左右贴合的。
4，上下贴合的好理解，就是个数*4+2，因为只要贴合就损耗2。
5，考虑左右贴合要有**立体思维**，只要贴合，损耗也是2
	// grid[i][j]会与grid[i - 1][j], grid[i][j - 1]有接触，是有高度的
    // 接触面个数为二者的最小,每一个接触面面积同样也是2,减去

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
	int n = grid.size();
	if (n == 0) return 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (grid[i][j] > 0) {
				sum += (grid[i][j] * 4 + 2);
				if (i > 0) sum -= min(grid[i][j], grid[i - 1][j]) * 2;
				if (j > 0) sum -= min(grid[i][j], grid[i][j - 1]) * 2;
			}
		}
	return sum;
    }
};
```