store three arrays:
rows[row][num]
cols[col][num]
boxes[idx][num]

```
when meet a number in position (i,j), arrays will plus 1.
```
code 
```
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int rows[9][10] = {0} ;  // rows [row no.][1-9]
        int cols[9][10] = {0};  // cols [col no.][1-9]
        int boxes[9][10] = {0}; // boxes[index. ][1-9]

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                
                char num_c = board[i][j];
                if (num_c != '.'){
                    int num = num_c - '0';
                    int box_index = (i / 3) * 3 + j / 3; 
                    rows[i][num] += 1;
                    cols[j][num] += 1;
                    boxes[box_index][num] += 1;
                    
                    if (rows[i][num] > 1 || cols[j][num] > 1 || boxes[box_index][num] > 1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
        
};
```