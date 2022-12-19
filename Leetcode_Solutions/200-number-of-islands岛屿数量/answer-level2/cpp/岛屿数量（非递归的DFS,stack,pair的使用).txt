### 解题思路
官方的思路：线性扫描整个二维网格，如果一个结点包含 1，则以其为根结点启动深度优先搜索。在深度优先搜索过程中，每个访问过的结点被标记为 0。计数启动深度优先搜索的根结点的数量，即为岛屿的数量。

总的来说就是：二重循环+找到'1'时，以'1'为根节点启动深搜，直到该区域找不到了'1'，再继续执行循环找到'1'，深搜...
### 代码

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
	int res = 0;
	int a[] = { 0,1,-1,0 };  //两个数组对应着他的四个方向。。
	int b[] = { -1,0,0,1 };
    stack<pair<int, int>>sta;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
        //stack<pair<int, int>>sta;不要在这里声明。。。。。
/*注意：如果在两层for循环里构建stack<pair<int, int>>sta会产生巨大的
空间消耗，用pair，不行就用一个int[]数组，再不行使用两个栈分别放置x,y坐标*/
			if (grid[i][j] == '1') {
				res++;
				sta.push({i,j});
				while (sta.size()) {
					int x = sta.top().first; //得到pair中的两个值
					int y = sta.top().second;
					sta.pop();
					    grid[x][y] = 0;
						for (int i = 0; i < 4; i++) {
                        if (x+a[i] >= 0 && x+a[i] < grid.size() && y+b[i] >= 0 && y+b[i] < grid[0].size()&&grid[x+a[i]][y+b[i]]=='1' ) {
							sta.push({ x + a[i],y + b[i] });
						}
					}
				}
			}
		}
	}
	return res;
}
};
```
stack在里面
![image.png](https://pic.leetcode-cn.com/399ddea392b5a7e2e7ecf09bd139691e37b66933a9ec6bf386a72c1f7e80014f-image.png)



stack在外面：
![image.png](https://pic.leetcode-cn.com/5341d1d4b1b2f1c0b58b507a9e20fe917c00548374e83d63f620bb4a817c668b-image.png)
