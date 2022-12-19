### 解题思路
踩到两个坑，记录一下：
1. 主函数部分，必须在循环内判断每次的返回值，只要有true，就返回。我一开始是等待循环完了在外面判断的，那样肯定不对；
2. dfs递归出口部分，要首先判断k是否已经满足要求了，然后再分析是否越界，还有当前值是否否和要求，顺序不能反；否则的
话有可能出现这样一种情况：我已经找到最后一个字符了，但是有可能此时是越界的，就当成错误情况判断了。

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //很明确，递归回溯
        int m = board.size();
        int n = board[0].size();
        //遍历每一个位置
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dfs(board, word, i, j, 0))   
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        //递归出口
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] != word[k])
            return false;

        //标记一下走过的路
        char temp = board[i][j];
        board[i][j] = 'o';
        bool flag = dfs(board, word, i+1, j, k+1) || dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j-1,k+1) || dfs(board, word, i, j+1, k+1);
        //回溯的时候要恢复原来的样子
        board[i][j] = temp;
        return flag;
    }
};
```