```
/**
*
*总体思路：
*1.根据原数组长度构建一个缓冲数组，并复制原数组
*2.利用快速排序对缓冲数组排序，
*3.对比原数组与缓冲数组，从而求得不满足的条件
*
*/

//quick sort the array
int cmp( const void * a , const void * b ){

    return *( int * )a - *( int * )b;

}

int heightChecker( int* heights, int heightsSize ){

    //used to count the number of the conditional element
    int count = 0 ;
    int * buffer = ( int * )malloc( sizeof( int ) * heightsSize );

    //copy the original array to the buffer
    for( int i = 0 ; i < heightsSize ; i++ ){

        *( buffer + i ) = *( heights + i );

    }

    //quick sort the array in the buffer
    qsort( buffer , heightsSize , sizeof( int ) , cmp );

    //coparing the original array to the array in the buffer
    for( int i = 0 ; i < heightsSize ; i++ ){

        if( *( buffer + i ) != *( heights + i ) ){

            count++;

        }

    }

    //free( buffer );

    return count;

}
```
