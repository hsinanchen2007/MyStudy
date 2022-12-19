## 思路一：直接遍历
### 代码
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

## 思路二：两次二分
第一次二分确定在哪一行，第二次二分确定在哪一列。
### 代码
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = row - 1, mid;
        //确定在哪一行
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (matrix[mid][0] == target || matrix[mid][col-1] == target) {
                return true;
            } else if (matrix[mid][col-1] < target) {
                i = mid + 1;
            } else if (matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                break;                
            }
        }
        //k保存已经确定的行号
        int k = mid;
        i = 0;
        j = col -1;        
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (matrix[k][mid] < target) {
                i = mid + 1;
            } else if (matrix[k][mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }        
        return false;
    }
};
```

## 思路三：转为一维数组再二分
### 代码
```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / col;
            int j = mid % col;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }            
        }
        return false;
    }
};
```



