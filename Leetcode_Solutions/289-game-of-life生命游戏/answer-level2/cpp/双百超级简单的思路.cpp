### 解题思路
![WeChat16f5a199fdc78496ddf6e3e37ac7e79f.png](https://pic.leetcode-cn.com/9a0f2590819edbb86d489180f72e68f504f8e2da9af2062606fac4927e6934d8-WeChat16f5a199fdc78496ddf6e3e37ac7e79f.png)
双百简单思路，复杂度低于 O(m * n)
首先创建一个都为零的二阶数组arr，用来存放周围“1”的数量，然后开始遍历board，只需要在遇到“1”时，将周围的8个格子加1即可。
对于board[i][j]的值满足 arr[i][j]为3 或者 arr[i][j]为2且board[i][j]为1 时 设置为1即可，其他情况皆为0.



### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 创建复制数组 copyBoard
        int rows = board.size();
        int cols = board[0].size();

        // 创建复制数组 copyBoard
        vector<vector<int>> arr(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            cols = board[i].size();
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 1) {
                    for (int m = -1; m < 2; m++) {
                        for (int n = -1; n < 2; n++) {
                            if (m == 0 && n == 0) {
                                continue;
                            }
                            if (i + m < 0 || j + n < 0) {
                                continue;
                            }
                            if (i + m >= rows || j + n >= cols) {
                                continue;
                            }
                            arr[i + m][j + n]++;
                            
                        }
                    }
                }
            }
        }

        for (int i = 0; i< rows; i++) {
            cols = board[i].size();
            for (int j = 0; j < cols; j++) {
                // board[i][j] = arr[i][j];
                board[i][j] = (arr[i][j] == 3 || (arr[i][j] == 2 && board[i][j] == 1)) ? 1 : 0;
            }
        }
    }
};
```