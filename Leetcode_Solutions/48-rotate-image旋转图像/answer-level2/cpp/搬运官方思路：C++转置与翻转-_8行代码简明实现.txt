### 解题思路
![无标题.png](https://pic.leetcode-cn.com/55dab718a93e163fa1d80a4cccfa7c0cdb3d5d42b69df97b9cbdd22fd6c8e940-%E6%97%A0%E6%A0%87%E9%A2%98.png)
官方思路：本题是利用矩阵的性质，首先对矩阵进行转置，然后对每一行逐行进行翻转即可。
### 代码

```cpp
class Solution {
public:
void rotate(vector<vector<int>>& matrix) {
	int N = matrix.size();
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			swap(matrix[i][j], matrix[j][i]);   //矩阵转置；
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N/2; j++)
			swap(matrix[i][j], matrix[i][N - j - 1]);   //逐行翻转
	return;
}
};
```