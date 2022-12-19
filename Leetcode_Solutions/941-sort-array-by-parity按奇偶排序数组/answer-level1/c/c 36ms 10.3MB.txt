```
/**
*
*整体思路：
*1.遍历数组，偶数直接存放在前列位置，奇数存放在缓冲区zhong
*2.将缓冲区数据继续排放在已排放的数组后面
*
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize){

    //used to save the number that is odd
    int * buffer = ( int * )malloc( sizeof( int ) * ASize );
    //the param of index is used to pointting the position of array,
    //and the param of len is used to count the length of buffer
    int index = 0 , len = 0;

    for( int i = 0 ; i < ASize ; i++ ){

        if( *( A +i ) % 2 == 0 ){

            //saving the number that is not odd in the array
            *( A + index++ ) = *( A + i );
            continue;

        }

        //saving the number that is odd in the buffer
        *( buffer + len++ ) = *( A + i );

    }

    //copying the elements in the buffer to the array
    for( int i = 0 ; i < len ; i++ ){

        *( A + index++ ) = *( buffer + i);

    }

    *returnSize = ASize;
    //free the buffer
    free( buffer );

    return A;

}
```
