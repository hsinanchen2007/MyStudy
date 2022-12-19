### 解题思路
刷了几十道题，做题的思考速度和写java的效率明显都提高了。

我想这道题就是要找出R的位置，然后看R对应的行 列上有没有可以吃到的子。

另外，因为R只能走一步，所以四个方向上，只要某个方向吃到一个子就不能再走了。

因此，答案最大就是4。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {

        int len = 8, ans = 0;

        int row = 0, col = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(board[i][j] == ','){
                    continue;
                }
                else if(board[i][j] == 'R'){
                    row = i;
                    col = j;
                }
            }
        }

        char[] colLine = new char[8];

        for(int l = 0; l < len; l++){
            colLine[l] = board[l][col];
        }

        ans = countEnemy(board[row], col) + countEnemy(colLine, row);

        return ans;
    }

    private int countEnemy(char[] line, int index) {
        int temp = 0;
        for(int i = index - 1; i >= 0; i--){
            if(line[i] == 'p'){
                temp++;
                break;
            }else if(line[i] == 'B'){
                break;
            }
        }

        for(int j = index + 1; j < 8; j++){
            if(line[j] == 'p'){
                temp++;
                break;
            }else if(line[j] == 'B'){
                break;
            }

        }
        return temp;
    }
}
```