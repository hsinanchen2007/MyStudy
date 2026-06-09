### 解题思路
经典的漫水填充法题目，题目给出了起点和要染的颜色，注意下原颜色和要染的颜色相同的情况即可。
![image.png](https://pic.leetcode-cn.com/190bb05b7bb160aa5b8b312f3829c05f4ba239051d4f39ff604d9b164d5185fd-image.png)


### 代码

```cpp
class Solution {
public:
	vector<vector<int> > result;
	int line, col;
	void dfs(int sx, int sy, int target, int color) {
		// 之前以为不用判断出界，但实际上这个题和被包围的岛屿那个题不一样
		// 这里没有东西包围着颜色 
		if (sx >= line || sx < 0 || sy >= col || sy < 0) return;
		// 同一颜色才进行染色（也就是连通），否则不管 
		if (result[sx][sy] != target) return;
		// 如果颜色和原色相同，就会出现无限染色的情况，这样就会
		// StackOverflow...所以这里用一个不可能存在的颜色标记地图，
		// 然后dfs完了再染成真正的颜色 
		// result[sx][sy] = -1;
		result[sx][sy] = color;
		dfs(sx + 1, sy, target, color);
		dfs(sx - 1, sy, target, color);
		dfs(sx, sy + 1, target, color);
		dfs(sx, sy - 1, target, color);
	}
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
		this->line = image.size(), this->col = image[0].size();
		this->result = image;
		int target = image[sr][sc];
		//		for (int i = 0; i < line; i++) {
		//			for (int j = 0; j < col; j++) {
		//				// 再把颜色染回来 
		//				result[i][j] = result[i][j] != -1 ? result[i][j] : newColor;
		//			}
		//		}
		// 当然相比染完了再染回来更加明智的选择是判断下原颜色
		// 是否和要染的颜色相同，这样就可以避免不必要的操作 
		if (target != newColor) dfs(sr, sc, target, newColor);
		return result;
    }
}; 
```