### 解题思路
此处撰写解题思路
	动态规划(通俗:双向生成传递值+层级调用)
		(PS:层级调用,即每一个新的循环/迭代,调用上一个循环/迭代,进行对比)

	·算法(详细部分写在代码注释里)
		从上至下、从左至右迭代整个矩阵： (1)上左->右下; (2)右下->上左
			(1)的矩阵并非完美,因为越是接近'右下'的matrix,越不一定是最优;所以需要(2)矩阵进行校验(我称之为逆向校验),实际上并非是斜对角线校验(并非欧式距离校验),而是2层顺序(first右second左,2个for的嵌套关系)。
		实际上,这和暴力破解法有异曲同工之妙,暴力破解法初始版本是1找0,这个办法直接通过生成一个新的图(NxN的matrix)


	·想法
		对于一个节点来说，它到 0 的距离可以通过邻居的最近距离计算，在这种情况下最近距离是邻居的距离 + 1。也就是术语：动态规划;通俗：'层级调用'

		对于每个 1，到 0 的最短路径可能从任意方向。所以我们需要检查所有 4 个方向。在从上到下的迭代中，我们需要检查左边和上方的最短路径；我们还需要另一个从下往上的循环，检查(校验)右边和下方的方向。

		最近距离考虑top方邻居和left侧邻居'距离+1'，这在前面的迭代中已经计算完成。
		最近距离考虑bottom方邻居和right侧邻居‘距离+1’，这在前面的迭代中已经计算完成。

	复杂度分析

	时间复杂度：O(r⋅c)，两边扫描各为r⋅c。
	空间复杂度：O(r⋅c)，除了 dist vector<vector<int> > 无需额外空间。



### 代码

```cpp
class Solution
{
public:
	vector<vector<int> > updateMatrix(vector<vector<int>>& matrix){
		int rows = matrix.size();

	if(rows == 0)
		return matrix;

	int cols = matrix[0].size();

	vector<vector<int> > dist(rows,vector<int>(cols,INT_MAX - 100000));

	//First pass : check for left and top
	for(int i=0;i<rows;i++) { // 从left->right
		for(int j=0;j<cols;j++){ // 从top->bottom
			if(matrix[i][j] == 0)
				dist[i][j] = 0;
			else{
				if(i>0)
					dist[i][j] = min(dist[i][j],dist[i-1][j]+1); // [i-1][j] = left + min(层级调用)
				if(j>0)
					dist[i][j] = min(dist[i][j],dist[i][j-1]+1); // [i][j-1] = top + min(层级调用)
			}
		}
	}

	//Second pass : check for bottom and right
	for(int i=rows-1;i>=0;i--){ // 从right->left
		for(int j=cols-1;j>=0;j--){ // 从bottom->top
			if(i < rows-1)
				dist[i][j] = min(dist[i][j],dist[i+1][j]+1);
					// [i+1][j] = bottom
			if(j < cols-1)
				dist[i][j] = min(dist[i][j],dist[i][j+1]+1);
					// [i][j+1] = right
		}
	}

	return dist;
	}
};
```