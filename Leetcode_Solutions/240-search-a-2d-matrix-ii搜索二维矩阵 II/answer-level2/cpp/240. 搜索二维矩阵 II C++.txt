### 解题思路


### 代码

```cpp
class Solution {
public:

    //方法1、 因为每行都是递增的， 按行进行二分查找
    //时间复杂度O(M * logN) M为行数，N为列数  空间复杂度O(1)
    int binary_search(vector<int>& v, int target)
    {
        int left = 0;
        int right = v.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(v.at(mid) == target)
                return mid;
            else if(target > v.at(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(int i = 0; i < matrix.size(); ++i)
        {
            if(binary_search(matrix.at(i), target) != -1)
                return true;
        }
        return false;
    }

    //方法2、与右上角顶点比较  如果没找到，则一次可以淘汰一行 或 一列
    //时间复杂度O(M + N) 空间复杂度O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty())
            return false;

        //右上角
        int row = 0;
        int col = matrix.at(0).size() - 1;

        //左下角
        int end_row = matrix.size() - 1;
        int end_col = 0;

        while (row <= end_row && col >= end_col)
        {
            if (matrix.at(row).at(col) == target)
            {
                return true;
            }
            else if(target < matrix.at(row).at(col)) //去左边部分找
            {
                --col;
            }
            else if (target > matrix.at(row).at(col)) //去下边部分找
            {
                ++row;
            }
        }
        
        return false;
    }
};
```