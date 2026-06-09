![image.png](https://pic.leetcode-cn.com/dce6824e07bfcae7145c7a3e3de4aeff80c4928cbc2ad5ff94b3cd720e226baf-image.png)

### 解题思路
跟官方题解思路相同，就懒得写思路了。
[官方题解](https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/)

### 代码
与官方题解“方法二”思路相同的C++代码
```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        if (matrix[0].empty()) return 0;
        int result = 0;
        vector<vector<int>> count(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < count.size(); i++) {
            for (int j = 0; j < count[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    count[i][j] = 1 + (j == 0 ? 0 : count[i][j - 1]);
                    result = max(result, count[i][j]);
                    for (int ii = 1; ii <= i; ii++) {
                        if (count[i - ii][j] == 0) break;
                        count[i - ii][j] = min(count[i - ii][j], count[i][j]);
                        result = max(result, count[i - ii][j] * (ii + 1));
                    }
                }

            }
        }
        return result;
    }
};
```

官方题解 方法四 C++代码
```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<int> left(n, 0); // 将left初始化为最左
        vector<int> right(n, n); // 将left初始化为最右
        vector<int> height(n, 0);

        int maxarea = 0;

        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;

            // 更新height
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            // 更新left
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                }
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            // 更新right
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                }
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }

            // update the area
            for (int j = 0; j < n; j++)
                maxarea = max(maxarea, height[j] * (right[j] - left[j]));

        }
        return maxarea;
    }
};
```