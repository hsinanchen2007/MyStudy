# 73. 矩阵置零
**思路：**
利用两个set分别存放行列中出现0的坐标行、列。
遍历数组找出所有为0点的坐标行、列。
再将得到应该赋值为0的行列赋0。
```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	set<int> col_set;
    	set<int> row_set;
    	if(!matrix.empty()) {
    		for(int i = 0; i < matrix.size(); ++i){
    			for(int j = 0; j < matrix[0].size(); ++j){
    				if( matrix[i][j] == 0 ){
    					if(row_set.find(i)==row_set.end()) row_set.insert(i);
	    				if(col_set.find(j)==col_set.end()) col_set.insert(j);
					}
				}
			}
			
			for(int col : col_set){
				for(int i = 0; i < matrix.size(); ++i){
					matrix[i][col] = 0;
				}
			}
			
			for(int row : row_set){
				for(int i = 0; i < matrix[0].size(); ++i){
					matrix[row][i] = 0;
				}
			}
		}    
    }
};
```
