### 解题思路
此处撰写解题思路
从右上角向左下角遍历
### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0 , j = col - 1;

        while(i<row&&j>=0){
            if(matrix[i][j]<target){
                i++;
            }else if(matrix[i][j]>target){
                j--;
            }else if(matrix[i][j] == target){
                return true;
            }
        }
        return false;
    } 
};
```