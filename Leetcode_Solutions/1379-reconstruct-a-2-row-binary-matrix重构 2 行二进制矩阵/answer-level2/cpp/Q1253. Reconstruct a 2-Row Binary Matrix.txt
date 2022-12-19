### 模拟
直接按照题意进行模拟
1. 如果列和等于2，则上下都设置为1；
2. 如果列和等于0，则上下都设置为0；
3. 如果列和等于1，上或者下都可以设置为1，具体看upper/lower是否大于0；
4. 不用处理列和等于0的情况，优先处理列和等于2的情况，然后再处理列和等于1的情况，比如题目中给出的第3个示例。
```
class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		vector<vector<int>> emptyMatrix;
		vector<vector<int>> matrix(2, vector<int>(colsum.size(), 0));
		size_t i = 0;
		for (; i < colsum.size(); ++i) {
			if (colsum[i] == 2) {
				if (upper <= 0 || lower <= 0)
					break;

				matrix[0][i] = matrix[1][i] = 1;
				--upper;
				--lower;
			}
		}

		if (i < colsum.size())
			return emptyMatrix;

		for (i = 0; i < colsum.size(); ++i) {
			if (colsum[i] == 1) {
				if (upper > 0) {
					matrix[0][i] = 1;
					matrix[1][i] = 0;
					--upper;
				}
				else if (lower > 0) {
					matrix[0][i] = 0;
					matrix[1][i] = 1;
					--lower;
				}
				else {
					break;
				}
			}
		}

		if (i < colsum.size() || upper > 0 || lower > 0)
			return emptyMatrix;

		return matrix;
	}
};
```
我果真不适合写题解，写文章啊！