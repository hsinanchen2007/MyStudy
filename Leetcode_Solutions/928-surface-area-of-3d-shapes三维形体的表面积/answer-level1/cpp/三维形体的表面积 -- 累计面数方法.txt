### 解题思路
分几步走：
1.摞起来的柱体一共有多少面：1正方体 6个面，每多一个少正方体，柱体就少2个面，基础面数temp = num * 6 - (num - 1) * 2;
2.判断上下左右的遮挡：
（1）上：判断i - 1 > 0,遮住上面的柱体，面数少上面柱体的个数（grid[i][j] - grid[i - 1][j] > 0）；
        被上面柱体遮住（grid[i][j] - grid[i - 1][j] 《= 0） ，面数少本身柱体个数个；
（2）下、左、右同理
3.累计所有的中间结果的面数；
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
                if (grid.size() == 0) return 0;
        int count  = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int num = grid[i][j];
                int temp = 0;
                if (num > 0) {
                    temp = num * 6 - (num - 1) * 2;
                }
                if (i - 1 >= 0) {
                    if (grid[i][j] - grid[i - 1][j] > 0) {
                        temp -= grid[i - 1][j];
                    } else {
                        temp -= grid[i][j];
                    }
                }
                if (i + 1 < grid.size()) {
                    if (grid[i][j] - grid[i + 1][j] > 0) {
                        temp -= grid[i + 1][j];
                    } else {
                        temp -= grid[i][j];
                    }
                }
                if (j - 1 >= 0) {
                    if (grid[i][j] - grid[i][j - 1] > 0) {
                        temp -= grid[i][j - 1];
                    } else {
                        temp -= grid[i][j];
                    }
                }
                if (j + 1 < grid[0].size()) {
                    if (grid[i][j] - grid[i][j + 1] > 0) {
                        temp -= grid[i][j + 1];
                    } else {
                        temp -= grid[i][j];
                    }
                }
                count += temp;
            }
        }
        return count;
    }
};
```