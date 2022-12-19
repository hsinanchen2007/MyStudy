### 解题思路
矩阵二分搜索： 因为矩阵按Z字形是升序排列，可以使用二分搜索  时间复杂度O(log(M * N)) = O(logM + logN)

m x n 矩阵
一维索引index 转 二维坐标(row, col)
row = index / n   
col = index % n

### 代码

```cpp
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty())
            return false;

        int m = matrix.size();
        int n = matrix.at(0).size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            int mid_element = matrix.at(mid / n).at(mid % n);
            if (mid_element == target)
            {
                return true;
            }
            else if (target < mid_element)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};
```