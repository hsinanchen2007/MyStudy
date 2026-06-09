写了一个状态机，每次到边缘就切换状态。一共有四个状态，分别是往右走、往下走、往左走和往上走。
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row == 0) return res;
        int line = matrix[0].size();
        if (line == 0) return res;
        int left = 0, right = line - 1, up = 1, bottom = row - 1;
        int x = 0, y = 0;
        int state = 0;
        if (right == 0) state = 1;
        for (int i = 0; i < row * line; i++)
        {
            switch (state)
            {
                case (0):
                    res.push_back(matrix[x][y]);
                    y += 1;
                    if (y == right)
                    {
                        right -= 1;
                        state = 1;
                    }
                    break;
                case (1):
                    res.push_back(matrix[x][y]);
                    x += 1;
                    if (x == bottom)
                    {
                        bottom -= 1;
                        state = 2;
                    }
                    break;
                case (2):
                    res.push_back(matrix[x][y]);
                    y -= 1;
                    if (y == left)
                    {
                        left += 1;
                        state = 3;
                    }
                    break;
                case (3):
                    res.push_back(matrix[x][y]);
                    x -= 1;
                    if (x == up)
                    {
                        up += 1;
                        state = 0;
                    }
                    break;
            }
        }
        return res;
    }
};


```


