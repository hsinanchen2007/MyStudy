![1.png](https://pic.leetcode-cn.com/4a35c89b9ccaa3baa9f6980fb8f1d0c6736184ddfdfce7422af41c6ae1e44363-1.png)




borad数据说明：十位用于存放更新后的状态(0或1)，个位用于存放原始状态(0或1)

```
/**
*注1:
*   if( row > 0 && *( *( board + row - 1 ) + col ) % 10 == 1 ){
*   
*       count++;
*
*   }
*/


/**
*
*整体思路：
*1.第一次遍历矩阵时，将更新结果存入十位的位置，第二次遍历时，更新当前元素/=10
*2.第一次遍历时，计算八个位置含有1的个数，注意：
*   count += *( *( board + row - 1 ) + col ) % 10 之所以这么写，是为了省去判断当前操作元素的值，
*   这样写同样满足count值是受当前元素值(0或1)的影响，如上注1代码,一般写法
*3.这么多规则，其实只要两个判断条件即可。tmp==2，同样根据i行j列原本结果去更新当前细胞状态
*   tmp==3，复活死细胞就可以了
*4.第二次遍历，当前元素/=10，即可
*/

/**
*Functioon: calculating the number of 1 around current elment in board
*@param: int ** board : the board ready to be checked
*@param: int boardSize : the maximun of row
*@param: int ColSize : the maximun of col
*@param: int row : the row of current element
*@param: int row : the col of current element
*Return: int : the number of 1 around current element 
*/
int check( int ** board , int boardSize , int ColSize , int row , int col ){

    //the parameter of count used to save the number of 1 around current element
    int count = 0;

    //if current element is not in the first row
    if( row > 0 ){

        count += *( *( board + row - 1 ) + col ) % 10;

        //if current element is not in the first col
        if( col > 0 ){

            count += *( *( board + row - 1 ) + col - 1 ) % 10;

        }

    }

    //if current element is not in the first row
    if( col > 0 ){

        count += *( *( board + row ) + col - 1 ) % 10;

        //if current element is not in the last row
        if( row < boardSize - 1 ){

            count += *( *( board + row + 1 ) + col - 1 ) % 10;

        }

    }

    //if current element is not in the last row
    if( row < boardSize - 1 ){

        count += *( *( board + row + 1 ) + col ) % 10;

        //if current element is not in the last col
        if( col < ColSize - 1 ){

            count += *( *( board + row + 1 ) + col + 1 ) % 10;

        }

    }

    //if current element is not in the last col
    if( col < ColSize - 1 ){

        count += *( *( board + row ) + col + 1 ) % 10;

        //if current element is not in the first row
        if( row > 0 ){

            count += *( *( board + row - 1 ) + col + 1 ) % 10;

        }

    }

    return count;

}

void gameOfLife( int ** board , int boardSize , int * boardColSize ){

    //visiting board
    for( int i = 0 ; i < boardSize ; i++ ){

        for( int j = 0 ; j < *( boardColSize + i ) ; j++ ){

            int tmp = check( board , boardSize , *( boardColSize + i ) , i , j );

            //if the value of tmp is 3, updating the living status of current element
            if( tmp == 3 ){

                *( *( board + i ) + j ) += 10;

            }

            //if the value of tmp is 2, updating the living status of current element
            //according to the original value of it
            if( tmp == 2 ){

                *( *( board + i ) + j ) += *( *( board + i ) + j ) * 10;

            }

        }

    }

    //updaintg the elements in board
    for( int i = 0 ; i < boardSize ; i++ ){

        for( int j = 0 ; j < *( boardColSize + i ) ; j++ ){

            *( *( board + i ) + j ) /= 10;

        }

    }

}
```
