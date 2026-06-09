### 解题思路

无非就是遍历，然后写到新的数据里，然后复制到旧的里面。

先得到数组的规格，先后遍历，计算当前位置的周围的合：

计算合的函数，就是遍历以当前位置为中心的九个格子，用-1到1的双层循环表示当前位置需要改变的数值。
筛选条件：
1.如果都为0，是当前位置，跳过；
2.如果行超界，则跳出当前的列循环，因为单次循环行不变，本次列循环也就没有必要了；
3.如果列越界，则跳过；
把符合条件的值加起来，即周边存活细胞的个数。

然后根据合判断即可。

判断条件如下：
1.如果活细胞（1）周围的合小于2或者大于3，则死（0）；
2.如果死细胞（0）周围的合不等于3，则继续死（0）；


### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        // 判断数组
        if(board == null){
            return;
        }
        int len = board.length;
        if (len == 0){
            return;
        }
        int wid = board[0].length;
        if (wid == 0){
            return;
        }
        int newBoard[][] = new int[len][wid];
        // 遍历
        for(int i = 0; i < len; i++){
            for(int j = 0; j < wid; j++){
                int alive = board[i][j];
                if(alive == 1){
                    // 当前存活条件下的判断
                    int flag = aroundSum(i, j, board, len, wid);
                    if (flag < 2 || flag > 3) {
                        alive = 0;
                    }
                    newBoard[i][j] = alive;
                    continue;
                }
                // 当前死亡条件下的判断
                int flag = aroundSum(i, j, board, len, wid);
                if (flag == 3){
                    alive = 1;
                }
                newBoard[i][j] = alive;
            }
        }
        // 新结果复制
        for(int i = 0; i < len; i++){
            for(int j = 0; j < wid; j++){
                board[i][j] = newBoard[i][j];
            }
        }
    }

    private static int aroundSum(int i, int j, int[][] boardtmp, int len, int wid){
        int flag = 0;
        // 遍历九个格子
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                // 为中心点，跳过
                if(x == 0 && y == 0){
                    continue;
                }
                int ni = i + x;
                // 行越界，终止内循环
                if(ni < 0 || ni >= len){
                    break;
                }
                // 列越界，跳过
                int nj = j + y;
                if(nj < 0 || nj >= wid){
                    continue;
                }
                // 加当前值
                flag += boardtmp[ni][nj];
            }
        }
        return flag;
    }
}
```