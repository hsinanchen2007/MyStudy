### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/39ade91f5c0d8efefb5ca266cc786cb384f34b74e1b14fcaa6429689e2f834e1-image.png)

##### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        if(matrix[0].empty()){
            return false;
        }
        //determine row
        int row1 = 0;
        int row2 = matrix.size()-1;
        int colEnd = matrix[0].size()-1;
        int rowT = 0;
        while (row1 <= row2) {
            if (matrix[row2][0] < target){
                rowT = row2;
                break;
            }else if(matrix[row2][0] == target){
                return true;
            }else if(matrix[row2][0] > target) {
                row2--;
            }
            if (matrix[row1][colEnd] > target){
                rowT = row1;
                break;
            }else if(matrix[row1][colEnd] == target ){
                return true;
            }else if (matrix[row1][colEnd] < target){
                row1++;
            }
        }
        
        int col1 = 0;
        int col2 = matrix[0].size()-1;
        
        while (col1 <= col2) {
            if (matrix[rowT][col1] < target) {
                ++col1;
            }else if (matrix[rowT][col1] == target) {
                return true;
            }
            if (matrix[rowT][col2] > target) {
                --col2;
            }else if (matrix[rowT][col2] == target) {
                return true;
            }
            
        }
        return false;
    }
};
```