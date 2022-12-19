### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int row = 0;
        int col = matrix[0].size()-1;
        //本菜菜刚开始把while循环分开为两个，超出时间限制了2333
        while(row<matrix.size() && col>=0){
                if(matrix[row][col] < target){
                    row ++;
                }
                else if(matrix[row][col] > target){
                    col --;
                }
                else{
                    return true;
                }
        }
        return false;
    }
};
```