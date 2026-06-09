/*一样是回溯法，只不过这个题是二维平面的回溯，即四个方向的回溯和状态重置*/

    class Solution {
    public:
        // size代表当前已被找到的字母序号，f代表二维图各位置状态
        bool dfs (vector<vector<char>>& board, string& word,
                int size, int x, int y, vector<vector<int>>& f) {
            if (size == word.size()){
                return true;
            }

            //超边界或不相等(一致)
            if (x < 0 || x > board.size()-1 
            || y < 0 || y > board[0].size()-1 
            || board[x][y] != word[size]){
                return false;
            }

            //如果找到了一个匹配的，则二维图该位置置1
            if (f[x][y] == 0) {
                f[x][y] = 1;
                //上下左右四个方向进行搜索回溯，都不行才会判定当前选择的这个位置是错误的，置0，否则返回true
                if (dfs(board, word, size+1, x+1, y, f) 
                || dfs(board, word, size+1, x-1, y, f) 
                || dfs(board, word, size+1, x, y+1, f) 
                || dfs(board, word, size+1, x, y-1, f)){
                    return true;
                }
                f[x][y] = 0;
            }
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            if (board.empty() || word.empty()){
                return false;
            }
            int row = board.size(), col = board[0].size();
            vector<vector<int>> f(row, vector<int>(col, 0));
            for (int i = 0; i < row; i++){
                for (int j = 0; j < col; j++){
                    if (dfs(board, word, 0, i,j, f)){
                        return true;
                    }
                }
            }
            return false;
        }
    };

![image.png](https://pic.leetcode-cn.com/18fe5413081aaddcc9d300112df479f72b32e3e44506262eab262ce5e885dc0b-image.png)
