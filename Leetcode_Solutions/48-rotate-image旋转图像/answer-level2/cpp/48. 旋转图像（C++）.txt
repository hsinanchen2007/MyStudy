# 48. 旋转图像（C++）
建立中间变量，移动后，再赋值回去
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int size = matrix.size();
        vector<vector<int>> rst = matrix;
        for( int i = 0; i < size; ++i ){
        	for( int j = 0; j < size; ++j ){
        		rst[j][size-1-i] = matrix[i][j];
       		}
        }
        matrix = rst;
        return;
    }
};
```

