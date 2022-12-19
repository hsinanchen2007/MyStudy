### 解题思路
构造二位数组height，保存matrix数组中相应位置的上连续"1"的数目（高度）
对height的每一行使用单调栈求解最大面积
题目解法同  84. 柱状图中最大的矩形

### 代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = i > 0 ? heights[i-1][j] + 1 : 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }
        stack<int> sh;
        stack<int> sl;
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[i].size(); ++j) {
                int h = heights[i][j];
                int cur_len = 0;
                while (!sh.empty() && h < sh.top()) {
                    int tmp_h = sh.top();
                    cur_len += sl.top();
                    sh.pop();
                    sl.pop();
                    result = max(result, cur_len * tmp_h);
                }
                if (h) {
                    sh.push(h);
                    sl.push(cur_len + 1);
                }
            }
            int cur_len = 0;
            while (!sh.empty()) {
                int tmp_h = sh.top();
                cur_len += sl.top();
                sh.pop();
                sl.pop();
                result = max(result, cur_len * tmp_h);
            }
        }
        return result;
    }
};
```