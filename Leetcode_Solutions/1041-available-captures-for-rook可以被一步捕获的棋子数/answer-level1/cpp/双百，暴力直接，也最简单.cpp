### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.1 MB, 在所有 C++ 提交中击败了100.00%的用户

暴力，直接。
代码非常简单，不搞骚东西。

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int a,b;
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                if (board[i][j] == 'R') {
                    a = i;
                    b = j;
                }                
            }
        }
        int count = 0;
        for (int i = b - 1; i >= 0; i--){
            if (board[a][i] == 'B') {break;}
            if (board[a][i] == 'p'){
                count++;
                break;
            }
        }
        for (int i = b + 1; i < 8; i++){
            if (board[a][i] == 'B') {break;}
            if (board[a][i] == 'p'){
                count++;
                break;
            }
        }
        for (int i = a - 1; i >= 0; i--){
            if (board[i][b] == 'B') {break;}
            if (board[i][b] == 'p'){
                count++;
                break;
            }
        }
        for (int i = a + 1; i < 8; i++){
            if (board[i][b] == 'B') {break;}
            if (board[i][b] == 'p'){
                count++;
                break;
            }
        }
        return count;
    }
};
```