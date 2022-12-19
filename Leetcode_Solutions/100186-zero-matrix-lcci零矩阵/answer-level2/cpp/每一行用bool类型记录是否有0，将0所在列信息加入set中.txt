顺序扫描矩阵。
每扫描一行，每行用bool类型记录该行是否有0，并将该行所有0所在列的信息加入变量set中，每行扫描结束，就根据bool值决定是否将该行清零。
矩阵扫描结束后根据set中的变量把那些列清零。
```C++ []
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		unordered_set<int> s;
		for (int i = 0; i < matrix.size(); i++) {
			bool flag = false;
			for (int j = 0; j < matrix[0].size(); j++) {
				if (!flag && !matrix[i][j]) {
					s.insert(j);
					flag = true;
					continue;
				}
				else if (flag && !matrix[i][j])
					s.insert(j);			
			}
			if (flag)
				for (int k = 0; k < matrix[0].size(); k++)
					matrix[i][k] = 0;
		}
		for (auto j:s) {
			for (int k = 0; k < matrix.size(); k++)
				matrix[k][j] = 0;
		}
	}
};
```
