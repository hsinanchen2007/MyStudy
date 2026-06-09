### 解题思路
通过题目的示例可以观察到每次转换的数字下标都是有规律的，我们每次只需要交换这几个下标的数字就可以了
这几个下标分别是**左上角的(i, j), 左下角的(N - j - 1, i), 右下角的(N - i - 1, N - j - 1), 右上角的(j, N - i - 1)**
然后按照左上与左下交换，交换后左下与右下交换，最后右下和右上交换的顺序就可以完成4个数字的翻转(也就是**逆时针转一圈**)
这个方法要注意的就是循环的次数，如果是偶数那么就是左上角的区域，如果是奇数就是左上角的区域加上中间的一部分
比如3\*3的矩阵对应的就是2\*1的区域，5\*5对应的就是3\*2的区域，这个也很好理解

### 代码

```cpp
class Solution {
public:
	int N;
	inline void rotate4(vector<vector<int> > & matrix, const int & i, const int & j) {
		swap(matrix[i][j], matrix[N - j - 1][i]);
		swap(matrix[N - j - 1][i], matrix[N - i - 1][N - j - 1]);
		swap(matrix[N - i - 1][N - j - 1], matrix[j][N - i - 1]);
	}
	void rotate(vector<vector<int> > & matrix) {
		N = matrix.size();
		int nRow = (N + 1) >> 1;
		int nCol = N >> 1;
		for (int i = 0; i < nRow; ++i) {
			for (int j = 0; j < nCol; ++j) {
				rotate4(matrix, i, j);
			}
		}
	}
};
```