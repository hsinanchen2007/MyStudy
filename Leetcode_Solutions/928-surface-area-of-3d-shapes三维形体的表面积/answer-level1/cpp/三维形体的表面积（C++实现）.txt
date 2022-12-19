### 解题思路
![无标题.png](https://pic.leetcode-cn.com/a470005fd05672f2c728d2ebe51c93fc19cec7b6729f899bdd1e7bd1e0ccaa71-%E6%97%A0%E6%A0%87%E9%A2%98.png)

**对于传统的想法**，人们会试图采用投影的方法或是六视图的方法。这种方法对于密铺几何体（没有“挖洞”的）也许可行，但是对于有空心的（空心必须延伸至表面）几何体不适用，因为投影和视图无法看出那些空洞。所以采用先累加后减去重复的面积，使用两层循环，故时间复杂度为**O（n^2）**
基本思路就是，建立两层循环遍历方格，**独立的加上每个方格内的立方体表面积（每个立方体6个面）**；然后减去重复的面积即可。
### 代码

```cpp
class Solution {
public:
int surfaceArea(vector<vector<int>>& grid) {
	int i, j, ans = 0;
	for (i = 0; i < grid.size(); i++) {
		for (j = 0; j < grid.size(); j++) {
			if (grid[i][j] > 0) {
				ans += grid[i][j] * 4 + 2;    //累加每个方格内立方体的面积（6个面）
				if (i > 0)
					ans -= min(grid[i][j], grid[i - 1][j]) * 2; //再减去重复面积
				if (j > 0)
					ans -= min(grid[i][j], grid[i][j - 1]) * 2;
			}
		}
	}
	return ans;
}
};
```