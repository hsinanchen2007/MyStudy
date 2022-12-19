现成的reverse方法反转数组，之后每个元素取反

代码：
```
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int length = A.size();
		for (int i = 0; i < length; i++) {
			reverse(A[i].begin(), A[i].end());
			for (int j = 0; j < length; j++)
				A[i][j] = !A[i][j];
		}
		return A;
	}
};
```
