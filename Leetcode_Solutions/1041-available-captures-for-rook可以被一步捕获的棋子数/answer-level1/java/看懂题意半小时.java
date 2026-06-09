### 解题思路
本体最难还是在于理解题意，感觉为了出一道算法题，得先学会好多东西。
总共分两步，一，找到车的位置，二，找到车走一次（上下左右）后的结果。
1. n^2时间复杂度找到车的坐标位置（x，y）。
2. 以该坐标为原点，分别从左右上下，找到所有符合的子结果。复杂度4n。
3. 判断条件为，遇到‘B’那么结束当前方向的寻找，遇到‘p’总结果+1，并结束当前方向的寻找。
4. 返回最终结果。时间复杂度O(n^2).
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        // 先找到车
        // 上下左右找
        // 遇到象时停止
        // 遇到p时值++，并停止
        // 返回结果
        int x = 0,y = 0;
        for (int i = 0; i < board.length; i++){
            for (int j = 0; j < board[i].length; j++){
                char str = board[i][j];
                if (str == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }   

        int res = 0;
        //向左
        for (int i = x; i > 0; i--){
            char str = board[i][y];
            if (str == 'B'){
                break;
            }else if (str == 'p'){
                res ++;
                break;
            }
        }
        // 向右
        for (int i = x; i < board.length; i++){
            char str = board[i][y];
            if (str == 'B'){
                break;
            }else if (str == 'p'){
                res ++;
                break;
            }
        }

        // 向上
        for (int j = y; j < board[x].length; j++){
            char str = board[x][j];
            if (str == 'B'){
                break;
            }else if (str == 'p'){
                res ++;
                break;
            }
        }

        // 向下

        for (int j = y; j > 0; j--){
            char str = board[x][j];
            if (str == 'B'){
                break;
            }else if (str == 'p'){
                res ++;
                break;
            }
        }

        return res;
    }
}
```