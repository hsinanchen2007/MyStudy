```
/**
*
*整体思路：
*1.先遍历原数组计算总的偶数和，
*2.遍历queries数组，如果待更新的A元素是偶数，则和减去当前元素，更新完后，如果是偶数，则加上该元素
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * sumEvenAfterQueries(int * A , int ASize , int ** queries , int queriesSize , int * queriesColSize , int * returnSize){

    //alloclating memory to save the result of sum
    int * buffer = ( int * )malloc( sizeof( int ) * queriesSize );
    int sum = 0;
    *returnSize = queriesSize;

    //calculating the summarise of A array
    for( int i = 0 ; i < ASize ; i++ ){

        if( *( A + i ) % 2 == 0 ){

            sum += *( A + i );

        }

    }

    for( int i = 0 ; i < ASize ; i++ ){

        //if current elemet is an even number, delete it value
        if(  *( A + ( *( *( queries + i ) + 1 ) ) ) % 2 == 0 ){

            sum -= *( A + ( *( *( queries + i ) + 1 ) ) );

        }

        //updating current element
        *( A + ( *( *( queries + i ) + 1 ) ) ) += *( *( queries + i ) + 0 );

        if( *( A + ( *( *( queries + i ) + 1 ) ) ) % 2 == 0 ){

            sum += *( A + ( *( *( queries + i ) + 1 ) ) );

        }

        //saving sum in the buffer
        *( buffer + i ) = sum;

    }

    return buffer;

}
```
