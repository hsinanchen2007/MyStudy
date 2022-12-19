```
/**
*
*整体思路：
*1.从1开始，不断遍历1-n/2之间的数字，利用函数返回是否存在某位为0的情况
*   如果不存在，则返回当前两个数，
*   如果存在，则进行下一次遍历
*
*/

/**
*Function: checking the parameter of num has bit is 0
*@param: int num : the number ready to be checked
*return: int : 1 : no bit is 0 , 0 : there have a bit is 0
*/
int checkBitZero( int num ){

    while( num > 0 ){

        if( num % 10 != 0 ){

            num /= 10;
            continue;

        }

        return 0;

    }

    return 1;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getNoZeroIntegers( int n , int * returnSize ){

    //alloclating memorise to save two that meet the conditions
    int * buffer = ( int * )malloc( sizeof( int ) * 2 );

    for( int i = 1 ; i <= ( n / 2 ) ; i++ ){

        if( checkBitZero( i ) == 1 && checkBitZero( n - i ) == 1 ){

            *( buffer + 0 ) = i;
            *( buffer + 1 ) = n - i;
            break;

        }

    }

    *returnSize = 2;

    return buffer;

}
```
