### 解题思路

![image.png](https://pic.leetcode-cn.com/7b66fd6bc966f8cfc6ecb0a7a4b324a2d680ec33080e3e462a727ba55190030a-image.png)

我真是写得乱七八糟。争取改

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int times = matrix.size() / 2;
        for (int i = 0; i < times; ++i) {
            int lang = matrix.size() - 1 - 2 * i;
            for (int j = 0; j < lang; ++j) {
                int x1 = i;
                int y1 = i + j;
                int x2 = y1;
                int y2 = matrix.size() - 1 - i;
                int x3 = y2;
                int y3 = matrix.size() - 1 - y1;
                int x4 = y3;
                int y4 = x1;


                int tmp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = tmp;
            }
        }
    }
};
```