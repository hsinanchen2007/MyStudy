### 解题思路
以矩阵的右上角作为起点，开始与target对比，若右上角值等于target返回true,若小于target，去除当前行，若大于target,去除当前列。

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)return false;
        int height=matrix.size()-1;
        int h=0;
        int width=matrix[0].size()-1;
        //选取右上角的数据（h=0,width=matrix[0].size()-1）与target进行对比
        while(h<=height&&width>=0){
            if(matrix[h][width]==target)return true;
            else if(matrix[h][width]<target)h++;
            else width--;
        }
        return false;
    }
};
```