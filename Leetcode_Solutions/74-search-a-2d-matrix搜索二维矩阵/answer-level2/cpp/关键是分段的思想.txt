### 解题思路
这道题目将整个数值范围划分为[INT_MIN, matrix[0][0]), [matrix[0][0], matrix[0].end()], (matrix[0].end(), matrix.end().end()], (matrix.end().end(), INT_MAX)
1. 第一步是排除[INT_MIN, matrix[0][0])与(matrix.end().end(), INT_MAX)
2. 第二步判断是否在[matrix[0][0], matrix[0].end()]中，如果是，直接最简单的二分
3. 第三步是本题的关键，先利用matrix[0].end()与matrix.end().end()进行二分找寻行号，然后找到行了之后，在二分找target即可
- 3中的判断是，如果比matrix[i].end()大，那说明一定是在i之后的行；如果和matrix[i].end()一样大，那么就是第i行；如果比matrix[i].end()小，又比matrix[i-1].end()大，说明在第i行；如果比matrix[i].end()小，又比matrix[i-1].end()小，说明一定是在i之前的行.

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l_row = 0, r_row = matrix.size() - 1;
        int l_col = 0, r_col = matrix[0].size() - 1;
        if(target < matrix[l_row][l_col] || target > matrix[r_row][r_col]) return false;
        if(target <= matrix[l_row][r_col]){
            return findInRow(matrix[l_row], target);
        }else{
            int row = findInCol(matrix, target);
            //cout << row << " " << matrix[row][0] << endl;
            return findInRow(matrix[row], target);
        }
    }

    bool findInRow(vector<int> &A, int target){
        int l = 0, r = A.size()-1; 
        while(l <= r){
            int mid = (l+r)/2;
            if(A[mid] == target){
                return true;
            }else if(A[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }

    int findInCol(vector<vector<int>>& matrix, int target){
        int l = 0, r = matrix.size() - 1;
        int r_col = matrix[0].size() - 1;
        while(l < r){
            int mid = (l+r)/2;
            if(matrix[mid][r_col] < target){
                l = mid+1;
            }else if(matrix[mid][r_col] == target){
                return mid;
            }else{
                //matrix[mid][r_col] > target
                if(mid == 0 || matrix[mid-1][r_col] < target){
                    return mid;
                }else{
                    r = mid - 1;
                }
            }
        }
        return l;
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 87.21% 的用户 
内存消耗 : 7.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户