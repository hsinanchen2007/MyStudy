### 解题思路
简单的思路；假设N=5；

int t=m[0][4]   
m[0][4]=m[0][0]  
m[0][0]=m[4][0]  
m[4][0]=m[4][4]
m[4][4]=t

大概就是这样的规律，一层一层地遍历。注意一下遍历的开始和结束就好
### 代码

```cpp
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int N = matrix.size();
		if (N == 0) return;
		for (int i = N - 1; i >= N / 2; i--){
			for (int j = N - 1 - i; j < i; j++){
				int t = matrix[j][i];
				matrix[j][i] = matrix[N - 1 - i][j];
				matrix[N - 1 - i][j] = matrix[N - 1 - j][N - 1 - i];
				matrix[N - 1 - j][N - 1 - i] = matrix[i][N - 1 - j];
				matrix[i][N - 1 - j] = t;
			}
		}
	}
};
```