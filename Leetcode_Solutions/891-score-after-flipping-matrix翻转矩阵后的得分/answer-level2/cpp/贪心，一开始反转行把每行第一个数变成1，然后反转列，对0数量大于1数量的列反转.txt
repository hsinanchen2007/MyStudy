贪心，一开始反转行把每行第一个数变成1，然后反转列，对0数量大于1数量的列反转。
由于对行和列的反转操作都是每重复操作2次就会和原来一样，所以可以证明最少的反转操作次数为对每一行或列要么不反转，要么只反转一次。按我这样的贪心方式找哪些行或列应该反转，尽量保证了前面1比较多的行数比较多，显然是比较接近正确答案的，提交结果证明确实如此。具体为什么这样是对的，不想想下去了。
```
class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			if (!A[i][0])
				trans_row(A, i);
		}
		for (int j = 0; j < A[0].size(); j++) {
			int count = 0;
			for (int i = 0; i < A.size(); i++) {
				if (!A[i][j])
					count++;
			}
			if (count > A.size() / 2)
				trans_col(A, j);
		}
		int sum = 0;
		for (int i = 0; i < A.size(); i++) {
			int tmp = 0;
			for (int j = 0; j < A[i].size(); j++) {
				tmp <<= 1;
				if (A[i][j])
					tmp++;
			}
			sum += tmp;
		}
		return sum;
	}
	void trans_row(vector<vector<int>>& A, int row) {
		for (int i = 0; i < A[row].size(); i++) {
			A[row][i] = !A[row][i];
		}
	}
	void trans_col(vector<vector<int>>& A, int col) {
		for (int i = 0; i < A.size(); i++) {
			A[i][col] = !A[i][col];
		}
	}
};
```
