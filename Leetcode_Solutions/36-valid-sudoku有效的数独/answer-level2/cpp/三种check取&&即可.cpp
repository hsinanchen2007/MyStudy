### 解题思路
三种check取&&，这个算easy才对
columnValid(board) && rowValid(board) && groupValid(board)

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return columnValid(board) && rowValid(board) && groupValid(board); 
    }

    bool columnValid(vector<vector<char>>& board){
        int row_len = board[0].size(), col_len = board.size();
        for(int j = 0; j < col_len; ++j){
            unordered_map<char, int> m;
            for(int i = 0; i < row_len; ++i){
                if(board[i][j] != '.' && m[board[i][j]] == 0){
                    m[board[i][j]]++;
                }else if(board[i][j] != '.' && m[board[i][j]] > 0){
                    return false;
                }
            }          
        }
        return true;
    }
    bool rowValid(vector<vector<char>>& board){
        int row_len = board[0].size(), col_len = board.size();
        for(int i = 0; i < row_len; ++i){
            unordered_map<char, int> m;
            for(int j = 0; j < col_len; ++j){
                if(board[i][j] != '.' && m[board[i][j]] == 0){
                    m[board[i][j]]++;
                }else if(board[i][j] != '.' && m[board[i][j]] > 0){
                    return false;
                }
            }
        }
        return true;
    }
    bool groupValid(vector<vector<char>>& board){
        int row_len = board[0].size(), col_len = board.size(); 
        for(int i = 0; i < row_len; i+=3){    
            for(int j = 0; j < col_len; j+=3){
                if(!group_check(board, i, j)){
                    return false;
                }
            }
        }   
        return true;
    }

    bool group_check(vector<vector<char>>& board, int i, int j){
        unordered_map<char, int> m;
        for(int p = i; p < i+3; ++p){
            for(int q = j; q < j+3; ++q){
                if(board[p][q] != '.' && m[board[p][q]] == 0){
                    m[board[p][q]]++;
                }else if(board[p][q] != '.' && m[board[p][q]] > 0){
                    return false;
                }
            }
        }
        return true;
    }
};
```

### 结果
执行用时 : 28 ms , 在所有 C++ 提交中击败了 15.93% 的用户 
内存消耗 : 8.3 MB , 在所有 C++ 提交中击败了 100.00% 的用户