### 解题思路
1.二分查找
2.两端遍历


1.二分查找
每行二分查找
### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        for (const auto &m : matrix) {
            if (binary_search(m.begin(), m.end(), target)) {
                return true;
            }
        }
        return false;
    }
};
```

2.两端遍历
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()|| matrix[0].empty()){
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();


        if(target<matrix[0][0]){
            return false;
        }
        

        for(int i = 0;i<row;i++){

            if(target == matrix[i][0] || target == matrix[i][col-1]){
                return true;
            }

            if(target>matrix[i][0] && target>matrix[i][col-1]){
                continue;
            }else if(target>matrix[i][0] && target<matrix[i][col-1]){
                vector<int> nums = matrix[i];
                if(find(nums.begin(),nums.end(),target)!= nums.end()){
                    return true;
                }else{
                    return false;
                }        

            }else if(i>= 1 && target< matrix[i][0] && target> matrix[i-1][col-1]){    
                return false;
            }
     
        }

        return false;

    }
};
```
