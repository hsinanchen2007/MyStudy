#### 本题求解采用了BP+BFS的方法。
- 求解步骤
  - 对```matrix```中的每一对```(i,j)```进行DFS处理
  - 对节点```(i,j)```,它所能到达的最远距离(结果存放在二维数组```visited```中) 
   ```
    visited[i][j] = 1+ max(DFS(i-1,j),DFS(i+1,j),DFS(i,j+1),DFS(i,j-1));
   ```
  - 更新```ret```的值, ```ret = max(ret,visited[i][j])```
  - 重复上述操作，直到遍历结束
- c++代码
```
#define MAX(x,y) ((x>y)?(x):(y))
class Solution {
public:
	int rows, cols;
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		rows = matrix.size(); 
        if(!rows) return 0;
        cols = matrix[0].size();
		vector<vector<int>> visited(rows, vector<int>(cols, 0));
		int ret = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				ret = MAX(ret,DFS(matrix, visited, i, j,INT_MIN));
			}
		}
		return ret;

	}
	int DFS(vector<vector<int>> &matrix, vector<vector<int>> &visited, int i, int j, int lastvalue) {
		if (i < 0 || i >= rows || j < 0 || j >= cols)
			return 0;
		int curvalue = matrix[i][j];
		if (curvalue <= lastvalue)
			return 0;
		int u, r, l, d;
		if (!visited[i][j]) {
			u = DFS(matrix, visited, i+1, j, curvalue);
			r = DFS(matrix, visited, i, j+1, curvalue);
			l = DFS(matrix, visited, i, j-1, curvalue);
			d = DFS(matrix, visited, i-1, j, curvalue);
            visited[i][j] =1 + MAX(MAX(u, r), MAX(l, d));
		}
		return visited[i][j];
	}
};
```