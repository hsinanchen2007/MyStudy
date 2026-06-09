## 1. 额外空间直接遍历
时间`O(mn)`，空间`O(mn)`。  
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board);
        int m = board.size(), n = board[0].size();
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1)
                        live++;
                }
                if (board[i][j] == 1) {
                    if (live < 2)
                        ans[i][j] = 0;
                    else if (live == 2 || live == 3)
                        ans[i][j] = 1;
                    else if (live > 3)
                        ans[i][j] = 0;
                } else if (board[i][j] == 0 && live == 3)
                    ans[i][j] = 1;
            }
        }

        board = ans;
    }
};
```
  
## 2. Follow up
#### 1. Could you solve it in-place?  
由于要求同时修改，直接每次顺序遍历时修改`board[i][j]`会导致非同时修改，因为`board[i][j]`依赖的`board[i-1][j-1],board[i-1][j],board[i-1][j+1],board[i][j-1]`已经被修改了。  
就算是改成逆序遍历，`board[i][j]`右下角部分的元素也会提前修改了。  
既然不能通过调整遍历的顺序实现原地修改，那么考虑设置新的变量，储存额外的信息。  
可以想到，题目中的数据取值为01，而数据类型为`int`，因此我们可以考虑`board[i][j]`同时存储修改前和修改后的值。  
因此对状态重新编码，`xy`代表修改之后状态是`x`，之前状态是`y`。  
*本来是打算`x`代表修改之前的状态，`y`代表修改之后的状态，但这样每次要取之前的状态还要判断一下是取倒数第二位还是取最后一位，所以还是改为以上的编码方式。*  
由于`01, 00`是无法用int直接表示为十位数据的，因此可以考虑位运算，左侧高位为修改后状态，右侧低位为之前状态。  
```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] & 1)
                        live++;
                }
                if (board[i][j] & 1) {
                    if (live == 2 || live == 3) 
                        board[i][j] |= 2;
                } else {
                    if (live == 3)
                        board[i][j] |= 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};
```
  
#### 2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
数据总归是存在外存上的，如果不能一下全读到内存中，那么可以分块读入，通过上述编码的方式进行处理，同时保存之前和之后的状态，重新存储到外存上。  