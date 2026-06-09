### 解题思路
这道题可谓是今年刷题卡我最久的一道题，思路很简单，dfs+hash.
但是这道题目卡了我很久，我一直不明白我，我看有人pass的代码和我思路几乎一模一样
除了我使用二维数组作为hash table，题解使用原本数组作为hash table
后来一步步排查终于发现，在于下面代码的注释部分，题解使用了if中多个||，而我把各种情况都调用函数，然后||起来
相对于我的方法，题解的方法就是剪枝，因为只要一个条件满足，就可以返回了！
题解链接https://leetcode-cn.com/problems/word-search/solution/hui-su-suan-fa-dai-ma-jian-ji-yi-dong-by-geekwade/

### 超时代码
```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0){
            return false;
        }
        vector<bool> tmp(board[0].size(), false);
        vector<vector<bool>> table(board.size(), tmp);
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    if(findStr(board, i, j, word, 0, table)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool findStr(vector<vector<char>>& board, int i, int j, string &word, int str_idx, vector<vector<bool>> &table){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[str_idx]){
            return false;
        }else{
            if(table[i][j]) return false;
            table[i][j] = true;
            str_idx++;
            if(str_idx >= word.size()) return true;
            bool l = findStr(board, i, j-1, word, str_idx, table); //error cause
            bool r = findStr(board, i, j+1, word, str_idx, table); //error cause
            bool u = findStr(board, i-1, j, word, str_idx, table); //error cause
            bool d = findStr(board, i+1, j, word, str_idx, table); //error cause
            table[i][j] = false;
            return l || r || u || d;
        }
    }
};
```

### PASS代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0){
            return false;
        }
        //cout << "size: " << board.size() << " " << board[0].size() << endl;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == word[0]){
                    if(findStr(board, i, j, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
private:
    bool findStr(vector<vector<char>>& board, int i, int j, string &word, int str_idx){
        //cout << i << " " << j << endl;
        if(board[i][j] != word[str_idx]){
            return false;
        }
        if(str_idx+1 >= word.size()){
            return true;
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        str_idx++;
        if((j > 0 && findStr(board, i, j-1, word, str_idx)) 
        || (j+1 < board[0].size() && findStr(board, i, j+1, word, str_idx))
        || (i > 0 && findStr(board, i-1, j, word, str_idx))
        || (i+1 < board.size() && findStr(board, i+1, j, word, str_idx))){
            return true;
        }
        board[i][j] = tmp;
        return false;
    }
};

```

### 结果
执行用时 : 24 ms , 在所有 C++ 提交中击败了 85.78% 的用户 
内存消耗 : 7.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户