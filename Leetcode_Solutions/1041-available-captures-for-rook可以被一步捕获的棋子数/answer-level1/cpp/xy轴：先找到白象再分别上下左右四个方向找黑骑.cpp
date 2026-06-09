### 解题思路
**将棋盘比作xy轴，遍历二维vector找到白象。找到白象后，分别找四个方向的黑骑。**
如果是向上找到了黑骑，就返回1，向上的方向不再继续找了，终止，返回1.
如果碰到了白象，也终止返回0。超出了边界也终止返回0。
**注意**
    查找的时候，以白象为中心点分别找出上下左右四个正方向上碰到的第一个黑骑数量。如果正方向上有2个黑骑，在碰到第一个黑骑就就会返回1，不再继续往前走的。

### 代码

```cpp
class Solution {
public:
int getRook(vector<vector<char>>& board, int i, int j,int dx,int dy)
{
    while (i > 0 && i < board.size() && j>0 && j < board[i].size()&&board[i][j]!='B')
    {
        //如果碰到了黑骑，那么返回1。
        if (board[i][j] == 'p')
        {
            return 1;
        }
        //一直往前移动。如果是dx=1，那么是一直向上走。
        i += dx;
        j += dy;
    }
    return 0;
   
}
int numRookCaptures(vector<vector<char>>& board) {
    //1.先遍历找到白象的位置,i代表x轴上的位置，j代表y轴上的位置。
    for (int i = 0; i < board.size(); i++) 
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                //累加上下左右方向获得的卒数量
                return getRook(board, i, j, 1, 0) + getRook(board, i, j, -1, 0) + getRook(board, i, j, 0, 1) + getRook(board, i, j, 0, -1);
            }
        }
    }
    return 0;
}
};
```
执行用时 :
    0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
    6 MB, 在所有 C++ 提交中击败了100.00%的用户