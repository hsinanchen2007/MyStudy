以左下角为起点开始查找
1. 当前值小于target，则target在当前值右侧，j++
2. 当前值大于target，则target在当前值上侧，i--
3. 若相等，则返回true
4. 遍历结束没有找到，则返回false
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1 || matrix[0].size()<1) return false;
        int i = matrix.size()-1, j = 0; //左下角坐标(i,j)
        while(i>=0 && j<matrix[0].size()){
            if(target > matrix[i][j]) j++; //小于target，target在当前值右侧
            else if(target < matrix[i][j]) i--; //大于target，target在当前值上侧
            else return true; //找到目标，返回true
        }
        return false;
    }
};
```
