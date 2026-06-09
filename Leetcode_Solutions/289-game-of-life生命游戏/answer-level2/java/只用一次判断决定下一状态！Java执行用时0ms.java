- 时间复杂度：O(mn)，其中 m，n 分别为 board 的行数和列数。
- 空间复杂度：O(1)，除原数组外只需要常数的空间存放若干变量。

**思路**
1. 用+2来mark下一状态为活细胞，如下一状态为死细胞则不操作(其实就是位运算啦)。因此board[i][j]凡是%2=1， 则初始状态为活细胞，%2=0，则初始状态为死细胞，/2=1，则下一状态为活细胞，/2=0，则下一状态为死细胞。
2. 找到了一个trick，来根据自身初始状态和周围活细胞的数量来判断下一状态。
即通过把自身初始状态（1or0）与周围活细胞数（0-8）进行相加或相乘操作，看会不会等于3.
如果原先活，需要周围=2or3才能活 -> 1 + 2 = 3， 1 * 3 = 3
如果原先死，需要周围=3才能活    -> 0 + 3 = 3
除此之外的情况，无论相加还是相乘都不能得到3的结果，因此用一个if判断就可以得到下一状态

1   +   2   = 3  =>  1
1   *   3   = 3  =>  1
1  +/*  X  != 3  =>  0
0   +   3   = 3  =>  1
0  +/*  X  != 3  =>  0

所以一个双层forloop得到所有下一状态，在用一个双层forloop把下一状态都更新到当前（通过/= 2）-> 时间复杂度O(mn)
申请的变量是常数个 -> 空间复杂度O(1)

以下是代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length, n = board[0].length;
        int start_x, end_x, start_y, end_y, alives;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                alives = 0; //record the #of live cells around.

                start_x = i > 0 ? i - 1 : 0;
                end_x = i < m - 1 ? i + 2 : m;
                start_y = j > 0 ? j - 1 : 0;
                end_y = j < n - 1 ? j + 2 : n;
                
                for(int x = start_x; x < end_x; x++){
                    for(int y = start_y; y < end_y; y++){
                        if((x == i) && (y == j)) continue;
                        alives += board[x][y] % 2;
                    }
                }

                if(board[i][j] % 2 + alives == 3 || board[i][j] % 2 * alives == 3){
                    board[i][j] += 2;
                }
            }

        }
        //Get all new state and then update
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] /= 2;
            }
        }

    }
}
```


