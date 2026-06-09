### 每一行都可以用二分查找，可以先排除一些不用查找的行
```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int startRow = 0;
        for (; startRow < matrix.size(); startRow++) {
            if (target == matrix[startRow].back()) return true;
            if (target < matrix[startRow].back()) break;
        }
        
        // 如果任意一行都不符合
        if (startRow == matrix.size()) return false;
        
        int endRow = startRow + 1;
        for (; endRow < matrix.size(); endRow++) {
            if (target == matrix[endRow].front()) return true;
            if (target < matrix[endRow].front()) break;
        }

        // 在 startRow 到 endRow 的行进行查找
        for (int i = startRow; i < endRow; i++) {
            if (binarySearch(matrix[i], target)) return true;
        }
        return false;
    }
    
private:
    bool binarySearch(vector<int> &arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] == target) return true;
            else if (arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
```

### 从右上角元素开始比较，如果与目标值相等则返回，如果小于目标值则向下查找，如果大于目标值则向左查找，思想跟二叉查找树很像！
```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int l = 0, r = matrix[0].size() - 1;
        int t = 0, b = matrix.size() - 1;
        int x = r, y = t;
        while (l <= x && x <= r && t <= y && y <= b) {
            if (matrix[y][x] == target) return true;
            else if (matrix[y][x] < target) {
                y++;
            } else {
                x--;
            }
        }
        return false;
    }
};
```