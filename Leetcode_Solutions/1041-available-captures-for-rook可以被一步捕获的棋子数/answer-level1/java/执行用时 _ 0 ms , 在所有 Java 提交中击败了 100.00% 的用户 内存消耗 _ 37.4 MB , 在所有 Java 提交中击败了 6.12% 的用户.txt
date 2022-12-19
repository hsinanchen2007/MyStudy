### 解题思路
这一题并不难，考验的是你的理解阅读能力，也没有什么算法可言，只要你理解了题目意思就是考察你的基本数组运算，这题的意思是：我们会找到一个‘R’，往上、下、左、右四个方向延伸，如果碰到‘B’，立刻停止，如果在碰到‘B’之前找到‘p’，我们会更新该次数并立刻停止该方向的延伸，转向其他方向，代码如下所示，四个for循环对应四种情况，易于理解，可以一看。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int count = 0;
        int hang = 0;
        int lie = 0;
        for(int i = 0;i<board.length;i++) {
            for(int j=0;j<board[0].length;j++) {
                if(board[i][j]=='R') {
                    hang = i;
                    lie = j;
                    break;
                }
            }
        }
        for(int i=hang;i>=0;i--) {
            if(board[i][lie]=='B') break;
            if(board[i][lie]=='p') {
                count++;
                break;
            }
        }
        for(int i = hang;i<board.length;i++) {
             if(board[i][lie]=='B') break;
             if(board[i][lie]=='p') {
                count++;
                break;
            }
        }
        for(int j = lie;j>=0;j--) {
            if(board[hang][j]=='B') break;
            if(board[hang][j]=='p') {
                count++;
                break;
            }
        }
        for(int j = lie;j<board[0].length;j++) {
            if(board[hang][j]=='B') break;
             if(board[hang][j]=='p') {
                count++;
                break;
            }
        }
        return count;


    }
}
```