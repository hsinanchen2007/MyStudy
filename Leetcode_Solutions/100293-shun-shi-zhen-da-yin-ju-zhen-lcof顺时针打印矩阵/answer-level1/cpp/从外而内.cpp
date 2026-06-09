### 解题思路
注意边界。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()<1) return result;
        int rows=matrix.size()-1;
        int columns=matrix[0].size()-1;
        int startRow=0,startColumn=0;
        while((startRow<=rows)&&(startColumn<=columns)){
            for(int i=startColumn;i<=columns; i++){
                result.push_back(matrix[startRow][i]);
                
            }
            if(startRow<rows){
                for(int j=startRow+1;j<=rows;j++){
                    result.push_back(matrix[j][columns]);
                }
            }
            if(startRow<rows&&startColumn<columns){
                for(int i=columns-1;i>=startColumn;i--){
                    result.push_back(matrix[rows][i]);
                }
            }
            if(startRow<rows-1&&startColumn<columns){
                for(int j=rows-1;j>startRow;j--){
                    result.push_back(matrix[j][startColumn]);
                }
            }
            startRow++;
            startColumn++;
            columns--;
            rows--;
        }
        return result;
    }
};
```