### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cee1eb0036d017b75ddaec642213e619f169ca5727ad4799c9eb59d0f9a423b5-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        vector<int> res = {};
        vector<int> range1(matrix[0].size());
        vector<vector<int>> range = {};
        for (int i = 0; i < matrix.size(); i++) {
            range.emplace_back(range1);
        }
        int dx = 1;
        int dy = 0;
        int x = 0;
        int y = 0;
        while(x < matrix[0].size() && x >= 0 && range[y][x] != 1) {
            while(x < matrix[0].size() && x >= 0 && range[y][x] != 1) {
                res.emplace_back(matrix[y][x]);
                range[y][x] = 1;
                x += dx;
            }
            if(dx == 1) {
                dy = 1;
            }else if(dx == -1) {
                dy = -1;
            }
            x -= dx;
            dx = 0;
            y +=dy;
            while(y < matrix.size() && y >= 0 && range[y][x] != 1) {
                res.emplace_back(matrix[y][x]);
                range[y][x] = 1;
                y += dy;
            }
            if(dy == 1) {
                dx = -1;
            }else if(dy == -1) {
                dx = 1;
            }
            y -=dy;
            dy = 0;
            x +=dx;
        }
        return res;
    }
};
```