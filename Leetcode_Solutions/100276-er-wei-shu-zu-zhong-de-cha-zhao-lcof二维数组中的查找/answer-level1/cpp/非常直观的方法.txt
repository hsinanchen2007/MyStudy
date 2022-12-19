思路：仔细观察数组可以发现，只要比上面的元素小，即可排除该列下面的所有元素，所以，先对第一行的元素进行比较。
从右边开始往左边比较。
比如说示例：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
要寻找5这个元素，先从右上角的15开始比较，然后是11，7，4，4比5小了，所有4下面可能有寻找的元素.
再比较4这一列，从上往下，5，找到了，返回。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        int row;
        int col;
        int i, j;
        if(matrix.size() == 0)
            return false;
        for(col = matrix[0].size() - 1; col >= 0; --col)
        {
            for(row = 0; row < matrix.size(); ++row)
            {
                if(target == matrix[row][col])
                    return true;
                if(target < matrix[row][col])
                    break;
            }
        }
        return false;
    }
};
```
