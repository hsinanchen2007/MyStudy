### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
bool haveSquare(vector<vector<int>>& matrix,int num,int row,int col) {
	for (int i = row; i <= row + num;i++) {
		if (matrix[i][col] == 1 || matrix[i][col + num] == 1)return false;
	}
	for (int i = col; i <= col + num;i++) {
		if (matrix[row][i] == 1 || matrix[row+num][i] == 1)return false;
	}
	return true;
}
vector<int> findSquare(vector<vector<int>>& matrix) {
	vector<int> output(3,0);
	if (matrix.empty())return output;
	for (int i = 0; i < matrix.size();i++) {
		int num = 0;
		for (int j = 0;j < matrix[0].size();j++) {
			if (output[2] == i + 1)break;//如果已经最大，跳出
			if (matrix[i][j] == 0) {
				if (++num >= i + 1)num = i + 1;//矩形最大不超过当前行数
				if (num > output[2]) {//如果可能存在更大的矩形
					for (int n = num;n >output[2];n--) {//遍历所有可能的尺寸
						//num -= 1;
						n -= 1;
						if(haveSquare(matrix,n,i-n,j-n)){//判断是否符合要求
							output[0]=i-n;
							output[1]=j-n;
							output[2]=n+1;
						}
						n += 1;
					}
				}
			}
			else {
				num = 0;
			}
		}
	}
	if (output[2] == 0)return{};
	return output;
}
};
```