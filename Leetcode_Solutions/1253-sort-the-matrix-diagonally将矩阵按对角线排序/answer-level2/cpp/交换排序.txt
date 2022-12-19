### 解题思路
用的是最直接的方法……交换排序。

### 代码

```cpp
class Solution {
public:
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
//	cout<<"first"<<endl;
	vector<vector<int>> rmat=mat;
	for (int i = 0; i < mat.size()-1; i++) {
		for(int k=i+1;k<mat.size();k++){
			for (int j = 0; j <mat[i].size()-1; j++) {
			if(j+k-i>=mat[i].size())break;	
			if(rmat[i][j]>rmat[k][j+k-i])swap(rmat[i][j],rmat[k][j+k-i]);
		}
		}
		
	}
	return rmat;
}
};
```