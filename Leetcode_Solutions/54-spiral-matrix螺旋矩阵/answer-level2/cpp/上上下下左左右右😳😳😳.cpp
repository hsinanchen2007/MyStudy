将矩阵当成一个牢笼，不断缩小上下左右边界遍历。
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int upper = 0, downer = matrix.size() - 1;  // 设置上下边界
        int left = 0, right = matrix[0].size() - 1; //设置左右边界
        while (upper <= downer && left <= right) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[upper][i]);
            }
            upper++;    //上边界往下一行
            if (upper > downer) {       //若此时条件不满足，则已遍历完成
                break;
            }
            for (int i = upper; i <= downer; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;    //右边界往左一列
            if (left > right) {     //若此时条件不满足，则已遍历完成
                break;
            }
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[downer][i]);
            }
            downer--;   //下边界往上一行
            for (int i = downer; i >= upper; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;     //左边界往右一列
        }
        
        return result;
    }
};
```