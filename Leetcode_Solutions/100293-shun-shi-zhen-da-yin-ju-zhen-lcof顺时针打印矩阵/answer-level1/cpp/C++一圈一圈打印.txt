```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
        {
            return res;
        }
        int column = matrix[0].size();
        int raw = matrix.size();

        int top = 0; // 每次从左到右的打印完成后top++，top的初始值为0
        int right = column - 1; // 每次从上到下的打印完成后right--，right的初始值为column-1
        int bottom = raw - 1; //每次从右到左的打印完成后bottom--，bottom的初始值为raw-1
        int left = 0; //每次从下到上的打印完成后left++，left的初始值为0

        while(top <= bottom && left <= right)
        {
            // 从左到右的打印
            for(int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            // 从上到下的打印
            for(int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            // 从右到左的打印
            for(int i = right; i >= left; i--)
            {
                if(top > bottom)
                    break;
                res.push_back(matrix[bottom][i]);
            }
            bottom--;

            // 从下到上的打印
            for(int i = bottom; i >= top; i--)
            {
                if(left > right)
                    break;
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
```
