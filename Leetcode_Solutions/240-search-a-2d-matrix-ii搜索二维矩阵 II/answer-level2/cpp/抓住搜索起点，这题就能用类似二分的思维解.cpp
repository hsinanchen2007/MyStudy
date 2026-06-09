### 解题思路
从右上角开始（左下也可以），往左下角走，右上角那个元素往左元素递减，往下元素递增，一增一减大大降低了搜索的时间复杂度
targe大了，往下搜
target小了，往左搜

时间复杂度：O(n+m)，因为最差情况是从右上搜到左下角，自己脑补一下就知道了，很简单
空间复杂度：O(1)，因为这种方法只处理几个指针，所以它的内存占用是恒定的。
### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int row_bound = matrix.size();
        int col_bound = matrix[0].size();
        int row = 0;
        int col = col_bound - 1;
        while(row < row_bound && col >= 0) {
            if(target < matrix[row][col]) --col;
            else if(target > matrix[row][col]) ++row; 
            else return true;
        }
        return false;
    }
};
```