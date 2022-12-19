### 解题思路
从某一具体例子实践中找到方法，首先选取第一行最后一个或者最后一行第一个与target进行对比，然后分情况讨论，i和j不断变化。
注意： 1循环结束条件，容易引起指针异常
      2 二维数组为空时的情况

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int i=0,j = matrix[0].size()-1;
        while(i<=matrix.size()-1 && j>=0){
            if(target == matrix[i][j]){
                return true;
            }
            else
            if(target < matrix[i][j]){
                j--;
            }
            else
            if(target > matrix[i][j]){
                i++;
            }
        }
        return false;
        
    }
};
```