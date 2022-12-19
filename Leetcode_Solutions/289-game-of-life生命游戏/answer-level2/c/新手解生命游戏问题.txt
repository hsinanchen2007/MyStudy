### 解题思路
1. 新建两个数组row和col，用来更新board这个二维矩阵，存的数据是下一时刻数值为一的行列位置
2. 在执行代码时通过了测试样例，在提交时报错说：variable length array bound evaluates to non-positive value 0（可变长度数组绑定的计算结果为非正值0），去解题思路里看了一下是若行或列为0的情况，return就可
3. num用来计数周围活细胞的数量
4. i为行，j为列，通过加减1判断周围的细胞是否在边界内，若在，则判断是否为活细胞，更新num
5. 当判断完周围细胞后，判断中心位置的细胞死活来对row和col数值进行更新
6. 用一个for循环将原二维矩阵全部归零
7. 用存在row和col数组里的数据对该二维矩阵进行更新

看了些别人的code，觉得自己的code里有很多可以简化的地方
1. 申请的数组空间过大
2. 在num更新时可以j直接加该位置的值，而不是先判断是否为活细胞

### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if ( !boardColSize[0] ||  !boardSize) {
        return ;
    }
    int row[ boardSize * (*boardColSize) ];//行
    int col[ boardSize * (*boardColSize) ];//列
    int amount = 0;//记录有多少个1
    for ( int i = 0 ; i < boardSize ; i++ ) {
        for ( int j = 0 ; j < (*boardColSize) ; j++ ) {
            int num = 0;
            if ( (i - 1) >= 0 && (j - 1) >= 0 ) {//1
                if ( board[i - 1][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (i - 1) >= 0 ) {//2
                if ( board[i - 1][j] == 1 ) {
                    num++;
                }
            }
            if ( (i - 1) >= 0 && (j + 1) < (*boardColSize) ) {//3
                if ( board[i - 1][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( (j - 1) >= 0 ) {//4
                if ( board[i][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (j + 1) < (*boardColSize) ) {//6
                if ( board[i][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize && (j - 1) >= 0 ) {//7
                if ( board[i + 1][j - 1] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize ) {//8
                if ( board[i + 1][j] == 1 ) {
                    num++;
                }
            }
            if ( (i + 1) < boardSize && (j + 1) < (*boardColSize) ) {//9
                if ( board[i + 1][j + 1] == 1 ) {
                    num++;
                }
            }
            if ( board[i][j] == 0 ) {
                if ( num == 3 ) {
                    row[amount] = i;
                    col[amount] = j;
                    amount++;
                }
            }
            if ( board[i][j] == 1 ) {
                if ( num >= 2 && num <= 3 ) {
                    row[amount] = i;
                    col[amount] = j;
                    amount++;
                }
            }
        }
    }
    for ( int k = 0 ; k < boardSize ; k++ ) {
        for ( int l = 0 ; l < (*boardColSize) ; l++ ) {
            board[k][l] = 0;
        }
    }

    for ( int m = 0 ; m < amount ; m++ ) {
        board[ row[m] ][ col[m] ] = 1;
    }
}
```