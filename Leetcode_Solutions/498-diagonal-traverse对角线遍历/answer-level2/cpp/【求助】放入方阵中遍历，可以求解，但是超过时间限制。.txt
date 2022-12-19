**超出时间限制怎么破？**

```


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
	int m = matrix.size() - 1;
	if (m == -1) {
		cout << "empty matrix!" << endl;
		return result;
	}
	int n = matrix[0].size() - 1;
	int i(0), j(0);
	int direction(0);
	int diagnal_num = m > n ? m : n;
	result.push_back(matrix[0][0]);
	for (int num = 1; num <= 2*diagnal_num+1; num++) {
		i = direction * num;
		j = (1 - direction) * num;
		for (int loops = 0; loops <= num; loops++) {
			if (i < 0 || i > m || j < 0 || j > n) {
				j += 2 * direction - 1;
				i += 1 - 2 * direction;
				continue;
			}
			else {
				result.push_back(matrix[i][j]);
				j += 2 * direction - 1;
				i += 1 - 2 * direction;
			}
		}
		direction = 1 - direction;
	}
	return result;
    }
};

```

思路就是把任意形状的矩阵放到2 * max<M,N> - 1的方阵中去搜索（左上角对齐），越过原来的界限的元素则continue。