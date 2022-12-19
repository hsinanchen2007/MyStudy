### 解题思路
1、将指针指向第一行最后一个元素。
2、如果目标值小于指针指向的元素，则向左移动，右边的元素大于左边。
3、如果目标值大于指针指向的元素，则向下移动，上边的元素小于下边。
4、如果目标值与当前指针指向的元素相等，则返回true。
### 代码

```cpp
class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    
    int col = matrix[0].size() - 1;
    int row = 0;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] > target)
            col--;
        else if(matrix[row][col] < target)
            row++;
        else
            return true;
    }
    
    return false;
}
        
};
```