```
/**
*
*整体思路：
*1.总步数小于4，则未下完
*2.将A棋手的所有步数全部依次按顺序遍历，moves中，所有偶数数组为A的步数，判断胜利与否
*   满足胜利条件，直接返回true，否则进入3
*3.将B棋手的所有步数全部依次按顺序遍历，moves中，所有奇数数组为B的步数，判断胜利与否
*   满足胜利条件，直接返回true，否则进入4
*4.如果当前总步数小于9，未下完
*5.平局
*/

/**
*对角线判断：
*利用直角坐标系的斜率公式 k = ( y2 - y1 ) / ( x2 - x1 )
*如果两者相等，代表在同一对角线上
*
*/


/**
*Function: judging the player whether meet the conditions of win
*@param: int * a : one of the steps
*@param: int * b : one of the steps
*@param: int * c : one of the steps
*return: bool : true : win , false : fail
*/
bool checkWin( int * a , int * b , int * c ){

    //if three steps in the same row
    if( *( a + 0 ) == *( b + 0 ) && *( b + 0 ) == *( c + 0 ) ){

        return true;

    }

    //if three steps in the same column
    if( *( a + 1 ) == *( b + 1 ) && *( b + 1 ) == *( c + 1 ) ){

        return true;

    }

    //if three steps in the diagonal
    if( ( *( a + 0 ) - *( b + 0 ) ) != 0 && ( *( c + 0 ) - *( b + 0 ) ) != 0 ){

        int k = ( ( *( a + 1 ) - *( b + 1 ) ) / ( *( a + 0 ) - *( b + 0 ) ) );

        if( ( k == -1 || k == 1 ) && 
            k == ( ( *( c + 1 ) - *( b + 1 ) ) / ( *( c + 0 ) - *( b + 0 ) ) ) ){

            return true;

        }

    }

    return false;

}

char * tictactoe( int ** moves , int movesSize , int * movesColSize ){

    //if the length of array is less than 5, return Pending
    if( movesSize <= 4 ){

        return "Pending";

    }

    //juding all the steps which belong to A
    for( int i = 0 ; i < movesSize ; i += 2 ){

        for( int j = i + 2 ; j < movesSize ; j += 2 ){

            for( int k = j + 2 ; k < movesSize ; k += 2 ){

                if( checkWin( *( moves + i ) , *( moves + j ) , *( moves + k ) ) ){
                    
                    return "A";

                }

            }

        }

    }

    //juding all the steps which belong to B
    for( int i = 1 ; i < movesSize ; i += 2 ){

        for( int j = i + 2 ; j < movesSize ; j += 2 ){

            for( int k = j + 2 ; k < movesSize ; k += 2 ){

                if( checkWin( *( moves + i ) , *( moves + j ) , *( moves + k ) ) ){

                    return "B";

                }

            }

        }

    }

    //if the length of moves is less than 9, return Pending
    if( movesSize < 9 ){

        return "Pending";

    }

    return "Draw";

}
```
