### 解题思路
回溯法，匹配到单词的第一个字符就启动回溯函数。每次先把访问过的字符设置为空，再匹配下一个字符。如果所有字符都被匹配到则返回true，否则把访问过的字符恢复原值。

![1.png](https://pic.leetcode-cn.com/5a94ded7d83e7a017a701ced1c7a7f8eb7fa363727dc44f559b211aa18bec46c-1.png)


### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int height = board.size(), width = 0;
        if (height > 0) {
            width = board[0].size();
        }
        if (height == 0 || width == 0) {
            return false;
        }

        if (word.size() == 0) {
            return false;
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                char c = board[i][j];

                if (c == word[0] && find_word(board, i, j, word, 1, height, width)) { //匹配到开头，启动查找
                    return true;
                }
            }
        }

        return false;
    }

private:
    //回溯法，查找单词的下一个字符，注意先把访问过的字符清空
    bool find_word(vector<vector<char>>& board, int i, int j, string &word, int pos, int height, int width) {
        if (pos >= word.size()) {
            return true;
        }

        char tmp = board[i][j];
        board[i][j] = '\0';

        if ((i > 0 && board[i-1][j] == word[pos]) 
            && (find_word(board, i-1, j, word, pos+1, height, width))) {
            return true;
        }
        if ((i < height-1 && board[i+1][j] == word[pos])
            && (find_word(board, i+1, j, word, pos+1, height, width))) {
            return true;
        }
        if ((j > 0 && board[i][j-1] == word[pos])
            && (find_word(board, i, j-1, word, pos+1, height, width))) {
            return true;
        }
        if ((j < width-1 && board[i][j+1] == word[pos])
            && (find_word(board, i, j+1, word, pos+1, height, width))) {
            return true;
        }

        board[i][j] = tmp;
        return false;
    }
};
```