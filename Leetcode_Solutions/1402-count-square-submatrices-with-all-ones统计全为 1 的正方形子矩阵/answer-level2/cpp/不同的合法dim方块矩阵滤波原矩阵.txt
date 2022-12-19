### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool FilterCore(const size_t& dim, const size_t& row_ini, const size_t& col_ini, vector<vector<int>>& matrix){
		for(size_t row_ind = row_ini; row_ind < row_ini + dim; ++row_ind){
			for(size_t col_ind = col_ini; col_ind < col_ini + dim; ++ col_ind){

				if(!matrix[row_ind][col_ind]) return false;
			}
		}
		return true;
	}
	int Filter(const size_t& dim, vector<vector<int>>& matrix){
		int num_valid_squares = 0;
		for(size_t row_ini = 0; row_ini <= matrix.size() - dim; ++row_ini){
			for(size_t col_ini = 0; col_ini <= matrix[0].size() - dim; ++col_ini){
				bool is_valid_square = FilterCore(dim, row_ini, col_ini, matrix);
				is_valid_square ? num_valid_squares++ : 0;
			}
		}
		return num_valid_squares;
	}
    int countSquares(vector<vector<int>>& matrix) {
    	int num_valid_squares = 0;
    	size_t max_dim = std::min(matrix.size(), matrix[0].size());
    	for(size_t dim = 1; dim <= max_dim; ++dim){
    		num_valid_squares += Filter(dim, matrix);
            //cout << "dim = " << dim << " valid_squ = " << Filter(dim, matrix) << endl;
    	}
    	return num_valid_squares;
    }
};
```