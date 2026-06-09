### 过年好！
### 解题思路
- 对于处于同一个对角线的元素来说，它的列号`c`减行号`r`值是相同的，因此可以用该差值将矩阵的元素按照对角线分组。
- 考虑到快速查找，使用哈希表。题目中要求对同一个对角线的元素按照从小到大排序，考虑使用优先队列（小顶堆）。
- 这样，我们按照对角线为分组加入元素，每当同一个对角线中加入一个元素，就会按照从小到大排序。之后我们按照哈希表检索，依次从堆顶输出元素。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, priority_queue<int,vector<int>, greater<int> > > m;
		const int r = mat.size(), c = mat[0].size();
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				m[j - i].push(mat[i][j]);
			}
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				mat[i][j] = m[j - i].top();
				m[j - i].pop();
			}
		}
		return mat;
    }
};
```