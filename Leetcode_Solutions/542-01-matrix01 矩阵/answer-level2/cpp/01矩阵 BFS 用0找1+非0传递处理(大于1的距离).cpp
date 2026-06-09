### 解题思路
此处撰写解题思路

### 代码

```cpp
/*
想法

一种更好的暴力：

搜寻整个矩阵太过于浪费，因此我们使用广度优先搜索去限制搜索空间。只要 0 出现在广度优先搜索时，我们就知道这个 0 是最近的。因此，只需要考虑下一个 1。

再次考虑：

但在这种方法中，我们只能够更新一个 1 的距离，这可能在某种程度上，更大程度提高方法 1 的复杂度。但是，如果我们从 0 开始广度优先搜索并且更新路径上所有的 1，这会优化我们的算法。

	总结：从1找0 演变成 0找1 . 而如果1的上下左右都是1,则1+1=2,传递处理解决。
		详细解析在代码注释
		
*/
class Solution{
public:
	vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
	{
		int rows = matrix.size();

		if(rows == 0)
			return matrix;

		int cols = matrix[0].size();

		vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));

		queue<pair<int,int>> q;

		for(int i=0;i<rows;i++)
			for(int j=0;j<cols;j++)
				if(matrix[i][j] == 0){
					dist[i][j] = 0;
					q.push({i,j});	//Put all coordinates of ‘0’ in the queue.
				}

		int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

		while(!q.empty()){
			pair<int,int> curr = q.front();
			q.pop();

			for(int i=0;i<4;i++){
				int new_r = curr.first + dir[i][0]; // 左右
				int new_c = curr.second + dir[i][1]; // 上下

				if(new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols){
					if(dist[new_r][new_c] > dist[curr.first][curr.second] + 1){ //新的>(旧的+1); 找到的新坐标 > 0+1时
						dist[new_r][new_c] = dist[curr.first][curr.second] + 1; // 则修改 + 1距离

						q.push({new_r,new_c}); // 用0找到的1可能身边都是非0,则通过1来传递->'1+1=2''2+1=3'进行传递处理。
					}
				}
			}
		}
		return dist;
	}
};


/*
	复杂度分析：
		· 时间复杂度：O(r·c),因为每个节点只会加入队列一次,不会多次加入。
		· 空间复杂度： O(r·c),比方法1需要多一个队列开销。

*/
```