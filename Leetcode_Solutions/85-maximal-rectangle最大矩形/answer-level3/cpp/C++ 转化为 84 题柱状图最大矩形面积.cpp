### 解题思路
将第 i 行以上看作是一个柱状图，然后逐行进行求其矩形面积最大值

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        vector<vector<int>> hist(row, vector<int>(col, 0));

        // 计算柱状图每一列的值
        for (int i = 0; i < col; ++i) hist[0][i] = matrix[0][i] == '1' ? 1 : 0;

        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') hist[i][j] = hist[i-1][j] + 1;
            }
        }

        // 所有柱状图当中的最大值即为答案
        int maxArea = 0;
        for (int i = 0; i < row; ++i) {
            maxArea = max(maxArea, caculateHistMaxArea(hist[i]));
        }
        return maxArea;
    }

    int caculateHistMaxArea(vector<int>& hist) {
        stack<int> index;
        index.push(-1);
        int maxArea = 0;
        int len = hist.size();
        for (int i = 0; i < len; ++i) {
            while (index.top() != -1 && hist[index.top()] > hist[i]) {
                int h = hist[index.top()]; 
                index.pop();
                maxArea = max(maxArea, (i - index.top() - 1) * h);
            }
            index.push(i);
        }

        while (index.top() != -1) {
            int h = hist[index.top()]; 
            index.pop();
            maxArea = max(maxArea, (len - index.top() - 1) * h);
        }
        return maxArea;
    }
};
```