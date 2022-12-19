### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了83.68% 的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了5.07%的用户

### 代码

```cpp
class Solution {
public:
	template<typename T>
	void SwapForRotate(T& l, T& r){
		l = l^r;
		r = l^r;
		l = l^r;
	}
	void rotate(vector<vector<int>>& matrix) {
		//1) 以主对角线为轴，镜像
		for(size_t i=0;i<matrix.size();++i){
			for(size_t j=i+1;j<matrix[0].size();++j){
				SwapForRotate(matrix[i][j], matrix[j][i]);
			}
		}
		//2) 每一行反向
		for(size_t i=0;i<matrix.size();++i){
			for(size_t j=0;j<matrix[0].size()/2;++j){
				SwapForRotate(matrix[i][j], matrix[i][matrix[0].size()-1-j]);
			}
		}
    }
};
```