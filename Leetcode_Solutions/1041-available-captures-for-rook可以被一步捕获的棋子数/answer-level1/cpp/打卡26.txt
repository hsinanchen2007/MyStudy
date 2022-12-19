### 解题思路
  题目很简单，就是看白色的车只走一步能吃到几个黑色的卒。因此只要找到R的位置，就往四个方向找就行。找到黑色的卒，就加一结束了。如果遇到不是空格的就直接结束即可。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int s = 0;
        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                if(board[i][j] == 'R'){
                    int t = i + 1;
                    while(t < 8){
                        if(board[t][j] == 'p'){
                            s++;
                            break;
                        }
                        if(board[t][j] == '.')t++;
                        else break;
                    }
                    t = i - 1;
                    while(t >= 0){
                        if(board[t][j] == 'p'){
                            s++;
                            break;
                        }
                        if(board[t][j] == '.')t--;
                        else break;
                    }
                    t = j - 1;
                    while(t >= 0){
                        if(board[i][t] == 'p'){
                            s++;
                            break;
                        }
                        if(board[i][t] == '.')t--;
                        else break;
                    }
                    t = j + 1;
                    while(t < 8){
                        if(board[i][t] == 'p'){
                            s++;
                            break;
                        }
                        if(board[i][t] == '.')t++;
                        else break;
                    }
                    return s;
                }
            }
        }
        return s;
    }

};
```