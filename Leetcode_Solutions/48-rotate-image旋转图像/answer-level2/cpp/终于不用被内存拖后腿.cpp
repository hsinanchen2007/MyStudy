### 解题思路
简单点，轮转，定好位置就行了

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
if (matrix.size() == 0) return;
	int n = matrix.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - i - 1; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - j - 1][i];
			matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
			matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
			matrix[j][n - i - 1] = tmp;
		}
	}
    }
};
```