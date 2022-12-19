### 解题思路
思路来自剑指offer

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        //此处有一个[]样例，即传入一个空vector
        if(matrix.size() == 0) return false;
        
        int length = matrix[0].size(), width = matrix.size();
        int i = 0, j = length - 1;
        while(i < width && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
```