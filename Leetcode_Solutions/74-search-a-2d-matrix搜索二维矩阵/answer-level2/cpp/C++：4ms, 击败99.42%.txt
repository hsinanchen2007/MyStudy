### 解题思路
很明显，题目给出的数组是升序的，因此我们可以通过两个遍历解决此题。
第一次遍历，遍历每行首个数字以确认目标可能在哪行。
第二次遍历，遍历确认的行。

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();

        // 寻找target对应行
        int i;  // target对应行的下一行
        for(i = 0; i < m ; i++){
            if(matrix[i][0] > target)
               break;
        }
        --i;

        // matrix的第一个元素>target,target不可能在matrix中
        if(i < 0)
            return false;
        
        // 遍历确定的行，找到target则返回true
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == target)
                return true;
        }

        return false;
    }
};
```