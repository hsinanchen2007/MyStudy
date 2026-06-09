```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 二维矩阵的二分查找
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int i = 0, j = n * m - 1;
        while (i < j) {
            int mid = (i + j) >> 1;
            int x = matrix[mid / m][mid % m];
            if (x < target) i = mid + 1;
            else j = mid;
        }
        return (matrix[j / m][j % m] == target);
    }
};
```
![image.png](https://pic.leetcode-cn.com/d4329b07620bd83297aff77c0334795002113b2b68d6167c8313f415704863bf-image.png)


