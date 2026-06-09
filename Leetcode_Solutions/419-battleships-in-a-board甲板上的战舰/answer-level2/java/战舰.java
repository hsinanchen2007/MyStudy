### 解题思路
此处撰写解题思路

### 代码

```java
/**
从左至右从上至下一次扫描，判断当前未知是不是战舰的起点，判断条件：该位置为X且上面或者左边没有X。如果是战舰的起点，就加1；
否则因为是从上往下，从左往右遍历的，如果此时战舰的上边和左边也是战舰，那说明之前已经统计过了，直接跳过。
*/
class Solution {
    public int countBattleships(char[][] board) {
        if (board == null || board.length == 0) {
            return 0;
        }
        int m = board.length;
        int n = board[0].length;
        int res = 0;
        for  (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                /**思路1：此时是战舰，分情况判断上面和左边是不是空位，是就加1
                if (board[i][j] == 'X') {
                    if (i==0 && j ==0) {
                        res++;
                    } else if (i==0 && j>0 && board[i][j-1] == '.') {
                        res++;
                    } else if (i>0 && j==0 && board[i-1][j] == '.') {
                        res++;
                    } else if (i > 0 && j > 0 && board[i-1][j] == '.' && board[i][j-1] == '.') {
                        res++;
                    }  
                }*/

                //思路2：因为是从上往下，从左往右遍历的，如果此时战舰的上边和左边也是战舰，那说明之前已经统计过了，直接跳过; 否则加1
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X')  //上方是战舰，这艘船被计算过了，continue掉
                        continue;
                    if (j > 0 && board[i][j - 1] == 'X')  //左边是战舰，这艘船被计算过了，continue掉
                        continue;
                    res++;
                }   
                
            }
        }
        return res;
    }
}
```