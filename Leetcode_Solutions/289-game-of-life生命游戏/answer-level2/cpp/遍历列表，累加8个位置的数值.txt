### 解题思路
1.因为细胞状态都依赖之前的状态，因此要复制出来一个，作为原状态矩阵。
2.遍历矩阵，求每个元素的8个位置的活细胞数量，累加8个位置的活细胞数量即可。
3.要考虑8个位置的细胞不一定存在，所以做边界判断，存在的就累加。
4.在算下一个元素的时候，累加的活细胞数量要清0.

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp(board.size(), vector<int>(board[0].size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                temp[i][j] = board[i][j];
            }
        }
        int nums = 0; 
        for (int i = 0; i < temp.size(); i++) {

            for (int j = 0; j < temp[0].size(); j++) {
                nums = 0;
            //左上
                if (i - 1 >= 0 && j - 1 >= 0) {
                    nums += temp[i-1][j-1];
                }
            //上
                if (i - 1 >= 0) {
                    nums += temp[i-1][j];
                }
                //右上
                if (i - 1 >=0 && j + 1 < temp[0].size()) {
                    nums += temp[i - 1][j + 1];
                }
                //左
                if (j - 1 >= 0) {
                    nums += temp[i][j - 1];
                }
                //右
                if (j + 1 < temp[0].size()) {
                    nums += temp[i][j + 1];
                }
                //左下
                if (i + 1 <temp.size() && j - 1 >=0) {
                    nums += temp[i + 1][j - 1];
                }
                //下
                if (i + 1 < temp.size()) {
                    nums += temp[i+1][j];
                }
                //右下
                if (i + 1 < temp.size() && j + 1 < temp[0].size()) {
                    nums += temp[i + 1][j+1];
                }
                //规则4
                if (temp[i][j] == 0) {
                    board[i][j] = (nums == 3) ? 1 : 0;
                }
                else {
                    board[i][j] = (nums < 2 || nums>3) ? 0 : 1;
                }
            }
        }
    }
};
```
执行结果：
    通过 显示详情
执行用时 :
    0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
    7.2 MB, 在所有 C++ 提交中击败了100.00%的用户