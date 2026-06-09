### 解题思路
直接四个方向模拟

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int ans = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    int curj = j + 1;
                    while(!(curj >= 8 || board[i][curj] == 'B')){
                        if(board[i][curj] == 'p'){
                            ans++;
                            break;
                        }else if(board[i][curj] == '.'){
                            curj++;
                        }
                    }
                    int decj = j - 1;
                    while(!(decj < 0 || board[i][decj] == 'B')){
                        if(board[i][decj] == 'p'){
                            ans++;
                            break;
                        }else if(board[i][decj] == '.'){
                            decj--;
                        }
                    }

                    int deci = i - 1;
                    while(!(deci < 0 || board[deci][j] == 'B')){
                        if(board[deci][j] == 'p'){
                            ans++;
                            break;
                        }else if(board[deci][j] == '.'){
                            deci--;
                        }
                    }

                    int curi = i + 1;
                    while(!(curi >= 8 || board[curi][j] == 'B')){
                        if(board[curi][j] == 'p'){
                            ans++;
                            break;
                        }else if(board[curi][j] == '.'){
                            curi++;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
}

```