### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int length){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || length>=word.size() || word[length] != board[i][j]){
            return false;
        }
        if(length == word.size() - 1 && word[length] == board[i][j]){
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '0';
        bool flag = dfs(board,word,i,j+1,length+1) || dfs(board, word, i, j-1, length+1) || dfs(board, word, i+1, j, length+1) || dfs(board, word, i-1, j, length+1);
        board[i][j] = temp;
        return flag;
    }
};

//无向图的深度优先遍历
//首先利用暴力搜索找到word的第一个字符
//然后 利用深度优先遍历，去查找以第一个字符为起点的四周，递归，若最终返回flag为true 则说明存在路径
```