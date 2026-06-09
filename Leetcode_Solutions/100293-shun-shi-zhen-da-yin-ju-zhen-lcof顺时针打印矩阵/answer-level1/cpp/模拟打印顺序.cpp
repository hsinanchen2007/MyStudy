```C++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 打印顺序是左==>下==>右==>上
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true) {

            // 先往左
            for (int i = left; i <= right; ++i) 
                ans.push_back(matrix[top][i]);
            top++;
            if (top > bottom || left > right)
                break;

            // 往下
            for (int i = top; i <= bottom; ++i)
                ans.push_back(matrix[i][right]);
            right--;
            if (top > bottom || left > right)
                break;

            // 往左
            for (int i = right; i >= left; --i)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            if (top > bottom || left > right)
                break;

            // 最后往上
            for (int i = bottom; i >= top; --i)
                ans.push_back(matrix[i][left]);
            left++;
            if(top > bottom || left > right)
                break;
        }
        return ans;
    }
};
```